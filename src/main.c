#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

const int ARGUMENTS_COUNT = 2;
const int HEADERS_VERSION4_SIZE = 122;
const int HEADERS_VERSION5_SIZE = 138;

#pragma pack(2)
typedef struct BMPheader{
    uint8_t id[2];
    uint32_t size;
    uint32_t unused;
    uint32_t offset;
} BMPheader;

typedef struct DIBheader_version3{
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

typedef struct DIBheader_version4{
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

typedef struct DIBheader_version5{
    uint32_t intent;
    uint32_t profile_data;
    uint32_t profile_size;
    uint32_t unused;
} DIBheader_version5;

typedef struct DIBheader{
    DIBheader_version3 *dib_header_v3;
    DIBheader_version4 *dib_header_v4;
    DIBheader_version5 *dib_header_v5;
} DIBheader;

FILE *open_BMPfile(char *path_to_file) {
    return fopen(path_to_file, "rb");
}

DIBheader *get_DIBheader(FILE *image, uint32_t offset) {
    DIBheader_version3 *dibheader_version3 = (DIBheader_version3*)malloc(sizeof(DIBheader_version3));
    fread(dibheader_version3, sizeof(DIBheader_version3), 1, image);
    DIBheader_version4 *dibheader_version4 = NULL;
    DIBheader_version5 *dibheader_version5 = NULL;
    if (offset >= HEADERS_VERSION4_SIZE) {
        dibheader_version4 = (DIBheader_version4*)malloc(sizeof(DIBheader_version4));
        fread(dibheader_version4, sizeof(DIBheader_version4), 1, image);
    }
    if (offset == HEADERS_VERSION5_SIZE) {
        dibheader_version5 = (DIBheader_version5*)malloc(sizeof(DIBheader_version5));
        fread(dibheader_version5, sizeof(DIBheader_version5), 1, image);
    }
    DIBheader *dibheader = (DIBheader*)malloc(sizeof(DIBheader));
    dibheader->dib_header_v3 = dibheader_version3;
    dibheader->dib_header_v4 = dibheader_version4;
    dibheader->dib_header_v5 = dibheader_version5;
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
    printf("Width: %d\n", dibheader->dib_header_v3->width);
    printf("Height: %d\n", dibheader->dib_header_v3->height);
    printf("Number of color planes: %d\n", dibheader->dib_header_v3->planes_count);
    printf("Bits/pixel: %d\n", dibheader->dib_header_v3->bits_count);
    printf("Compression: %d\n", dibheader->dib_header_v3->compression); //todo
    printf("Size of the bitmap data: %d\n", dibheader->dib_header_v3->bitmap_data_size);
    printf("Pixels/meter: %dx%d\n", dibheader->dib_header_v3->horizontal_resolution, dibheader->dib_header_v3->vertical_resolution);
    printf("Number of colors: %d\n", dibheader->dib_header_v3->colors_count);
    printf("Number of important colors: %d\n", dibheader->dib_header_v3->important_colors);
    if (dibheader->dib_header_v4) {
        printf("Red mask: %d\n", dibheader->dib_header_v4->red_mask);
        printf("Green mask: %d\n", dibheader->dib_header_v4->green_mask);
        printf("Blue mask: %d\n", dibheader->dib_header_v4->blue_mask);
        printf("Alpha mask: %d\n", dibheader->dib_header_v4->alpha_mask);
        printf("CSType: %d\n", dibheader->dib_header_v4->cstype);
        printf("Gamma red: %d\n", dibheader->dib_header_v4->gamma_red);
        printf("Gamma green: %d\n", dibheader->dib_header_v4->gamma_green);
        printf("Gamma blue: %d\n", dibheader->dib_header_v4->gamma_blue);
    }
    if (dibheader->dib_header_v5) {
        printf("Intent: %d\n", dibheader->dib_header_v5->intent);
        printf("Profile data: %d\n", dibheader->dib_header_v5->profile_data);
        printf("Profile size: %d\n", dibheader->dib_header_v5->profile_size);
    }
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
    DIBheader *dibheader = get_DIBheader(image, bmpheader->offset);
    print_BMPheader(bmpheader);
    print_DIBheader(dibheader);
    free(bmpheader);
    free(dibheader);
    return 0;
}