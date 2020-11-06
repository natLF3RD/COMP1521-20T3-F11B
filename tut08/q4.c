#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Bad number of arguments, expected 2 but received %d", argc);
        exit(1);
    }

    // opening file to read
    FILE* fp = fopen(argv[1],"r");

    // check it actually opened
    if (fp == NULL) {
        // it failed
        perror(argv[1]);
        exit(1);
    }

    // now to actually read the file.
    int c = fgetc(fp);
    while (c != EOF) {
        fprintf(stdout, "%c", c);

        c = fgetc(fp);
    }

    fclose(fp);
    return 0;
}