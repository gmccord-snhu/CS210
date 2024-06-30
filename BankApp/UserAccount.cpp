/*****************************************************************/
/**
 * \file   UserAccount.cpp
 * \brief  CS 210 - Project 2
 *         Implements functions for UserAccount class
 * \author Grant McCord
 * \date   June 2024
 *
 *********************************************************************/
#include "UserAccount.h"

// ------ public accessors ------ // 

/**
 * \return The user account initial investment
 */
double UserAccount::GetInitialInvestment() const {
    return m_initialInvestmentAmount;
}

/**
 * \return The user account monthly deposit
 */
double UserAccount::GetMonthlyDeposit() const{
    return m_monthlyDeposit;
}

/**
 * \return The user account annual interest rate
 */
double UserAccount::GetAnnualInterestRate() const {
    return m_annualInterestRate;
}

/**
 * \return The number of years to profile
 */
int UserAccount::GetNumberOfYears() const {
    return m_numberOfYears;
}

// ------ public setters ------ // 

/**
 * Sets the user account initial investment
 * 
 * \param t_amt initial amount
 * \return true if amount is valid, otherwise false
 */
bool UserAccount::SetInitialInvestment(double t_amt) {
    if (t_amt >= 0) {
        m_initialInvestmentAmount = t_amt;
        return true;
    }
    return false;
}
 
/**
 * Sets the user account monthly deposit
 *
 * \param t_amt deposit amount
 * \return true if amount is valid, otherwise false
 */
bool UserAccount::SetMonthlyDeposit(double t_amt) {
    if (t_amt >= 0) {
        m_monthlyDeposit = t_amt;
        return true;
    }
    return false;
}

/**
 * Sets the user account annual interest rate
 *
 * \param t_date interest rate (0.05 for example)
 * \return true if amount is valid, otherwise false
 */
bool UserAccount::SetAnnualInterestRate(double t_rate) {
    if (t_rate >= 0 && t_rate <= 1) {
        m_annualInterestRate = t_rate;
        return true;
    }
    return false;
}

/**
 * Sets the user report preference for years displayed
 *
 * \param t_years the number of years to display
 * \return true if amount is valid, otherwise false
 */
bool UserAccount::SetNumberOfYears(int t_years) {
    if (t_years >= 0 && t_years < 100) {
        m_numberOfYears = t_years;
        return true;
    }
    return false;
}