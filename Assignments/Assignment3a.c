#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

struct book {
    char *title;
    char *author;
    struct book *next;
    struct book *previous;
};

int main(void) {

    char *book_title[SIZE] = {"Neuromancer", "Hyperion", "Solaris"};
    char *book_author[SIZE] = {"William Gibson", "Dan Simmons", "Stanislaw Lem"};
    struct book *first;
    struct book *current;
    struct book *new;
    int i, len;

    current = (struct book *)malloc(sizeof(struct book));
    len = (int)strlen(book_title[0]);
    current->title = (char *) malloc((len+1) * sizeof(char));
    strcpy(current->title, book_title[0]);
    len = (int)strlen(book_author[0]);
    current->author = (char *) malloc((len+1) * sizeof(char));
    strcpy(current->author, book_author[0]);
    current->next = NULL;
    current->previous = NULL;
    first = current;

    for (i=1; i<SIZE; i++) {
 // place your code here

    }

    current = first;
    i = 0;
    while (current != NULL) {
// pleace your code here

    }

    printf("END\n");

    return 0;
}
