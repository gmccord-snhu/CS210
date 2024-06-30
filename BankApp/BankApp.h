#ifndef BANKAPP_H
#define BANKAPP_H

#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

/*****************************************************************/
/**
 * \file   BankApp.h
 * \brief  CS 210 - Project 2
 *         Implements Airgead Banking application
 * \author Grant McCord
 * \date   June 2024
 *
 *********************************************************************/

/**
 * yearData structure
 */
struct yearData
{
	double year_total;
	double year_interest;
};

/**
 * Class BankApp
 * Contains all functions related to calculations for the bank.
 */
class BankApp
{
	public:
		static yearData compound_interest(double, double, int, double);
};

/**
 * Utility function to convert a double into a (2) precision
 * dollar string prepended with the $ sign.
 *
 * \param t_value the value to print
 * \return string representation in dollars
 */
std::string printDollars(double t_value) {
	std::stringstream stream;
	t_value = std::ceil(t_value * 100.0) / 100.0;	// round
	stream << "$" << std::fixed << std::setprecision(2) << t_value;
	return stream.str();
}

/**
 * Utility function to print centered text on a line.
 *
 * \param text text to print
 * \param lineLength line length
 */
void centerText(const std::string& t_text, int t_lineLength) {
	int padding = (t_lineLength - t_text.length()) / 2;
	std::cout << std::string(padding, ' ') << t_text << std::string(padding, ' ') << std::endl;
}

#endif // BANKAPP_H