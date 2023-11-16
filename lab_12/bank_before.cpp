#include <iostream>

////Create virtual class CurrencyConverter with virtual convertCurrency method that will accept
//// amount and conversionRate

////Create class CentralizedCurrencyConverter (based on CurrencyConverter)
//// implementing convertCurrency, that will return amount * conversionRate

// Module: Account
class Account {
public:
    double balance;

    Account(double initialBalance) : balance(initialBalance) {}

    // Original currency conversion logic in Module A
    double convertCurrency(double amount, double conversionRate) {
        return amount * conversionRate;
////instead of returning the expression, use currencyConverter pointer
//// to access to the method convertCurrency()
    }

    void displayBalance() {
        std::cout << "Account Balance: " << balance << std::endl;
    }
////Here we need the setter for the currency converter, receiving pointer
//// to object of class CurrencyConverter

////Here we need a private attribute: CurrencyConverter pointer to object
//// of class CurrencyConverter
};

// Module: Transaction
class Transaction {
public:
    // Original currency conversion logic in Module B
    double convertCurrency(double amount, double conversionRate) {
        return amount * conversionRate;
////instead of returning the expression, use currencyConverter pointer
//// to access to the method convertCurrency()
    }

    void displayTransactionAmount(double amount) {
        std::cout << "Transaction Amount: " << amount << std::endl;
    }
////Here we need the setter for the currency converter, receiving pointer
//// to object of class CurrencyConverter

////Here we need a private attribute: CurrencyConverter pointer to object
//// of class CurrencyConverter
};

// Client Code
int main() {
    Account userAccount(1000.0);
    Transaction transaction;

    double amountInUSD = 50.0;
    double conversionRateToEUR = 0.85;

    ////Here we need to create the object centralizedConverter
    //// from the class CentralizedCurrencyConverter

    ////We need to use the setters "setCurrentConverter" of userAccount
    //// and transaction, passing the reference to centralizedConverter.


    // Using currency conversion logic from Module A
    double amountInEUR_A = userAccount.convertCurrency(amountInUSD, conversionRateToEUR);
    userAccount.displayBalance();

    // Using currency conversion logic from Module B
    double amountInEUR_B = transaction.convertCurrency(amountInUSD, conversionRateToEUR);
    transaction.displayTransactionAmount(amountInEUR_B);

    return 0;
}
