#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

const int ARGUMENTS_COUNT = 2;

#pragma pack(2)
typedef struct BMPheader{
    uint8_t id[2];
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

FILE* open_BMP(char *path_to_file) {
    return fopen(path_to_file, "rb");
}

int read_BMP(FILE *image) {
    BMPheader *bmpheader = (BMPheader*)malloc(sizeof(BMPheader));
    fread(bmpheader, sizeof(BMPheader), 1, image);
}

int main(int argc, char **argv){
    FILE *image;
    if (argc != ARGUMENTS_COUNT) {
        fprintf(stderr, "Error: wrong number of arguments");
        return 0;
    }
    else if (!(image = open_BMP(argv[1]))) {
        fprintf(stderr, "Error: can't open the file");
        return 0;
    }
    else {
        read_BMP(image);
    }
    return 0;
}