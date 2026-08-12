#include <stdio.h>
#include <stdlib.h>
#include "fancystring.h"

int main(int argc, char *argv[]) {
    if (argc == 2){
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "error: cannot open file '%s'", argv[1]);
            exit(1);
        }

        //returns a linked list of lines from file, starting from last line
        FancyString *line = fancy_readlines(fp);
        FancyString *previousLine;
        
        while (line != NULL) {
            printf("%s", line->string);

            previousLine = line;
            line = previousLine->prev;

            FancyString_free(previousLine);
        }
        fclose(fp);
        return 0;
    }
}