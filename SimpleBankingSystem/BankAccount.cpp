#include "BankAccount.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

BankAccount::BankAccount() // Default constructor
{
    accountHolderName = "";
    accountNumber = generateAccountNumber();
    balance = 0;
}

BankAccount::BankAccount(std::string setAccountHolderName, double setBalance) // Parameterized constructor
{
    accountHolderName = setAccountHolderName;
    accountNumber = generateAccountNumber();
    balance = setBalance;
}

std::string BankAccount::getName() // Accessor for account holder name
{
    return accountHolderName;
}

std::string BankAccount::getAccountNumber() // Accessor for account number
{
    return accountNumber;
}

double BankAccount::getBalance() // Accessor method for balance
{
    return balance;
}

void BankAccount::depositInto(double addedAmount) // Deposits (adds) the specified amount to bank account
{
    balance += addedAmount;
}

void BankAccount::withdrawFrom(double takenAmount) // Withdraws (subtracts) the specified amount from bank account
{
    balance -= takenAmount;
}


std::string BankAccount::generateAccountNumber() // Generates a random 8-digit account number
{
    // Variable declaration(s)
    std::string newAccountNumber; // Holds the full randomly-generated account number
    std::string randDigit; // Holds each randomly generated digit to add to account number
    
    // Generates a random digit eight times, appending it to newAccountNumber at the end of each run
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int count = 0; count < 8; count++)
    {
        randDigit = std::to_string(rand() % 10);
        newAccountNumber.append(randDigit);
    }
    
    return newAccountNumber;
}
