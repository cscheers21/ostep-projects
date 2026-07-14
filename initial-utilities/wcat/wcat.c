#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    int index = 1;

    while (index < argc) {
        FILE *fp = fopen(argv[index], "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            return 1;
        }

        char buffer[100];

        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("%s", buffer);
        }

        fclose(fp);
        index++;
    }

    return 0;
}