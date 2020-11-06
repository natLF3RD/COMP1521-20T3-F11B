#include <stdio.h>
#include <stdlib.h>

unsigned int get_bort(FILE* fp);

int main (int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Bad number of arguments, expected 2 but received %d", argc);
        exit(1);
    }

    // opening file to write
    FILE* fp = fopen(argv[1], "r");

    // check it actually opened
    if (fp == NULL) {
        // it failed
        perror(argv[1]);
        exit(1);
    }

    // now to actually read the file.
    unsigned int bort = get_bort(fp);
    int i = 0;
    while (bort != EOF) {
        fprintf(stdout, "bort %4d, %d\n", i, bort);

        bort = get_bort(fp);
        i++;
    }

    fclose(fp);
    return 0;
}

unsigned int get_bort(FILE* fp) {
    unsigned bort = 0;

    // read the bytes
    unsigned int byte1 = fgetc(fp);
    unsigned int byte2 = fgetc(fp);

    if (byte1 == EOF || byte2 == EOF)
        return EOF;

    bort = (byte1 << 8) | byte2;

    return bort;
}