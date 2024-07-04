#include "bmp_headers.h"
#include <stdio.h>
#include <stdlib.h>

const int HEADERS_VERSION4_SIZE = 122;
const int HEADERS_VERSION5_SIZE = 138;

DIBheader *get_DIBheader(FILE *image, uint32_t offset)
{
    DIBheader_version3 *dibheader_version3 = (DIBheader_version3 *)malloc(sizeof(DIBheader_version3));
    fread(dibheader_version3, sizeof(DIBheader_version3), 1, image);
    DIBheader_version4 *dibheader_version4 = NULL;
    DIBheader_version5 *dibheader_version5 = NULL;

    if (offset >= HEADERS_VERSION4_SIZE)
    {
        dibheader_version4 = (DIBheader_version4 *)malloc(sizeof(DIBheader_version4));
        fread(dibheader_version4, sizeof(DIBheader_version4), 1, image);
    }
    if (offset == HEADERS_VERSION5_SIZE)
    {
        dibheader_version5 = (DIBheader_version5 *)malloc(sizeof(DIBheader_version5));
        fread(dibheader_version5, sizeof(DIBheader_version5), 1, image);
    }

    DIBheader *dibheader = (DIBheader *)malloc(sizeof(DIBheader));
    dibheader->dib_header_v3 = dibheader_version3;
    dibheader->dib_header_v4 = dibheader_version4;
    dibheader->dib_header_v5 = dibheader_version5;
    return dibheader;
}

BMPheader *get_BMPheader(FILE *image)
{
    BMPheader *bmpheader = (BMPheader *)malloc(sizeof(BMPheader));
    fread(bmpheader, sizeof(BMPheader), 1, image);
    return bmpheader;
}
