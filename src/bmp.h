#include <stdint.h>

#pragma pack(2)
typedef struct BMPheader
{
    uint8_t id[2];
    uint32_t size;
    uint32_t unused;
    uint32_t offset;
} BMPheader;

typedef struct DIBheader_version3
{
    uint32_t dib_size;
    uint32_t width;
    uint32_t height;
    uint16_t planes_count;
    uint16_t bits_count;
    uint32_t compression;
    uint32_t bitmap_data_size;
    uint32_t horizontal_resolution;
    uint32_t vertical_resolution;
    uint32_t colors_count;
    uint32_t important_colors;
} DIBheader_version3;

typedef struct DIBheader_version4
{
    uint32_t red_mask;
    uint32_t green_mask;
    uint32_t blue_mask;
    uint32_t alpha_mask;
    uint32_t cstype;
    uint64_t endpoint_part1;
    uint64_t endpoint_part2;
    uint64_t endpoint_part3;
    uint64_t endpoint_part4;
    uint32_t endpoint_part5;
    uint32_t gamma_red;
    uint32_t gamma_green;
    uint32_t gamma_blue;
} DIBheader_version4;

typedef struct DIBheader_version5
{
    uint32_t intent;
    uint32_t profile_data;
    uint32_t profile_size;
    uint32_t unused;
} DIBheader_version5;

typedef struct DIBheader
{
    DIBheader_version3 *dib_header_v3;
    DIBheader_version4 *dib_header_v4;
    DIBheader_version5 *dib_header_v5;
} DIBheader;
