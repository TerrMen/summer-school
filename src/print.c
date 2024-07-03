#include <stdio.h>
#include "bmp.h"

char *get_intent(uint32_t number)
{
    switch (number)
    {
    case 1:
        return "LCS_GM_BUSINESS";
    case 2:
        return "LCS_GM_GRAPHICS";
    case 4:
        return "LCS_GM_IMAGES";
    case 8:
        return "LCS_GM_ABS_COLORIMETRIC";
    default:
        return "None";
    }
}

char *get_CSType(uint32_t number)
{
    switch (number)
    {
    case 0:
        return "LCS_CALIBRATED_RGB";
    case 1934772034:
        return "LCS_sRGB";
    case 1466527264:
        return "LCS_WINDOWS_COLOR_SPACE";
    case 1279872587:
        return "PROFILE_LINKED";
    case 1296188740:
        return "PROFILE_EMBEDDED";
    }
}

char *get_compression(uint32_t number)
{
    switch (number)
    {
    case 0:
        return "BI_RGB";
    case 1:
        return "BI_RLE8";
    case 2:
        return "BI_RLE4";
    case 3:
        return "BI_BITFIELDS";
    case 4:
        return "BI_JPEG";
    case 5:
        return "BI_PNG";
    case 6:
        return "BI_ALPHABITFIELDS";
    default:
        return "None";
    }
}

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
    printf("Compression: %s\n", get_compression(dibheader->dib_header_v3->compression));
    printf("Size of the bitmap data: %d\n", dibheader->dib_header_v3->bitmap_data_size);
    printf("Pixels/meter: %dx%d\n", dibheader->dib_header_v3->horizontal_resolution, dibheader->dib_header_v3->vertical_resolution);
    printf("Number of colors: %d\n", dibheader->dib_header_v3->colors_count);
    printf("Number of important colors: %d\n", dibheader->dib_header_v3->important_colors);
    if (dibheader->dib_header_v4)
    {
        printf("Red mask: %X\n", dibheader->dib_header_v4->red_mask);
        printf("Green mask: %X\n", dibheader->dib_header_v4->green_mask);
        printf("Blue mask: %X\n", dibheader->dib_header_v4->blue_mask);
        printf("Alpha mask: %X\n", dibheader->dib_header_v4->alpha_mask);
        printf("CSType: %s\n", get_CSType(dibheader->dib_header_v4->cstype));
        printf("Gamma red: %d\n", dibheader->dib_header_v4->gamma_red);
        printf("Gamma green: %d\n", dibheader->dib_header_v4->gamma_green);
        printf("Gamma blue: %d\n", dibheader->dib_header_v4->gamma_blue);
    }
    if (dibheader->dib_header_v5)
    {
        printf("Intent: %s\n", get_intent(dibheader->dib_header_v5->intent));
        printf("Profile data: %d\n", dibheader->dib_header_v5->profile_data);
        printf("Profile size: %d\n", dibheader->dib_header_v5->profile_size);
    }
}
