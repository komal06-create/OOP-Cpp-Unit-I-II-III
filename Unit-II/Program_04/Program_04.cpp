#include <iostream>      // Used for input and output (cout)
#include <string>        // Used for string data type
using namespace std;     // Allows us to use cout, string, etc. without std::

/*
    Base class: Account
    This class contains common details and operations
    for all types of bank accounts.
*/
class Account
{
protected:
    int accountNumber;       // Stores account number
    string holderName;      // Stores account holder's name
    double balance;         // Stores account balance

public:

    // Constructor to initialize account details
    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;   // Assign account number
        holderName = name;       // Assign account holder name
        balance = bal;           // Assign initial balance
    }

    // Function to deposit money into the account
    void deposit(double amount)
    {
        balance += amount;       // Add deposited amount to balance

        cout << "Deposited: Rs. " << amount << endl;
    }

    // Function to withdraw money from the account
    void withdraw(double amount)
    {
        // Check whether sufficient balance is available
        if (amount <= balance)
        {
            balance -= amount;   // Subtract withdrawal amount

            cout << "Withdrawn: Rs. " << amount << endl;
        }
        else
        {
            // Display message if balance is insufficient
            cout << "Insufficient balance." << endl;
        }
    }

    // Pure virtual function for calculating interest
    // Each derived class will provide its own implementation
    virtual double calculateInterest() const = 0;

    // Virtual function to display account information
    virtual void display() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() {}
};


/*
    SavingsAccount is derived from Account.
    It calculates interest at 4%.
*/
class SavingsAccount : public Account
{
public:

    // Constructor of SavingsAccount
    // Calls the constructor of Account
    SavingsAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    // Overrides the interest calculation function
    double calculateInterest() const override
    {
        return balance * 0.04;       // Calculate 4% interest
    }

    // Overrides display function
    void display() const override
    {
        cout << "\n--- Savings Account ---" << endl;

        // Display common account information
        Account::display();

        // Display calculated interest
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


/*
    CurrentAccount is derived from Account.
    In this example, it has 0% interest.
*/
class CurrentAccount : public Account
{
public:

    // Constructor of CurrentAccount
    CurrentAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    // Overrides interest calculation
    double calculateInterest() const override
    {
        return 0;       // Current account has no interest
    }

    // Overrides display function
    void display() const override
    {
        cout << "\n--- Current Account ---" << endl;

        // Display common account information
        Account::display();

        // Display calculated interest
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


/*
    FixedDepositAccount is derived from Account.
    It calculates interest at 7%.
*/
class FixedDepositAccount : public Account
{
public:

    // Constructor of FixedDepositAccount
    FixedDepositAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {}

    // Overrides the interest calculation function
    double calculateInterest() const override
    {
        return balance * 0.07;       // Calculate 7% interest
    }

    // Overrides display function
    void display() const override
    {
        cout << "\n--- Fixed Deposit Account ---" << endl;

        // Display common account information
        Account::display();

        // Display calculated interest
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Main function
int main()
{
    // Create a Savings Account object
    SavingsAccount savings(101, "Amit", 50000);

    // Create a Current Account object
    CurrentAccount current(102, "Sneha", 75000);

    // Create a Fixed Deposit Account object
    FixedDepositAccount fixedDeposit(103, "Rohan", 100000);

    // Display heading
    cout << "===== BANKING SYSTEM =====" << endl;

    // Deposit Rs. 5000 into savings account
    savings.deposit(5000);

    // Withdraw Rs. 2000 from savings account
    savings.withdraw(2000);

    // Deposit Rs. 10000 into current account
    current.deposit(10000);

    // Withdraw Rs. 5000 from current account
    current.withdraw(5000);

    // Deposit Rs. 20000 into fixed deposit account
    fixedDeposit.deposit(20000);

    // Display savings account details
    savings.display();

    // Display current account details
    current.display();

    // Display fixed deposit account details
    fixedDeposit.display();

    // End the program
    return 0;
}