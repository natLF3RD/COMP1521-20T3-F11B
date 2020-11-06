#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Bad number of arguments, expected 2 but received %d", argc);
        exit(1);
    }

    // opening file to write
    FILE* fp = fopen(argv[1], "w");

    // check it actually opened
    if (fp == NULL) {
        // it failed
        perror(argv[1]);
        exit(1);
    }

    // now to actually read the file.
    int c = fgetc(stdin);
    while (c != EOF) {
        fprintf(fp, "%c", c);

        c = fgetc(stdin);
    }

    fclose(fp);
    return 0;
}