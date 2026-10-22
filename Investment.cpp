#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constructor implementation initializing member variables
Investment::Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_years)
    : m_initialInvestment(t_initialInvestment),
    m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterest(t_annualInterest),
    m_years(t_years) {
}

// Getters
double Investment::GetInitialInvestment() const { return m_initialInvestment; }
double Investment::GetMonthlyDeposit() const { return m_monthlyDeposit; }
double Investment::GetAnnualInterest() const { return m_annualInterest; }
int Investment::GetYears() const { return m_years; }

// Setters
void Investment::SetInitialInvestment(double t_initialInvestment) { m_initialInvestment = t_initialInvestment; }
void Investment::SetMonthlyDeposit(double t_monthlyDeposit) { m_monthlyDeposit = t_monthlyDeposit; }
void Investment::SetAnnualInterest(double t_annualInterest) { m_annualInterest = t_annualInterest; }
void Investment::SetYears(int t_years) { m_years = t_years; }

// Helper for tabular alignment
void Investment::printRow(int year, double endBalance, double interestEarned) const {
    cout << setfill(' ') << right
        << setw(8) << year
        << setw(20) << fixed << setprecision(2) << endBalance
        << setw(28) << fixed << setprecision(2) << interestEarned << endl;
}

// Reports balance growth WITHOUT additional monthly deposits
void Investment::PrintWithoutMonthlyDeposits() const {
    cout << "=========================================================================\n";
    cout << "  Balance and Interest Without Additional Monthly Deposits               \n";
    cout << "=========================================================================\n";
    cout << "  Year      Year End Balance      Year End Earned Interest\n";
    cout << "-------------------------------------------------------------------------\n";

    double currentBalance = m_initialInvestment;
    double monthlyRate = (m_annualInterest / 100.0) / 12.0;

    for (int year = 1; year <= m_years; ++year) {
        double yearEarnedInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = currentBalance * monthlyRate;
            yearEarnedInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        printRow(year, currentBalance, yearEarnedInterest);
    }
    cout << endl;
}

// Reports balance growth WITH additional monthly deposits
void Investment::PrintWithMonthlyDeposits() const {
    cout << "=========================================================================\n";
    cout << "  Balance and Interest With Additional Monthly Deposits                  \n";
    cout << "=========================================================================\n";
    cout << "  Year      Year End Balance      Year End Earned Interest\n";
    cout << "-------------------------------------------------------------------------\n";

    double currentBalance = m_initialInvestment;
    double monthlyRate = (m_annualInterest / 100.0) / 12.0;

    for (int year = 1; year <= m_years; ++year) {
        double yearEarnedInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            currentBalance += m_monthlyDeposit; // Deposit made at start of month
            double monthlyInterest = currentBalance * monthlyRate;
            yearEarnedInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        printRow(year, currentBalance, yearEarnedInterest);
    }
    cout << endl;
}