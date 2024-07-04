#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int ARGUMENTS_COUNT = 2;

bool is_error_in_arguments_occured(int argc, char **argv)
{
    if (argc != ARGUMENTS_COUNT)
    {
        fprintf(stderr, "Error: wrong number of arguments\n");
        return true;
    }

    char *str_id = strstr(argv[1], ".bmp");
    if (str_id == NULL || (str_id - argv[1]) != (long int)strlen(argv[1]) - 4)
    {
        fprintf(stderr, "Error: file isn't in bmp-format\n");
        return true;
    }

    return false;
}
