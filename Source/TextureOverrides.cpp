// Copyright (c) 2020-2021 Sultim Tsyrendashiev
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "TextureOverrides.h"

#include <filesystem>

#include "Const.h"
#include "ImageLoader.h"

using namespace RTGL1;

namespace
{
    VkFormat ToUnorm(VkFormat f)
    {
        switch (f)
        {
            case VK_FORMAT_R8_SRGB: return VK_FORMAT_R8_UNORM;
            case VK_FORMAT_R8G8_SRGB: return VK_FORMAT_R8G8_UNORM;
            case VK_FORMAT_R8G8B8_SRGB: return VK_FORMAT_R8G8B8_UNORM;
            case VK_FORMAT_B8G8R8_SRGB: return VK_FORMAT_B8G8R8_UNORM;
            case VK_FORMAT_R8G8B8A8_SRGB: return VK_FORMAT_R8G8B8A8_UNORM;
            case VK_FORMAT_B8G8R8A8_SRGB: return VK_FORMAT_B8G8R8A8_UNORM;
            case VK_FORMAT_A8B8G8R8_SRGB_PACK32: return VK_FORMAT_A8B8G8R8_UNORM_PACK32;
            case VK_FORMAT_BC1_RGB_SRGB_BLOCK: return VK_FORMAT_BC1_RGB_UNORM_BLOCK;
            case VK_FORMAT_BC1_RGBA_SRGB_BLOCK: return VK_FORMAT_BC1_RGBA_UNORM_BLOCK;
            case VK_FORMAT_BC2_SRGB_BLOCK: return VK_FORMAT_BC2_UNORM_BLOCK;
            case VK_FORMAT_BC3_SRGB_BLOCK: return VK_FORMAT_BC3_UNORM_BLOCK;
            case VK_FORMAT_BC7_SRGB_BLOCK: return VK_FORMAT_BC7_UNORM_BLOCK;
            default: return f;
        }
    }

    VkFormat ToSRGB(VkFormat f)
    {
        switch (f)
        {
            case VK_FORMAT_R8_UNORM: return VK_FORMAT_R8_SRGB;
            case VK_FORMAT_R8G8_UNORM: return VK_FORMAT_R8G8_SRGB;
            case VK_FORMAT_R8G8B8_UNORM: return VK_FORMAT_R8G8B8_SRGB;
            case VK_FORMAT_B8G8R8_UNORM: return VK_FORMAT_B8G8R8_SRGB;
            case VK_FORMAT_R8G8B8A8_UNORM: return VK_FORMAT_R8G8B8A8_SRGB;
            case VK_FORMAT_B8G8R8A8_UNORM: return VK_FORMAT_B8G8R8A8_SRGB;
            case VK_FORMAT_A8B8G8R8_UNORM_PACK32: return VK_FORMAT_A8B8G8R8_SRGB_PACK32;
            case VK_FORMAT_BC1_RGB_UNORM_BLOCK: return VK_FORMAT_BC1_RGB_SRGB_BLOCK;
            case VK_FORMAT_BC1_RGBA_UNORM_BLOCK: return VK_FORMAT_BC1_RGBA_SRGB_BLOCK;
            case VK_FORMAT_BC2_UNORM_BLOCK: return VK_FORMAT_BC2_SRGB_BLOCK;
            case VK_FORMAT_BC3_UNORM_BLOCK: return VK_FORMAT_BC3_SRGB_BLOCK;
            case VK_FORMAT_BC7_UNORM_BLOCK: return VK_FORMAT_BC7_SRGB_BLOCK;
            default: return f;
        }
    }

    template<uint32_t N>
    void SafeCopy(char (&dst)[N], const char *src)
    {
        memset(dst, 0, N);

        if (src != nullptr)
        {
            for (uint32_t i = 0; i < N - 1; i++)
            {
                if (src[i] == '\0')
                {
                    break;
                }

                dst[i] = src[i];
            }
        }
    }

    auto Loader_Load(TextureOverrides::Loader loader, const std::filesystem::path &filepath)
    {
        if (std::holds_alternative<ImageLoaderDev *>(loader))
        {
            return std::get<ImageLoaderDev *>(loader)->Load(filepath);
        }
        else
        {
            return std::get<ImageLoader *>(loader)->Load(filepath);
        }
    }

    void Loader_FreeLoaded(TextureOverrides::Loader loader)
    {
        if (std::holds_alternative<ImageLoaderDev *>(loader))
        {
            std::get<ImageLoaderDev *>(loader)->FreeLoaded();
        }
        else
        {
            std::get<ImageLoader *>(loader)->FreeLoaded();
        }
    }

    constexpr const char *Loader_GetExtension(TextureOverrides::Loader loader)
    {
        if (std::holds_alternative<ImageLoaderDev *>(loader))
        {
            return ".png";
        }
        else
        {
            return ".ktx2";
        }
    }

    std::optional<std::filesystem::path> GetTexturePath(const char *commonFolderPath, const char *relativePath, const char *postfix, const char *extension)
    {
        if (relativePath == nullptr)
        {
            return std::nullopt;
        }

        return std::filesystem::path(commonFolderPath)
            .append(relativePath)
            .replace_extension("").concat(postfix)
            .replace_extension(extension);
    }
}

TextureOverrides::TextureOverrides(
    const char *_relativePath,
    const RgTextureSet &_defaultTextures,
    const RgExtent2D &_defaultSize,
    const OverrideInfo &_overrideInfo,
    Loader _loader
)
    : loader(_loader)
    , results{}
    , debugname{}
{
    SafeCopy(debugname, _relativePath);

    const void *defaultData[TEXTURES_PER_MATERIAL_COUNT] =
    {
        _defaultTextures.pDataAlbedoAlpha,
        _defaultTextures.pDataRoughnessMetallicEmission,
        _defaultTextures.pDataNormal,
    };

    constexpr VkFormat defaultSRGBFormat = VK_FORMAT_R8G8B8A8_SRGB;
    constexpr VkFormat defaultLinearFormat = VK_FORMAT_R8G8B8A8_UNORM;
    constexpr uint32_t defaultBytesPerPixel = 4;


    if (!_overrideInfo.disableOverride)
    {
        for (uint32_t i = 0; i < TEXTURES_PER_MATERIAL_COUNT; i++)
        {
            // TODO: try to load with different loaders with their own extensions
            if (auto path = GetTexturePath(_overrideInfo.texturesPath, _relativePath, _overrideInfo.postfixes[i], Loader_GetExtension(loader)))
            {
                results[i] = Loader_Load(loader, path.value());
                
                if (results[i])
                {
                    results[i]->format =
                        _overrideInfo.overridenIsSRGB[i] ? ToSRGB(results[i]->format) : ToUnorm(results[i]->format);
                }
            }
        }
    }


    const uint32_t defaultDataSize = defaultBytesPerPixel * _defaultSize.width * _defaultSize.height;

    for (uint32_t i = 0; i < TEXTURES_PER_MATERIAL_COUNT; i++)
    {
        // if file wasn't found, use default data instead
        if ( !results[i] && defaultData[i] )
        {
            results[i] = ImageLoader::ResultInfo
            {
                .levelOffsets = {0},
                .levelSizes = {defaultDataSize},
                .levelCount = 1,
                .isPregenerated = false,
                .pData = static_cast<const uint8_t *>(defaultData[i]) ,
                .dataSize = defaultDataSize,
                .baseSize = _defaultSize,
                .format = _overrideInfo.originalIsSRGB[i] ? defaultSRGBFormat : defaultLinearFormat,
            };
        }
    }
}

TextureOverrides::~TextureOverrides()
{
    Loader_FreeLoaded(loader);
}

const std::optional<ImageLoader::ResultInfo> &RTGL1::TextureOverrides::GetResult(uint32_t index) const
{
    assert(index < TEXTURES_PER_MATERIAL_COUNT);
    return results[index];
}

const char *RTGL1::TextureOverrides::GetDebugName() const
{
    return debugname;
}
