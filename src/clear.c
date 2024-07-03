#include "bmp.h"
#include <stdlib.h>

void clear(BMPheader *bmpheader, DIBheader *dibheader)
{
    free(bmpheader);
    free(dibheader->dib_header_v3);
    free(dibheader->dib_header_v4);
    free(dibheader->dib_header_v5);
    free(dibheader);
}
