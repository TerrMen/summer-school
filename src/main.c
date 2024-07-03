#include <stdio.h>
#include <stdint.h>

typedef struct BMPheader{
    unsigned char id[2];
    uint32_t size;
    uint32_t unused;
    uint32_t offset;
} BMPheader;

typedef struct DIBheader{
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
} DIBheader;

int main(int argc, char **argv){
    return 0;
}