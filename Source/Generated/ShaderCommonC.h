// This file was generated by GenerateShaderCommon.py

#pragma once

namespace RTGL1
{

#include <stdint.h>

#define MAX_STATIC_VERTEX_COUNT (1048576)
#define MAX_DYNAMIC_VERTEX_COUNT (2097152)
#define MAX_INDEXED_PRIMITIVE_COUNT (1048576)
#define MAX_BOTTOM_LEVEL_GEOMETRIES_COUNT (4096)
#define MAX_BOTTOM_LEVEL_GEOMETRIES_COUNT_POW (12)
#define MAX_GEOMETRY_PRIMITIVE_COUNT (1048576)
#define MAX_GEOMETRY_PRIMITIVE_COUNT_POW (20)
#define LOWER_BOTTOM_LEVEL_GEOMETRIES_COUNT (256)
#define MAX_TOP_LEVEL_INSTANCE_COUNT (45)
#define BINDING_VERTEX_BUFFER_STATIC (0)
#define BINDING_VERTEX_BUFFER_DYNAMIC (1)
#define BINDING_INDEX_BUFFER_STATIC (2)
#define BINDING_INDEX_BUFFER_DYNAMIC (3)
#define BINDING_GEOMETRY_INSTANCES (4)
#define BINDING_GEOMETRY_INSTANCES_MATCH_PREV (5)
#define BINDING_PREV_POSITIONS_BUFFER_DYNAMIC (6)
#define BINDING_PREV_INDEX_BUFFER_DYNAMIC (7)
#define BINDING_STATIC_TEXCOORD_LAYER_1 (8)
#define BINDING_STATIC_TEXCOORD_LAYER_2 (9)
#define BINDING_STATIC_TEXCOORD_LAYER_3 (10)
#define BINDING_DYNAMIC_TEXCOORD_LAYER_1 (11)
#define BINDING_DYNAMIC_TEXCOORD_LAYER_2 (12)
#define BINDING_DYNAMIC_TEXCOORD_LAYER_3 (13)
#define BINDING_GLOBAL_UNIFORM (0)
#define BINDING_ACCELERATION_STRUCTURE_MAIN (0)
#define BINDING_TEXTURES (0)
#define BINDING_CUBEMAPS (0)
#define BINDING_RENDER_CUBEMAP (0)
#define BINDING_BLUE_NOISE (0)
#define BINDING_LUM_HISTOGRAM (0)
#define BINDING_LIGHT_SOURCES (0)
#define BINDING_LIGHT_SOURCES_PREV (1)
#define BINDING_LIGHT_SOURCES_INDEX_PREV_TO_CUR (2)
#define BINDING_LIGHT_SOURCES_INDEX_CUR_TO_PREV (3)
#define BINDING_INITIAL_LIGHTS_GRID (4)
#define BINDING_INITIAL_LIGHTS_GRID_PREV (5)
#define BINDING_LENS_FLARES_CULLING_INPUT (0)
#define BINDING_LENS_FLARES_DRAW_CMDS (1)
#define BINDING_DRAW_LENS_FLARES_INSTANCES (0)
#define BINDING_DECAL_INSTANCES (0)
#define BINDING_PORTAL_INSTANCES (0)
#define BINDING_LPM_PARAMS (0)
#define BINDING_RESTIR_INDIRECT_INITIAL_SAMPLES (0)
#define BINDING_RESTIR_INDIRECT_RESERVOIRS (1)
#define BINDING_RESTIR_INDIRECT_RESERVOIRS_PREV (2)
#define BINDING_VOLUMETRIC_STORAGE (0)
#define BINDING_VOLUMETRIC_SAMPLER (1)
#define BINDING_VOLUMETRIC_SAMPLER_PREV (2)
#define BINDING_VOLUMETRIC_ILLUMINATION (3)
#define BINDING_VOLUMETRIC_ILLUMINATION_SAMPLER (4)
#define INSTANCE_CUSTOM_INDEX_FLAG_DYNAMIC (1 << 0)
#define INSTANCE_CUSTOM_INDEX_FLAG_FIRST_PERSON (1 << 1)
#define INSTANCE_CUSTOM_INDEX_FLAG_FIRST_PERSON_VIEWER (1 << 2)
#define INSTANCE_CUSTOM_INDEX_FLAG_SKY (1 << 3)
#define INSTANCE_MASK_WORLD_0 (1 << 0)
#define INSTANCE_MASK_WORLD_1 (1 << 1)
#define INSTANCE_MASK_WORLD_2 (1 << 2)
#define INSTANCE_MASK_RESERVED_0 (1 << 3)
#define INSTANCE_MASK_RESERVED_1 (1 << 4)
#define INSTANCE_MASK_REFRACT (1 << 5)
#define INSTANCE_MASK_FIRST_PERSON (1 << 6)
#define INSTANCE_MASK_FIRST_PERSON_VIEWER (1 << 7)
#define PAYLOAD_INDEX_DEFAULT (0)
#define PAYLOAD_INDEX_SHADOW (1)
#define SBT_INDEX_RAYGEN_PRIMARY (0)
#define SBT_INDEX_RAYGEN_REFL_REFR (1)
#define SBT_INDEX_RAYGEN_DIRECT (2)
#define SBT_INDEX_RAYGEN_INDIRECT_INIT (3)
#define SBT_INDEX_RAYGEN_INDIRECT_FINAL (4)
#define SBT_INDEX_RAYGEN_GRADIENTS (5)
#define SBT_INDEX_RAYGEN_INITIAL_RESERVOIRS (6)
#define SBT_INDEX_RAYGEN_VOLUMETRIC (7)
#define SBT_INDEX_MISS_DEFAULT (0)
#define SBT_INDEX_MISS_SHADOW (1)
#define SBT_INDEX_HITGROUP_FULLY_OPAQUE (0)
#define SBT_INDEX_HITGROUP_ALPHA_TESTED (1)
#define MATERIAL_NO_TEXTURE (0)
#define MATERIAL_BLENDING_TYPE_OPAQUE (0)
#define MATERIAL_BLENDING_TYPE_ALPHA (1)
#define MATERIAL_BLENDING_TYPE_ADD (2)
#define MATERIAL_BLENDING_TYPE_SHADE (3)
#define MATERIAL_BLENDING_TYPE_BIT_COUNT (2)
#define MATERIAL_BLENDING_TYPE_BIT_MASK (3)
#define GEOM_INST_FLAG_BLENDING_LAYER_COUNT (4)
#define GEOM_INST_FLAG_RESERVED_0 (1 << 8)
#define GEOM_INST_FLAG_RESERVED_1 (1 << 9)
#define GEOM_INST_FLAG_RESERVED_2 (1 << 10)
#define GEOM_INST_FLAG_RESERVED_3 (1 << 11)
#define GEOM_INST_FLAG_RESERVED_4 (1 << 12)
#define GEOM_INST_FLAG_RESERVED_5 (1 << 13)
#define GEOM_INST_FLAG_RESERVED_6 (1 << 14)
#define GEOM_INST_FLAG_EXISTS_LAYER1 (1 << 15)
#define GEOM_INST_FLAG_EXISTS_LAYER2 (1 << 16)
#define GEOM_INST_FLAG_EXISTS_LAYER3 (1 << 17)
#define GEOM_INST_FLAG_MEDIA_TYPE_ACID (1 << 18)
#define GEOM_INST_FLAG_EXACT_NORMALS (1 << 19)
#define GEOM_INST_FLAG_IGNORE_REFRACT_AFTER (1 << 20)
#define GEOM_INST_FLAG_REFL_REFR_ALBEDO_MULT (1 << 21)
#define GEOM_INST_FLAG_REFL_REFR_ALBEDO_ADD (1 << 22)
#define GEOM_INST_FLAG_NO_MEDIA_CHANGE (1 << 23)
#define GEOM_INST_FLAG_REFRACT (1 << 24)
#define GEOM_INST_FLAG_REFLECT (1 << 25)
#define GEOM_INST_FLAG_PORTAL (1 << 26)
#define GEOM_INST_FLAG_MEDIA_TYPE_WATER (1 << 27)
#define GEOM_INST_FLAG_MEDIA_TYPE_GLASS (1 << 28)
#define GEOM_INST_FLAG_GENERATE_NORMALS (1 << 29)
#define GEOM_INST_FLAG_INVERTED_NORMALS (1 << 30)
#define GEOM_INST_FLAG_IS_MOVABLE (1 << 31)
#define SKY_TYPE_COLOR (0)
#define SKY_TYPE_CUBEMAP (1)
#define SKY_TYPE_RASTERIZED_GEOMETRY (2)
#define BLUE_NOISE_TEXTURE_COUNT (128)
#define BLUE_NOISE_TEXTURE_SIZE (128)
#define BLUE_NOISE_TEXTURE_SIZE_POW (7)
#define COMPUTE_COMPOSE_GROUP_SIZE_X (16)
#define COMPUTE_COMPOSE_GROUP_SIZE_Y (16)
#define COMPUTE_BLOOM_UPSAMPLE_GROUP_SIZE_X (16)
#define COMPUTE_BLOOM_UPSAMPLE_GROUP_SIZE_Y (16)
#define COMPUTE_BLOOM_DOWNSAMPLE_GROUP_SIZE_X (16)
#define COMPUTE_BLOOM_DOWNSAMPLE_GROUP_SIZE_Y (16)
#define COMPUTE_BLOOM_APPLY_GROUP_SIZE_X (16)
#define COMPUTE_BLOOM_APPLY_GROUP_SIZE_Y (16)
#define COMPUTE_BLOOM_STEP_COUNT (8)
#define COMPUTE_EFFECT_GROUP_SIZE_X (16)
#define COMPUTE_EFFECT_GROUP_SIZE_Y (16)
#define COMPUTE_LUM_HISTOGRAM_GROUP_SIZE_X (16)
#define COMPUTE_LUM_HISTOGRAM_GROUP_SIZE_Y (16)
#define COMPUTE_LUM_HISTOGRAM_BIN_COUNT (256)
#define COMPUTE_VERT_PREPROC_GROUP_SIZE_X (256)
#define VERT_PREPROC_MODE_ONLY_DYNAMIC (0)
#define VERT_PREPROC_MODE_DYNAMIC_AND_MOVABLE (1)
#define VERT_PREPROC_MODE_ALL (2)
#define GRADIENT_ESTIMATION_ENABLED (1)
#define COMPUTE_GRADIENT_ATROUS_GROUP_SIZE_X (16)
#define COMPUTE_ANTIFIREFLY_GROUP_SIZE_X (16)
#define COMPUTE_SVGF_TEMPORAL_GROUP_SIZE_X (16)
#define COMPUTE_SVGF_VARIANCE_GROUP_SIZE_X (16)
#define COMPUTE_SVGF_ATROUS_GROUP_SIZE_X (16)
#define COMPUTE_SVGF_ATROUS_ITERATION_COUNT (4)
#define COMPUTE_ASVGF_STRATA_SIZE (3)
#define COMPUTE_ASVGF_GRADIENT_ATROUS_ITERATION_COUNT (4)
#define COMPUTE_INDIRECT_DRAW_FLARES_GROUP_SIZE_X (256)
#define LENS_FLARES_MAX_DRAW_CMD_COUNT (512)
#define DEBUG_SHOW_FLAG_MOTION_VECTORS (1 << 0)
#define DEBUG_SHOW_FLAG_GRADIENTS (1 << 1)
#define DEBUG_SHOW_FLAG_UNFILTERED_DIFFUSE (1 << 2)
#define DEBUG_SHOW_FLAG_UNFILTERED_SPECULAR (1 << 3)
#define DEBUG_SHOW_FLAG_UNFILTERED_INDIRECT (1 << 4)
#define DEBUG_SHOW_FLAG_ONLY_DIRECT_DIFFUSE (1 << 5)
#define DEBUG_SHOW_FLAG_ONLY_SPECULAR (1 << 6)
#define DEBUG_SHOW_FLAG_ONLY_INDIRECT_DIFFUSE (1 << 7)
#define DEBUG_SHOW_FLAG_LIGHT_GRID (1 << 8)
#define DEBUG_SHOW_FLAG_ALBEDO_WHITE (1 << 9)
#define MAX_RAY_LENGTH (10000.0)
#define MEDIA_TYPE_VACUUM (0)
#define MEDIA_TYPE_WATER (1)
#define MEDIA_TYPE_GLASS (2)
#define MEDIA_TYPE_ACID (3)
#define MEDIA_TYPE_COUNT (4)
#define GEOM_INST_NO_TRIANGLE_INFO (UINT32_MAX)
#define LIGHT_TYPE_NONE (0)
#define LIGHT_TYPE_DIRECTIONAL (1)
#define LIGHT_TYPE_SPHERE (2)
#define LIGHT_TYPE_TRIANGLE (3)
#define LIGHT_TYPE_SPOT (4)
#define LIGHT_ARRAY_DIRECTIONAL_LIGHT_OFFSET (0)
#define LIGHT_ARRAY_REGULAR_LIGHTS_OFFSET (1)
#define LIGHT_INDEX_NONE (32767)
#define LIGHT_GRID_SIZE_X (16)
#define LIGHT_GRID_SIZE_Y (16)
#define LIGHT_GRID_SIZE_Z (16)
#define LIGHT_GRID_CELL_SIZE (128)
#define COMPUTE_LIGHT_GRID_GROUP_SIZE_X (256)
#define PORTAL_INDEX_NONE (63)
#define PORTAL_MAX_COUNT (63)
#define PACKED_INDIRECT_SAMPLE_SIZE_IN_WORDS (6)
#define PACKED_INDIRECT_RESERVOIR_SIZE_IN_WORDS (8)
#define VOLUMETRIC_SIZE_X (160)
#define VOLUMETRIC_SIZE_Y (88)
#define VOLUMETRIC_SIZE_Z (64)
#define COMPUTE_VOLUMETRIC_GROUP_SIZE_X (16)
#define COMPUTE_VOLUMETRIC_GROUP_SIZE_Y (16)
#define VOLUME_ENABLE_NONE (0)
#define VOLUME_ENABLE_SIMPLE (1)
#define VOLUME_ENABLE_VOLUMETRIC (2)

struct ShVertex
{
    float position[4];
    float normal[4];
    float tangent[4];
    float texCoord[2];
    uint32_t color;
    uint32_t _padding;
};

struct ShGlobalUniform
{
    float view[16];
    float invView[16];
    float viewPrev[16];
    float projection[16];
    float invProjection[16];
    float projectionPrev[16];
    float volumeViewProj[16];
    float volumeViewProjInv[16];
    float volumeViewProj_Prev[16];
    float volumeViewProjInv_Prev[16];
    float cellWorldSize;
    float lightmapScreenCoverage;
    uint32_t _unused0;
    float renderWidth;
    float renderHeight;
    uint32_t frameId;
    float timeDelta;
    float minLogLuminance;
    float maxLogLuminance;
    float luminanceWhitePoint;
    uint32_t stopEyeAdaptation;
    uint32_t directionalLightExists;
    float polyLightSpotlightFactor;
    uint32_t skyType;
    float skyColorMultiplier;
    uint32_t skyCubemapIndex;
    float skyColorDefault[4];
    float cameraPosition[4];
    float cameraPositionPrev[4];
    uint32_t debugShowFlags;
    uint32_t indirSecondBounce;
    uint32_t lightCount;
    uint32_t lightCountPrev;
    float emissionMapBoost;
    float emissionMaxScreenColor;
    float normalMapStrength;
    float skyColorSaturation;
    uint32_t maxBounceShadowsLights;
    float rayLength;
    uint32_t rayCullBackFaces;
    uint32_t rayCullMaskWorld;
    float bloomIntensity;
    float bloomThreshold;
    float bloomEmissionMultiplier;
    uint32_t reflectRefractMaxDepth;
    uint32_t cameraMediaType;
    float indexOfRefractionWater;
    float indexOfRefractionGlass;
    float waterTextureDerivativesMultiplier;
    uint32_t volumeEnableType;
    float volumeScattering;
    uint32_t forceNoWaterRefraction;
    uint32_t waterNormalTextureIndex;
    uint32_t noBackfaceReflForNoMediaChange;
    float time;
    float waterWaveSpeed;
    float waterWaveStrength;
    float waterColorAndDensity[4];
    float acidColorAndDensity[4];
    float cameraRayConeSpreadAngle;
    float waterTextureAreaScale;
    uint32_t dirtMaskTextureIndex;
    float upscaledRenderWidth;
    float worldUpVector[4];
    float upscaledRenderHeight;
    float jitterX;
    float jitterY;
    float primaryRayMinDist;
    uint32_t rayCullMaskWorld_Shadow;
    uint32_t lensFlareCullingInputCount;
    uint32_t applyViewProjToLensFlares;
    uint32_t twirlPortalNormal;
    uint32_t lightIndexIgnoreFPVShadows;
    float gradientMultDiffuse;
    float gradientMultIndirect;
    float gradientMultSpecular;
    float minRoughness;
    float volumeCameraNear;
    float volumeCameraFar;
    uint32_t antiFireflyEnabled;
    float volumeAmbient[4];
    float volumeSourceColor[4];
    float volumeDirToSource[4];
    float volumeSourceAsymmetry;
    float _pad1;
    float _pad2;
    float _pad3;
    int32_t instanceGeomInfoOffset[48];
    int32_t instanceGeomInfoOffsetPrev[48];
    int32_t instanceGeomCount[48];
    float viewProjCubemap[96];
    float skyCubemapRotationTransform[16];
};

struct ShGeometryInstance
{
    float model[16];
    float prevModel[16];
    uint32_t flags;
    uint32_t texture_base;
    uint32_t texture_base_ORM;
    uint32_t texture_base_N;
    uint32_t texture_base_E;
    uint32_t texture_layer1;
    uint32_t texture_layer2;
    uint32_t texture_lightmap;
    uint32_t colorFactor_base;
    uint32_t colorFactor_layer1;
    uint32_t colorFactor_layer2;
    uint32_t colorFactor_lightmap;
    uint32_t baseVertexIndex;
    uint32_t baseIndexIndex;
    uint32_t prevBaseVertexIndex;
    uint32_t prevBaseIndexIndex;
    uint32_t vertexCount;
    uint32_t indexCount;
    float roughnessDefault;
    float metallicDefault;
    float emissiveMult;
    uint32_t firstVertex_Layer1;
    uint32_t firstVertex_Layer2;
    uint32_t firstVertex_Layer3;
    uint32_t _unused3;
    uint32_t _unused4;
    uint32_t _unused5;
    uint32_t _unused6;
    uint32_t _unused7;
    uint32_t _unused8;
    uint32_t _unused9;
    uint32_t _unused10;
};

struct ShTonemapping
{
    uint32_t histogram[256];
    float avgLuminance;
};

struct ShLightEncoded
{
    float color[3];
    uint32_t lightType;
    float data_0[4];
    float data_1[4];
    float data_2[4];
};

struct ShLightInCell
{
    uint32_t selected_lightIndex;
    float selected_targetPdf;
    float weightSum;
    uint32_t __pad0;
};

struct ShVertPreprocessing
{
    uint32_t tlasInstanceCount;
    uint32_t tlasInstanceIsDynamicBits[2];
};

struct ShIndirectDrawCommand
{
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;
    float positionToCheck_X;
    float positionToCheck_Y;
    float positionToCheck_Z;
};

struct ShLensFlareInstance
{
    uint32_t textureIndex;
};

struct ShDecalInstance
{
    float transform[16];
    uint32_t textureAlbedoAlpha;
    uint32_t textureOcclusionRoughnessMetallic;
    uint32_t textureNormal;
    uint32_t textureEmissive;
};

struct ShPortalInstance
{
    float inPosition[4];
    float outPosition[4];
    float outDirection[4];
    float outUp[4];
};

}