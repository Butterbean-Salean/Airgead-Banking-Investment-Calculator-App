#include <iostream>
#include <limits>
#include <string>
#include "Investment.h"

using namespace std;

// Robust validation method to prevent crash from non-numeric or out-of-bound inputs
double GetValidDoubleInput(const string& prompt) {
    double input;
    while (true) {
        cout << prompt;
        if (cin >> input && input >= 0) {
            return input;
        }
        cout << "Invalid entry. Please enter a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int GetValidIntInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        if (cin >> input && input > 0) {
            return input;
        }
        cout << "Invalid entry. Please enter a whole number greater than 0.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    char userChoice = 'y';

    while (userChoice == 'y' || userChoice == 'Y') {
        cout << "**********************************\n";
        cout << "********** Data Input ************\n";

        double initialInvestment = GetValidDoubleInput("Initial Investment Amount: $");
        double monthlyDeposit = GetValidDoubleInput("Monthly Deposit: $");
        double annualInterest = GetValidDoubleInput("Annual Interest (%): ");
        int years = GetValidIntInput("Number of years: ");

        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        // Instantiate domain object
        Investment userInvestment(initialInvestment, monthlyDeposit, annualInterest, years);

        cout << "\n";
        userInvestment.PrintWithoutMonthlyDeposits();
        userInvestment.PrintWithMonthlyDeposits();

        cout << "Would you like to run another scenario? (y/n): ";
        cin >> userChoice;
        cout << endl;
    }

    cout << "Thank you for using the Airgead Banking App!\n";
    return 0;
}