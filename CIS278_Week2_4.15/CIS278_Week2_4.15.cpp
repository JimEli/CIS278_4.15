/*************************************************************************
* Title: Sale-Commission Calculator 
* File: CIS278_Week2_4.15.cpp
* Author: James Eli
* Date: 1/18/2018
*
* A large company pays its salespeople on a commission basis. The 
* salespeople each receive $200 per week plus 9% of their gross sales for 
* that week. For example, a salesperson who sells $5000 worth of chemicals 
* in a week receives $200 plus 9% of $5500, or a total of $650. Develop a 
* C++ program that uses a while statement to input each salesperson’s gross 
* sales for last week and calculates and displays that salesperson’s 
* earnings. Process one salesperson’s figures at a time.
*
*   Enter sales in dollars (-1 to end): 5000.00
*   Salary is $650.00
*
*   Enter sales in dollars (-1 to end): 6000.00
*   Salary is $740.00
*
*   Enter sales in dollars (-1 to end): 7000.00
*   Salary is $830.00
*
*   Enter sales in dollars (-1 to end): -1
*
* Notes:
* (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/18/2018: Initial release. JME
*************************************************************************/
#include <iostream>  // cin/cout/endl
#include <iomanip>   // setprecision
#include "input.cpp" // numeric input routines

int main() 
{
	while (true) 
	{
		// Employee gross sales.
		double sales = { 0.0 };
		// Base pay for comissioned employee.
		const double BASE_PAY = { 200.00 };
		// Commission percentage.
		const double COMMISSION_PERCENTAGE = { 0.09 };

		// Attempt to get gross sales input.
		if (!getNumber<double>("Enter sales in dollars (-1 to end): ", sales, -1., 100000.))
			break;
		// Exit upon sentinel value.
		if (sales == -1)
			break;
		// Ensure gross sales is not negative.
		if (sales < 0.0) {
			std::cout << "Sales cannot be less than 0.\n";
			sales = 0.0;
		}
		else 
		{
			// Calculate salary and display.
			double salary = BASE_PAY + (COMMISSION_PERCENTAGE * sales);
			std::cout << "Salary is " << std::fixed << std::setprecision(2) << salary << "\n\n";
		}
	}

	return 0;
}