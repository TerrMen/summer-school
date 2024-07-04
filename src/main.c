#include <stdio.h>
#include <stdbool.h>
#include "bmp_headers.h"

BMPheader *get_BMPheader(FILE *image);
DIBheader *get_DIBheader(FILE *image, uint32_t offset);
void print_DIBheader(DIBheader *dibheader);
void print_BMPheader(BMPheader *bmpheader);
void clear(BMPheader *bmpheader, DIBheader *dibheader);
bool is_error_in_arguments_occured(int argc, char **argv);

FILE *open_BMPfile(char *path_to_file)
{
    return fopen(path_to_file, "rb");
}

int main(int argc, char **argv)
{
    FILE *image;
    if (is_error_in_arguments_occured(argc, argv))
    {
        return 0;
    }

    if (!(image = open_BMPfile(argv[1])))
    {
        fprintf(stderr, "Error: can't open the file\n");
        return 0;
    }

    BMPheader *bmpheader = get_BMPheader(image);
    if (!bmpheader)
    {
        fclose(image);
        fprintf(stderr, "Error: bmp headers don't match version 3, 4, 5\n");
        return 0;
    }
    DIBheader *dibheader = get_DIBheader(image, bmpheader->offset);
    print_BMPheader(bmpheader);
    print_DIBheader(dibheader);
    clear(bmpheader, dibheader);
    fclose(image);
    return 0;
}
