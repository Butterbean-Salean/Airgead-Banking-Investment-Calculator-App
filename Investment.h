#pragma once
#ifndef INVESTMENT_H
#define INVESTMENT_H

/**
 * @class Investment
 * @brief Manages investment calculations and formatted report generation.
 */
class Investment {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_years;

    // Helper method to format monetary output nicely
    void printRow(int year, double endBalance, double interestEarned) const;

public:
    // Constructor
    Investment(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_years);

    // Getters
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetAnnualInterest() const;
    int GetYears() const;

    // Setters
    void SetInitialInvestment(double t_initialInvestment);
    void SetMonthlyDeposit(double t_monthlyDeposit);
    void SetAnnualInterest(double t_annualInterest);
    void SetYears(int t_years);

    // Calculation and Reporting Methods
    void PrintWithoutMonthlyDeposits() const;
    void PrintWithMonthlyDeposits() const;
};

#endif // INVESTMENT_H