#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);

    return 0;
}