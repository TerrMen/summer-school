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

typedef struct DIBheader_version{
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

FILE *open_BMPfile(char *path_to_file) {
    return fopen(path_to_file, "rb");
}

DIBheader *get_DIBheader(FILE *image) {
    DIBheader *dibheader = (DIBheader*)malloc(sizeof(DIBheader));
    fread(dibheader, sizeof(DIBheader), 1, image);
    return dibheader;
}

BMPheader *get_BMPheader(FILE *image) {
    BMPheader *bmpheader = (BMPheader*)malloc(sizeof(BMPheader));
    fread(bmpheader, sizeof(BMPheader), 1, image);
    return bmpheader;
}

void print_BMPheader(BMPheader *bmpheader) {
    printf("Size: %d\n", bmpheader->size);
    printf("Offset of the bitmap data: %d\n", bmpheader->offset);
}

void print_DIBheader(DIBheader *dibheader) {
    printf("Width: %d\n", dibheader->width);
    printf("Height: %d\n", dibheader->height);
    printf("Number of color planes: %d\n", dibheader->planes_count);
    printf("Bits/pixel: %d\n", dibheader->bits_count);
    printf("Compression: %d\n", dibheader->compression); //todo
    printf("Size of the bitmap data: %d\n", dibheader->bitmap_data_size);
    printf("Pixels/meter: %dx%d\n", dibheader->horizontal_resolution, dibheader->vertical_resolution);
    printf("Number of colors: %d\n", dibheader->colors_count);
    printf("Number of important colors: %d\n", dibheader->important_colors);
}

int main(int argc, char **argv){
    FILE *image;
    if (argc != ARGUMENTS_COUNT) {
        fprintf(stderr, "Error: wrong number of arguments");
        return 0;
    }
    else if (!(image = open_BMPfile(argv[1]))) {
        fprintf(stderr, "Error: can't open the file");
        return 0;
    }
    BMPheader *bmpheader = get_BMPheader(image);
    DIBheader *dibheader = get_DIBheader(image);
    print_BMPheader(bmpheader);
    print_DIBheader(dibheader);
    return 0;
}