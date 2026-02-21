#include <cstdio>
#include <cstdlib>

#include "testScanner.h"

int main(int argc, char* argv[])
{
    FILE* file = NULL;

    if (argc == 1)
    {
        file = stdin;
    }
    else if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (file == NULL)
        {
            fprintf(stderr, "Fatal: Cannot open file\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Fatal: Improper usage\n");
        fprintf(stderr, "Usage: P2 [filename]\n");
        exit(EXIT_FAILURE);
    }

    testScanner(file);

    if (file != stdin)
    {
        fclose(file);
    }

    return 0;
}