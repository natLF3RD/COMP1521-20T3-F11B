#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


void chmod_if_needed(char* path);

int main (int argc, char* argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Expected at least 2 arguments, got %d", argc);
        exit(1);
    }

    for (int i=1; i<argc; i++) {
        chmod_if_needed(argv[i]);
    }

    return 0;
}


void chmod_if_needed(char* path) {
    struct stat sb;

    if (lstat(path, &sb) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    if ((sb.st_mode & S_IWOTH) != 0 ) {
        // file is publically writeable.
        printf("removing public write from %s\n", path);
        mode_t new_mode = sb.st_mode & ~S_IWOTH;
        if (chmod(path, new_mode) != 0) {
            // failed to change it.
            perror("chmod");
            exit(1);
        }
    } else {
        printf("%s is not publically writable\n", path);
    }


}