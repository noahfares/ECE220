#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5


struct person {
    char *fname;
    int pHeight;
    struct person *next;
};


struct person *find_tallest(struct person *last);


int main(void) {

    char *name[SIZE] = {"Carol", "Johan", "Coty", "Joe", "Beth"};
    int height[SIZE] = {165, 179, 177, 173, 181};
    struct person *first;
    struct person *current;
    struct person *new;
    int i, len;

    struct person *found;

    current = (struct person *)malloc(sizeof(struct person));
    len = 1+(int)strlen(name[0]);
    current->fname = (char *) malloc(len * sizeof(char));
    strcpy(current->fname, name[0]);
    current->pHeight = height[0];
    current->next = NULL;
    first = current;

    for (i=1; i<SIZE; i++) {
        new = (struct person *)malloc(sizeof(struct person));
        len = 1+(int)strlen(name[i]);
        new->fname = (char *) malloc(len * sizeof(char));
        strcpy(new->fname, name[i]);

        new->pHeight = height[i];
        new->next = NULL;
        current->next = new;
        current = new;
    }

    found = find_tallest(first);
    
    printf("tallest person is: %s\n", found->fname);

    //printing the whole list
    current = first;
    i = 0;
    while (current != NULL) {
        printf("name [%d] is %s\n", i++, current->fname);
        current = current->next;
    }
    printf("END\n");


    return 0;
}

int *find_tallest(int first) {
    int *j = first;
    
    for (int i = 0; i < SIZE; i++) {
        if (j[i] < j[i+1]);
            int temp = j[i+1];
            j[i+1] = j[i];
            j[i] = temp;
    }
    return j;
}