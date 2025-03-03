#include "BankAccount.hpp"

#include <iostream>
#include <iomanip>

// Function prototype(s)
void createNewAccount(); // Creates a new account
void deposit(); // Deposits the specified amount into bank account
void withdraw(); // Withdraws the specified amount from bank account (if amount is valid)
void displayBalance(); // Displays the balance of bank account
void viewAccountDetails(); // Displays general details (name and account number) of bank account

// Global variable(s)
BankAccount* newAccount; // Pointer to BankAccount, used to allocate new BankAccount object when user creates their account

int main()
{
    // Variable declaration(s)
    int menuSelection; // To hold user's menu selection
    bool accountInUse = false; // Holds whether an account is currently being used (if one has been created already)
    
    // Welcome message
    std::cout << "Welcome to the Simple Banking System.";
    
    // do-while loop containing entire menu system, along with function calls for each menu option. Continuously repeats until user chooses to exit program
    do
    {
        // do-while loop handles menu output, and repeats if user enters invalid input
        do
        {
            try
            {
                std::cout << '\n' << '\n' << "Please select your desired action from the menu by enterring the number indicated by"
                << " the chosen option."
                << '\n' << "-----------------------"
                << '\n' << "1 - Create an account"
                << '\n' << "2 - Deposit money"
                << '\n' << "3 - Withdraw money"
                << '\n' << "4 - Check account balance"
                << '\n' << "5 - View account details"
                << '\n' << "6 - Exit Simple Bank System"
                << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin >> menuSelection;
                
                if (menuSelection < 1 || menuSelection > 6) // Throws upon invalid selection
                    throw ("Invalid input");
            }
            catch (...) // Outputs error message
            {
                std::cout << '\n' << '\n' << "Please make a valid selection.";
            }
        } while (menuSelection < 1 || menuSelection > 6);
        
        // switch statement initiating function calls based on user selection. No case for option 6, instead, do while loop ends completely as while condition
        // for "greater" do-while loop is fulfilled
        switch (menuSelection)
        {
            case 1:
                if (!accountInUse) // If account has not yet been created, account creation proceeds
                {
                    createNewAccount();
                    
                    accountInUse = true; // To signal moving forward that an account does already exist
                }
                else // Else, user is indicated that account exists and redirected to menu
                {
                    std::cout << '\n' << '\n' << "An account has already been created. Please proceed with the other options.";
                }
                break;
            case 2:
                if (accountInUse) // If account has been created, depositing proceeds
                    deposit();
                else // Else, user is indicated to first create an account
                    std::cout << '\n' << '\n' << "Please first create an account.";
                break;
            case 3:
                if (accountInUse) // If account has been created, withdrawal proceeds
                    withdraw();
                else // Else, user is indicated to first create an account
                    std::cout << '\n' << '\n' << "Please first create an account.";
                break;
            case 4:
                if (accountInUse) // If account has been created, displaying balance proceeds
                    displayBalance();
                else // Else, user is indicated to first create an account
                    std::cout << '\n' << '\n' << "Please first create an account.";
                break;
            case 5:
                if (accountInUse) // If account has been created, viewing account proceeds
                    viewAccountDetails();
                else // Else, user is indicated to first create an account
                    std::cout << '\n' << '\n' << "Please first create an account.";
                break;
        }
    } while (menuSelection != 6);
    
    // Clears out dynamically allocated BankAccount object if it has been allocated (if an account was created)
    if (accountInUse)
        delete newAccount;
    
    // Farewell message
    std::cout << '\n' << "Thank you for using the Simple Banking System!"
    << '\n';
    
    return 0;
}

void createNewAccount() // Creates a new account
{
    // Variable declaration(s)
    std::string newName; // Holds name inputted by user
    double newBalance; // Holds balance inputted by user
    bool validBalance = false; // Holds if balance inputted by user is valid, used for input validation
    
    // Retrieves name from user
    std::cout << '\n' << '\n' << "Please enter the name for the new account."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, newName);
    
    // Retrieves initial balance from user
    do
    {
        try
        {
            std::cout << '\n' << '\n' << "Please enter the initial balance for the new account."
            << '\n' << "-----------------------"
            << '\n' << "Enter here -> ";
            if (std::cin >> newBalance) // First if statement checks that value is numerical
            {
                if (newBalance >= 0) // Second if statement checks that value is positive
                    validBalance = true;
                else // Throws exception that initial balance is negative
                    throw ("Balance is negative.");
            }
            else // Throws exception that initial balance is not a number
            {
                throw ("Balance is not numerical.");
            }
        }
        catch (...) // Outputs error message
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << '\n' << '\n' << "Please enter a valid balance.";
        }
    } while (!validBalance);
        
    // Creates account with inputted details
    newAccount = new BankAccount{newName, newBalance};
    
    // Return message
    std::cout << '\n' << '\n' << "Account created. Returning to main menu...";
}

void deposit() // Deposits the specified amount into bank account
{
    // Variable declarations
    double depositAmount; // Holds amount user wishes to deposit
    
    // Retrieves amount user wishes to deposit
    std::cout << '\n' << "Please enter the amount you wish to deposit."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin >> depositAmount;
    
    // Deposits specified amount into account
    (*newAccount).depositInto(depositAmount);
    
    // Return message
    std::cout << '\n' << '\n' << "Deposit complete. Returning to main menu...";
}

void withdraw() // Withdraws the specified amount from bank account (if amount is valid)
{
    // Variable declarations
    double withdrawAmount; // Holds amount user wishes to withdraw
    
    // Retrieves amount user wishes to withdraw
    std::cout << '\n' << "Please enter the amount you wish to withdraw."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin >> withdrawAmount;
    
    // Checks if specified withdrawal amount is valid (i.e. if it's less than current account balance)
    if (withdrawAmount <= (*newAccount).getBalance())
    {
        // Withdraws specified amount from account
        (*newAccount).withdrawFrom(withdrawAmount);
        
        // Return message
        std::cout << '\n' << '\n' << "Withdrawal complete. Returning to main menu...";
    }
    else
    {
        // Indicates that account funds are insufficiet for withdrawal
        std::cout << '\n' << '\n' << "You have insufficient funds to withdraw this amount. Returning to main menu...";
    }
    
}

void displayBalance() // Displays the balance of bank account
{
    // Variable declaration(s)
    std::string dummySelection; // Simply holds whatever user inputs to progress forward
    
    // Output formatting
    std::cout << std::showpoint << std::fixed << std::setprecision(2);
    
    // Displays balance
    std::cout << '\n' << '\n' << "Below is your account's current balance. Please enter any key to return to the main menu."
    << '\n' << "-----------------------"
    << '\n' << "Balance: $" << (*newAccount).getBalance()
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin >> dummySelection;
    
    // Return message
    std::cout << '\n' << '\n' << "Returning to main menu...";
}

void viewAccountDetails() // Displays general details (name and account number) of bank account
{
    // Variable declaration(s)
    std::string dummySelection; // Simply holds whatever user inputs to progress forward
    
    // Displays account details
    std::cout << '\n' << '\n' << "Below are your account details. Please enter any key to return to the main menu."
    << '\n' << "-----------------------"
    << '\n' << "Name: " << (*newAccount).getName()
    << '\n' << "Accont Number: " << (*newAccount).getAccountNumber()
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin >> dummySelection;
    
    // Return message
    std::cout << '\n' << '\n' << "Returning to main menu...";
}
