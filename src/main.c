#include <stdio.h>
#include "bmp.h"

const int ARGUMENTS_COUNT = 2;

BMPheader *get_BMPheader(FILE *image);
DIBheader *get_DIBheader(FILE *image, uint32_t offset);
void print_DIBheader(DIBheader *dibheader);
void print_BMPheader(BMPheader *bmpheader);
void clear(BMPheader *bmpheader, DIBheader *dibheader);

FILE *open_BMPfile(char *path_to_file)
{
    return fopen(path_to_file, "rb");
}

int main(int argc, char **argv)
{
    FILE *image;
    if (argc != ARGUMENTS_COUNT)
    {
        fprintf(stderr, "Error: wrong number of arguments");
        return 0;
    }
    else if (!(image = open_BMPfile(argv[1])))
    {
        fprintf(stderr, "Error: can't open the file");
        return 0;
    }
    BMPheader *bmpheader = get_BMPheader(image);
    DIBheader *dibheader = get_DIBheader(image, bmpheader->offset);
    print_BMPheader(bmpheader);
    print_DIBheader(dibheader);
    clear(bmpheader, dibheader);
    fclose(image);
    return 0;
}
