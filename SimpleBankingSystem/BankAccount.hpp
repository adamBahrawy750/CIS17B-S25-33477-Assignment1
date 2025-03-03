#ifndef BankAccount_hpp
#define BankAccount_hpp

#include <string>

class BankAccount
{
    private:
    std::string accountHolderName; // Holds the name of the account holder
    std::string accountNumber; // Holds a randomly generated account number
    double balance; // Holds the account's balance
    
    public:
    // Constructor(s)
    BankAccount(); // Default constructor
    BankAccount(std::string setAccountHolderName, double setBalance); // Parameterized constructor
    
    // Accessor(s)
    std::string getName(); // Accessor for account holder name
    std::string getAccountNumber(); // Accessor for account number
    double getBalance(); // Accessor for balance
    
    // Misc. functions
    void depositInto(double addedAmount); // Deposits (adds) the specified amount to bank account
    void withdrawFrom(double takenAmount); // Withdraws (subtracts) the specified amount from bank account
    std::string generateAccountNumber(); // Generates a random 8-digit account number
};

#endif
