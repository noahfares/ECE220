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

    //*********************************************************
    current = (struct book *)malloc(sizeof(struct book));
    len = (int)strlen(book_title[0]);
    current->title = (char *) malloc((len+1) * sizeof(char));
    strcpy(current->title, book_title[0]);
    len = (int)strlen(book_author[0]);
    current->author = (char *) malloc((len+1) * sizeof(char));
    strcpy(current->author, book_author[0]);
    //*********************************************************

    current->next = NULL;
    current->previous = NULL;
    first = current;

    for (i=1; i<SIZE; i++) {

        new = (struct book *)malloc(sizeof(struct book));//setting the memory for each node
        len = (int)strlen(book_title[i]);
        new->title = (char *) malloc((len+1) * sizeof(char));
        strcpy(new->title, book_title[i]);
        len = (int)strlen(book_author[i]);
        new->author = (char *) malloc((len+1) * sizeof(char));
        strcpy(new->author, book_author[i]); 

        if (i == 1) {//setting up the current node

            new->previous = current;
            new->next = NULL;
            current->next = new;
            current->previous = first;
            current = new;//simply using the memory allocation from new node to store the current node information 

        } else {//setting up the new node

            new->previous = current;
            new->next = NULL;
            current->next = new;
            current->previous = first;
        }

        
    }

    first->next = current;

    current = first;
    while (current != NULL) {
        printf("Author of %s is %s \n", current->title, current->author);//this will simply print then move to the next node 

        current = current->next;
        
    }

    printf("END\n");

    return 0;
}
