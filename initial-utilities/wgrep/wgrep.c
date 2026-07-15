#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    FILE *input = NULL;

    if (argc < 3) {
        input = stdin;
    }
    else {
        input = fopen(argv[2], "r");
        if (input == NULL) {
            printf("wgrep: cannot open file\n");
            return 1;
        }
    }

    char *string = argv[1];
    char *line = NULL;
    size_t size = 0;

    while(getline(&line, &size, input) != -1) {
            if (strstr(line, string) != NULL) {
                printf("%s", line);
            }
    }
    free(line);

    if (input != stdin) {
        fclose(input);
    }

    return 0;
}