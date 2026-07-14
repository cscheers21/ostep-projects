#include <stdio.h>;
#include <string.h>;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        printf("wgrep: cannout open file\n");
        return 1;
    }

    char *string = argv[2];
    char *line = NULL;
    size_t size = 0;

    while(getline(&line, &size, fp) != -1) {
            if (strstr(line, string) != NULL) {
                printf("%s\n", line);
            }
    }
    

}