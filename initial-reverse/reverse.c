#include <stdio.h>

int main(int argc, char argv[]) {
    if (argc == 2){
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "error: cannot open file '%s'", argv[1]);
            exit(1);
        }

        
    }
}