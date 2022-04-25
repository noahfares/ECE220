#include <iostream>
#include <string.h>
#define MAX 40
using namespace std;

class book {
protected:
    char publisher[MAX];
    int pub_year;
public:
    book();
    book(char *, int);
    void print();
};

class fiction : public book {
private:
    char author[MAX], title[MAX];
public:
    fiction(char *, char *, char *, int);
    void print();

};

int main() {

    char a1_pub[] = "HarperOne";
    int a1_pub_yr = 2014;
    char a1_title[] = "The Alchemist";
    char a1_author[] = "Paulo Coelho";

    char a2_pub[] = "Bantam";
    int a2_pub_yr = 1988;
    char a2_title[] = "A Brief History of Time";
    char a2_author[] = "Stephen Hawking";

    fiction *library[2];

    fiction a1(a1_author, a1_title, a1_pub, a1_pub_yr);//creating the objects
    fiction a2(a2_author, a2_title, a2_pub, a2_pub_yr);

    library[0] = &a1;//storing the addresses of the objects
    library[1] = &a2;

    library[0]->print();
    library[1]->print();

    fiction *copy;
    copy = library[0];
    copy->print();

    library[1]->book::print();

    delete library[1];
    delete library[0];
    
    return 0;
}

book ::book(){//constructor
    publisher[0] = 0;
    pub_year = 0;
}

book ::book(char *publish, int year) {//constructor
    strcpy(publisher,publish);
    pub_year = year;
}

void book::print(){//print for the book class
    cout << "\nPublisher: " << publisher << endl;
    cout << "Year Published: " << pub_year << endl;
}

fiction ::fiction(char * auth, char * book_name, char *publish, int year) {//constructor for fiction class
    strcpy(author,auth);
    strcpy(title,book_name);
    strcpy(publisher,publish);
    pub_year = year;

}

void fiction::print() {//print for he subclass
    book::print();
    cout << "Author: " << author << endl;
    cout << "Title: " << title << endl;   
}
