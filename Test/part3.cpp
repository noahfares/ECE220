#include <iostream>
#include <string.h>
using namespace std;

class book {
private:
    char *author;
    char *name;
public:
    construct(char *,char *);
    void print();
};

int main() {
    book first("author01", "name01");
    book second("author02", "name02");
    
}

book ::construct(char *n1, char *n2){
    strcpy(author, n1);
    strcpy(name,n2);
}

void book ::print(){
    cout << "First book: \n" << "Name: " << first->name << "Author: " << first->author << endl;
    cout << "Second book: \n" << "Name: " << second->name << "Author: " << second->author << endl;
}
