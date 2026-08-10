#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

typedef struct _fancystring
{
    ssize_t length;
    char *string;
    size_t buffer_size;
    struct _fancystring *next;
    struct _fancystring *prev;
} FancyString;

void FancyString_free(FancyString *target)
{
    if (target->string)
    {
        free(target->string);
    }
    free(target);
}

FancyString *fancy_getline(FILE *stream)
{
    FancyString *target = malloc(sizeof(*target));
    if (target == NULL) {
        return NULL;
    }
    target->string = NULL;
    target->buffer_size = 0;
    target->next = NULL;
    target->prev = NULL;

    target->length = getline(&(target->string), &(target->buffer_size), stream);
    if (target->length == -1)
    {
        FancyString_free(target);
        return NULL;
    }
    else
    {
        return target;
    }
}

FancyString *fancy_readlines(FILE *stream)
{
    FancyString *first = NULL;
    FancyString *last = NULL;
    FancyString *i = NULL;

    while ((i = fancy_getline(stream)) != NULL)
    {
        if (first == NULL)
        {
            first = i;
            last = i;
        }
        else
        {
            last->next = i;
            i->prev = last;
            last = i;
        }
    }

    return last;
}

/*int main()
{
    printf("Enter many lines, end with CTRL+D\n");

    FancyString *line = fancy_readlines(stdin);
    FancyString *previous_line;

    int i = 1;
    while (line != NULL)
    {
        printf("Line %d: %s", i, line->string);
        i++;
        previous_line = line;
        line = line->next;
        FancyString_free(previous_line);
    }

    return 0;
}*/
