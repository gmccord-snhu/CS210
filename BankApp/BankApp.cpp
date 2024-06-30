/*****************************************************************/
/**
 * \file   BankApp.cpp
 * \brief  CS 210 - Project 2
 *         Implements Airgead Banking application
 * \author Grant McCord
 * \date   June 2024
 *
 *********************************************************************/

#include "BankApp.h"
#include "UserAccount.h"

/**
 * Calculates yearly totals and accumulated interest for the year
 * 
 * \param t_principal principal
 * \param t_rate interest rate
 * \param t_time number of years to calculate
 * \param t_monthly_deposit the customer monthly deposit
 * 
 * Returns a yearData structure
 */
yearData BankApp::compound_interest(double t_principal, double t_rate, int t_time, double t_monthly_deposit) {
	
	// return struct
	yearData yeardata;

	// Convert annual rate to monthly rate
	double monthly_rate = t_rate / 12.0;

	// Calculate total amount
	double total_amount = t_principal;
	for (int i = 0; i < t_time; ++i) {
		double interest_earned_year = 0.0;
		for (int j = 0; j < 12; ++j) {
			total_amount += t_monthly_deposit;
			total_amount *= (1 + monthly_rate);
			interest_earned_year += (total_amount - t_monthly_deposit) * monthly_rate;
		}
		yeardata.year_total = total_amount;
		yeardata.year_interest = interest_earned_year;
	}

	// Return struct
	return yeardata;
}

/**
 * Reads input from screen into a user account.
 * 
 * \param t_userAccount the user account object
 */
void readInput(UserAccount & t_userAccount)
{
	double answer;
	
	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;

	// get initial investment amount
	do
	{
		cout << "Enter Initial Investment Amount: ";
		cin >> answer;
	} while (t_userAccount.SetInitialInvestment(answer) == false);

	// get monthly deposit
	do
	{
		cout << "Enter Monthly Deposit: ";
		cin >> answer;
	} while (t_userAccount.SetMonthlyDeposit(answer) == false);

	// get annual interest rate
	do
	{
		cout << "Enter Annual Interest Rate (as percentage): ";
		cin >> answer;
	} while (t_userAccount.SetAnnualInterestRate(answer) == false);

	// get number of years
	do
	{
		cout << "Enter Number of Years: ";
		cin >> answer;
	} while (t_userAccount.SetNumberOfYears(answer) == false);

	cout << "Press any key to continue...";
	
	// clear input buffer
	cin.ignore(); 

	// wait for user input
	cin.get();    
}

/**
 * Displays a user account report to the screen
 * 
 * \param t_userAccount UserAccount reference
 * \param t_monthly_deposit whether the report should use monthly desposits
 */
void displayReport(const UserAccount& t_userAccount, bool t_monthly_deposit)
{
	double deposit = 0;
	if (t_monthly_deposit) {
		centerText("Balance and Interest With Additional " + printDollars(t_userAccount.GetMonthlyDeposit()) + " Monthly Deposits", 80);
		deposit = t_userAccount.GetMonthlyDeposit();
	}
	else {
		centerText("Balance and Interest Without Additional Monthly Deposits", 80);
	}
	cout << setfill('=') << setw(80) << '=' << endl;
	cout << setfill(' ') << left << setw(28) << "Year" << "Year End Balance" << right << setw(30) << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;

	for (int year = 1; year <= t_userAccount.GetNumberOfYears(); ++year) {

		// Calculate year
		yearData yd = BankApp::compound_interest(t_userAccount.GetInitialInvestment(), t_userAccount.GetAnnualInterestRate(), year, deposit);
		
		// Print line
		cout << setfill(' ') << right << setw(4) << to_string(year);
		cout << setfill(' ') << right << setw(40) << printDollars(yd.year_total);
		cout << setfill(' ') << right << setw(30) << printDollars(yd.year_interest);
		cout << endl;
	}
	cout << setfill('=') << setw(80) << '=' << endl;
}

/**
 * Main routine
 *
 * \return 0 or 1
 */
int main()
{
	UserAccount ua;
	try
	{
		// loop until user decides to exit
		while (true)
		{
			readInput(ua);
			displayReport(ua, false);
			displayReport(ua, true);
			break;
		}
	}
	catch (const exception& e) {
		cerr << "An unexpected error occurred: " << e.what() << endl;
		return 1;
	}

	return 0;
}