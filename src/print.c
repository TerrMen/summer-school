#include <stdio.h>
#include "bmp.h"

void print_BMPheader(BMPheader *bmpheader)
{
    printf("Size: %d\n", bmpheader->size);
    printf("Offset of the bitmap data: %d\n", bmpheader->offset);
}

void print_DIBheader(DIBheader *dibheader)
{
    printf("Width: %d\n", dibheader->dib_header_v3->width);
    printf("Height: %d\n", dibheader->dib_header_v3->height);
    printf("Number of color planes: %d\n", dibheader->dib_header_v3->planes_count);
    printf("Bits/pixel: %d\n", dibheader->dib_header_v3->bits_count);
    printf("Compression: %d\n", dibheader->dib_header_v3->compression); // todo
    printf("Size of the bitmap data: %d\n", dibheader->dib_header_v3->bitmap_data_size);
    printf("Pixels/meter: %dx%d\n", dibheader->dib_header_v3->horizontal_resolution, dibheader->dib_header_v3->vertical_resolution);
    printf("Number of colors: %d\n", dibheader->dib_header_v3->colors_count);
    printf("Number of important colors: %d\n", dibheader->dib_header_v3->important_colors);
    if (dibheader->dib_header_v4)
    {
        printf("Red mask: %d\n", dibheader->dib_header_v4->red_mask);
        printf("Green mask: %d\n", dibheader->dib_header_v4->green_mask);
        printf("Blue mask: %d\n", dibheader->dib_header_v4->blue_mask);
        printf("Alpha mask: %d\n", dibheader->dib_header_v4->alpha_mask);
        printf("CSType: %d\n", dibheader->dib_header_v4->cstype);
        printf("Gamma red: %d\n", dibheader->dib_header_v4->gamma_red);
        printf("Gamma green: %d\n", dibheader->dib_header_v4->gamma_green);
        printf("Gamma blue: %d\n", dibheader->dib_header_v4->gamma_blue);
    }
    if (dibheader->dib_header_v5)
    {
        printf("Intent: %d\n", dibheader->dib_header_v5->intent);
        printf("Profile data: %d\n", dibheader->dib_header_v5->profile_data);
        printf("Profile size: %d\n", dibheader->dib_header_v5->profile_size);
    }
}
