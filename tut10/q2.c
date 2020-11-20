#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
    // fopen("$HOME/.diary", "r"); -> fails
    git a
    // get $HOME
    char* home_location = getenv("HOME");
    if (home_location == NULL) {
        fprintf(stderr, "Failed to get HOME");
    }

    char * diary_string = "/.diary";
    size_t path_size = strlen(diary_string) + strlen(home_location) + 1;
    char path[path_size];
    snprintf(path, path_size, "%s%s", home_location, diary_string);


    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("");
        exit(1);
    }

    int c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);

    return 0;
}