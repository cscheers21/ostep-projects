#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    char prev_char = fgetc(fp);
    if (prev_char == EOF) {
        return 0;
    }

    int counter = 1;

    char sent_char = fgetc(fp);
    if (sent_char == EOF) {
        fwrite(&counter, sizeof(int), 1, stdout);
        fwrite(&prev_char, sizeof(char), 1, stdout);
        return 0;
    }

    while (sent_char != EOF) {
        if (sent_char != prev_char) {
            fwrite(&counter, sizeof(int), 1, stdout);
            fwrite(&prev_char, sizeof(char), 1, stdout);
            counter = 1;
        }
        else {
            counter++;
        }

        prev_char = sent_char;
        sent_char = fgetc(fp);
    }

    counter++;
    fwrite(&counter, sizeof(int), 1, stdout);
    fwrite(&prev_char, sizeof(char), 1, stdout);

    return 0;
}