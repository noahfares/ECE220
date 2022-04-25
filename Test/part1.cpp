#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 10

class cd {
private:
    char *name;
    float price;
public:
    cd (char *n) {
        int len = strlen(n) + 1;
        name = new char [len];
        strcpy(name, n);
    }
    void setPrice(float p) {
        price = p;
    }
    char *getName() {
        return name;
    }
    float getPrice() {
        return price;
    }
};

class classicCD: public cd {
private:
    char *composer;
public:
    classicCD (char *n);
    void setComposer (char *n);
    void print();
};


int main() {
    
    char n[] = "Symphony No 5";
    char c[] = "Ludwig van Beethoven";

    classicCD *CD01;
    CD01 = new classicCD(n);
    CD01->cd::setPrice(19.99);
    CD01->setComposer(c);

    CD01->print();

    return 0;
}

classicCD ::classicCD(char *n) {
    char nam = *n;
}

void classicCD ::setComposer(char *n){
    strcpy(composer, n);
}

void classicCD ::print(){
    cout << "name: " << getName() << endl;
    cout << "composer: " << composer << endl;
    cout << "price: " << getPrice << endl;
}
