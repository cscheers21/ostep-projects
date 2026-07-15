#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    int index = 1;
    int prev_char;
    int sent_char;
    int counter = 1;
    bool first_file = true;
    FILE *fp = NULL;

    while (index < argc) {
        fp = fopen(argv[index], "r");
        if (fp == NULL) {
            printf("Could not open file\n");
            return 1;
        }

        if (first_file) {
            prev_char = fgetc(fp);
            if (prev_char == EOF) {
                fclose(fp);
                index++;
                continue;
            }
            first_file = false;
        }

        while ((sent_char = fgetc(fp)) != EOF) {
            if (sent_char == prev_char) {
                counter++;
            }
            else {
                fwrite(&counter, sizeof(int), 1, stdout);
                fwrite(&prev_char, sizeof(char), 1, stdout);

                prev_char = sent_char;
                counter = 1;
            }
        }
        fclose(fp);
        index++;
    }

    if (!first_file) {
        fwrite(&counter, sizeof(int), 1, stdout);
        fwrite(&prev_char, sizeof(char), 1, stdout);
    }
    return 0;
}