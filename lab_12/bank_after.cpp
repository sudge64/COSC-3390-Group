#include <iostream>
class CentralizedCurrencyConverter {
public:
    static double convertCurrency(double amount, double conversionRate) {
        return amount * conversionRate;
        ////instead of returning the expression, use currencyConverter pointer
        //// to access to the method convertCurrency()
    }
};

// Module: Account
class Account {
public:
    double balance;

    Account(double initialBalance) : balance(initialBalance) {
    }

    double convertCurrency(double amount, double conversionRate) {
        return CentralizedCurrencyConverter::convertCurrency(amount, conversionRate);
    }

    void displayBalance() {
        std::cout << "Account Balance: " << balance << std::endl;
    }
};

// Module: Transaction
class Transaction {
public:
    double convertCurrency(double amount, double conversionRate) {
        return CentralizedCurrencyConverter::convertCurrency(amount, conversionRate);
    }

    void displayTransactionAmount(double amount) {
        std::cout << "Transaction Amount: " << amount << std::endl;
    }
};

// Client Code
int main() {
    Account userAccount(1000.0);
    Transaction transaction;
    double amountInUSD = 50.0;
    double conversionRateToEUR = 0.85;

    // Using currency conversion logic from Module A
    double amountInEUR_A = userAccount.convertCurrency(amountInUSD, conversionRateToEUR);
    userAccount.displayBalance();

    // Using currency conversion logic from Module B
    double amountInEUR_B = transaction.convertCurrency(amountInUSD, conversionRateToEUR);
    transaction.displayTransactionAmount(amountInEUR_B);

    return 0;
}
