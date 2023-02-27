#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu();
void displayBalanceWithDeposits(float initialInvestment, float monthlyDeposit, float annualInterest, float years);
void displayBalanceWithNoDeposits(float initialInvestment, float monthlyDeposit, float annualInterest, float years);
void printDetails(float year, float totalAmount, float interestEarned);

int main() {
	//Declare variables for input
	float initialInvestment, monthlyDeposit, annualInterest, months, years;

	displayMenu();

	//Get user input
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $" << endl;
	cin >> initialInvestment;
	cout << "Monthly Deposit: $" << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest: %" << endl;
	cin >> annualInterest;
	cout << "Number of years: " << endl;
	cin >> years;
	months = years * 12;

	system("PAUSE");

	displayBalanceWithNoDeposits(initialInvestment, monthlyDeposit, annualInterest, years);

	displayBalanceWithDeposits(initialInvestment, monthlyDeposit, annualInterest, years);


	return 0;
}

void  displayMenu()
{
	//Display menu to the user
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	//Press any key to continue command
	system("PAUSE");
}


void displayBalanceWithDeposits(float initialInvestment, float monthlyDeposit, float annualInterest, float years)
{

	float totalAmount, interestAmount, yearlyTotalInterest;

	//Calculate monthly interest and month end total
	totalAmount = initialInvestment;

	//Display year end data with monthly deposits
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Calculate yearly interest and year end total
	for (int i = 0; i < years; i++) {
		//Initialize yearly interest to 0
		yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			//Calculate monthly interest amount
			interestAmount = (((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12);

			//Calculate month end interest
			yearlyTotalInterest = yearlyTotalInterest + interestAmount;

			//Calculate month end total
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyTotalInterest << endl;
	}
}

void displayBalanceWithNoDeposits(float initialInvestment, float monthlyDeposit, float annualInterest, float years)
{
	float totalAmount, interestAmount, yearlyTotalInterest;

	//Calculate monthly interest and month end total
	totalAmount = initialInvestment;

	//Display year end data if no monthly deposits
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Calculate yearly interest and year end total
	for (int i = 0; i < years; i++) {
		//Calculate yearly interest amount
		interestAmount = ((totalAmount) * (annualInterest / 100));

		//Calculate year end total
		totalAmount = totalAmount + interestAmount;

		//Show decimal as dollar amount correctly with set precision to 2 decimal places
		printDetails((i + 1), totalAmount, interestAmount);
	}
}

void printDetails(float year, float totalAmount, float interestEarned)
{
	cout << year << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestEarned << endl;
}