#define max_accounts_number 100
#include <iostream>
#include <string.h>
using namespace std;

#define MAX_NAME_LEN 40

class BankAccount
{
protected:
    char name[MAX_NAME_LEN];
    int account_number;
    double balance;

public:
    BankAccount();
    BankAccount(char *);
    BankAccount(char *, int, double);
    void printSummary();
    double withdraw(double);
    void deposit(double);
    double getBalance();
    void setName(char *);
    void setAccount_number(int);
    void setbalance(double);
};

class saveBankAccount : public BankAccount
{ // inheritance of BankAccount
protected:
    double interestRate;
    int noWithDraws;
    int MAXnoWithDraws;

public:
    saveBankAccount(char *, int, double, double, int);
    void printSummary();
    double withdraw(double);
    void callInterest();
    void resetWithdraws();
    void transfer(saveBankAccount &acc, double);
};

int main(void)
{
    // Part 1 initial inputs
    char nTom[MAX_NAME_LEN] = "Tom";
    saveBankAccount tomAcc(nTom, 234567, 2000.00, 0.05, 1); // creating object tomAcc and usng constructors to initially store values
    tomAcc.printSummary();

    // The new opperations for Part 2
    tomAcc.deposit(1000);
    tomAcc.printSummary();

    tomAcc.withdraw(500);
    tomAcc.printSummary();

    tomAcc.withdraw(500);
    tomAcc.printSummary();

    cout << "Getting Balance...\n"
         << "Current Balance: $" << tomAcc.getBalance() << "\n"
         << endl;
    tomAcc.resetWithdraws(); // setting withdraw count to zero
    tomAcc.printSummary();

    tomAcc.withdraw(500);
    tomAcc.printSummary();

    tomAcc.callInterest();
    tomAcc.printSummary();

    char nEric[MAX_NAME_LEN] = "Eric";
    saveBankAccount ericAcc(nEric, 23454, 5000, 0.04, 1); // creating a new object

    ericAcc.printSummary();
    ericAcc.transfer(tomAcc, 1000);

    ericAcc.printSummary();
    tomAcc.printSummary();

    return 0;
}

//**********************************************
// class BankAccount: methods
//**********************************************
BankAccount ::BankAccount()
{
    name[0] = 0;
    account_number = 0;
    balance = 0.0;
}

BankAccount ::BankAccount(char *n)
{
    strcpy(name, n);
    account_number = 0;
    balance = 0.0;
}

BankAccount ::BankAccount(char *n, int a_no, double bal)
{
    strcpy(name, n);
    account_number = a_no;
    balance = bal;
}

void BankAccount ::printSummary()
{
    cout << "---------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
    cout << "---------------------" << endl;
}

double BankAccount ::withdraw(double toWD)
{
    if (balance - toWD > 0)
    {
        balance -= toWD;
    }
    else
    {
        cout << "!!!Sorry, not enough money!!!" << endl;
        return 0;
    }
    return toWD;
}

void BankAccount ::deposit(double toDep)
{
    cout << "Depositing...\n"
         << endl;
    balance += toDep;
}

double BankAccount ::getBalance()
{

    return balance;
}

void BankAccount ::setName(char *n)
{
    strcpy(name, n);
}

void BankAccount ::setAccount_number(int a_no)
{
    account_number = a_no;
}

void BankAccount ::setbalance(double bal)
{
    balance = bal;
}

//**********************************************
// class saveBankAccount: methods
//**********************************************

// Constructor
saveBankAccount ::saveBankAccount(char *n, int acc_num, double bal, double intRate, int MAXnoWith)
{
    //**********************************************
    // Setting values within the constructor based on the input parameters
    strcpy(name, n);
    account_number = acc_num;
    balance = bal;
    interestRate = intRate;
    MAXnoWithDraws = MAXnoWith;
    noWithDraws = 0;
    //**********************************************
}

// printing method
void saveBankAccount ::printSummary()
{
    cout << "Printing personal information..." << endl;
    cout << "---------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: $" << balance << endl;
    // These are the new values required for printing
    cout << "Interest Rate: " << interestRate << endl;
    cout << "# of Withdraws: " << noWithDraws << endl;
    cout << "Max # of Withdraws: " << MAXnoWithDraws << endl;
    cout << "---------------------" << endl;
    cout << "\n"
         << endl;
}

// withdraw
double saveBankAccount ::withdraw(double value)
{
    cout << "Withdrawing..." << endl;
    if (balance - value > 0 && MAXnoWithDraws > noWithDraws) // if there is enough money in the account and the user has enough withdraws remaining
    {
        balance = balance - value;
        noWithDraws++;
        cout << "New Balance: $" << balance << "\n"
             << endl;
        return value;
    }
    else if (balance - value < 0) // if the amount wanted is over the amount within the account
    {
        cout << "!!!Sorry, not enough money!!!" << endl;
        return 0;
    }
    else if (MAXnoWithDraws <= noWithDraws) // if the user does not have any withdrawls remaining
    {
        cout << "Account does not have anymore withdrawls \n"
             << endl;
        return 0;
    }
    return value;
}

// Interest calculation
void saveBankAccount ::callInterest()
{
    cout << "Calculating Interest..." << endl;
    double interest = interestRate * balance;
    balance = interest + balance;
    cout << "New Balance: $" << balance << "\n"
         << endl;
}

// Withdraw reset
void saveBankAccount ::resetWithdraws()
{
    noWithDraws = 0;
}

// Transfer
void saveBankAccount ::transfer(saveBankAccount &acc, double value)
{
    cout << "Transferring...\n"
         << endl;
    int withAmount = withdraw(value);
    if (withAmount > 0) // checking if the withdrawl amount is larger than zero, otherise the return statement would be zero if there was an error.
    {
        acc.deposit(withAmount);
    }
    else
    {
        cout << "Transfer unsuccessful.\n"
             << endl; // for the cases where the widthdraw didnt work
    }
}