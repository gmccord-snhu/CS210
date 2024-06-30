#ifndef USERACCOUNT_H
#define USERACCOUNT_H
/*****************************************************************/
/**
 * \file   UserAccount.h
 * \brief  CS 210 - Project 2
 *         Definition of UserAccount class
 * \author Grant McCord
 * \date   June 2024
 *
 *********************************************************************/

/**
 * UserAccount class
 */
class UserAccount {

public:

	// ------ constructor, destructor ------ // 
	UserAccount() {};
	~UserAccount() {};

	// ------ public setters ------ // 
	bool SetInitialInvestment(double);
	bool SetMonthlyDeposit(double);
	bool SetAnnualInterestRate(double);
	bool SetNumberOfYears(int);

	// ------ public accessors ------ // 
	double GetInitialInvestment() const;
	double GetMonthlyDeposit()const;
	double GetAnnualRate()const;
	double GetAnnualInterestRate()const;
	int GetNumberOfYears()const;


	double getEndBalance(int) const;

private:

	double m_initialInvestmentAmount;
	double m_monthlyDeposit;
	double m_annualInterestRate;
	double m_numberOfYears;
};

#endif // USERACCOUNT_H
