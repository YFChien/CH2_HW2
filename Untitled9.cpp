#include <stdio.h>
#include <stdlib.h>

int main()
{
	int payCode;


	double pay; 
	double totalPay = 0;
	int countManagers = 0;
	int countHourlyWorkers = 0;
	int countCommissionWorkers = 0;
	int countPieceworkers = 0;

	const int WEEKS_PER_YEAR = 52;				
	double salary;

	const int HOURS_PER_WEEK_THRESHOLD = 40;		
	const double OVERTIME_MULTIPLIER = 1.5; 
	double hourlyRate;
	double hoursWorked;
	double overtimeHours;
	
	const double COMMISSION_BASE = 250;
	const double COMMISSION_MULTIPLIER = .057; 
	double grossWeeklySales;

	double numberPieces;
	double wagePerPiece;


	do
	{
		// print menu
		puts("");
		puts("Select type of Employee from menu");
		puts("1. Manager/Salary");
		puts("2. Hourly Worker");
		puts("3. Commission Worker");
		puts("4. Pieceworker");
		printf("%s", "Enter paycode (-1 to end): ");

		// user chooses type of employee
		scanf("%d", &payCode);

		// switch will decide which type the user chose
		switch (payCode)
		{
			// manager
			case 1:
				// reset variables
				pay = salary = 0;

				// prompt the user for necessary values
				puts("");
				puts("Manager selected.");
				printf("%s", "Enter the yearly salary: $");
				scanf("%lf", &salary);

				pay = salary / WEEKS_PER_YEAR;

				// output
				printf("Manager's weekly pay is $%.2lf", pay);

				countManagers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// hourly
			case 2:
				// reset variables
				pay = hourlyRate = hoursWorked = overtimeHours = 0;

				// prompt the user for necessary values
				puts("");
				puts("Hourly worker selected.");
				printf("%s", "Enter the hourly rate: $");
				scanf("%lf", &hourlyRate);
				printf("%s", "Enter the total hours worked: ");
				scanf("%lf", &hoursWorked);
				
				if (hoursWorked > HOURS_PER_WEEK_THRESHOLD)
				{
					overtimeHours = hoursWorked - HOURS_PER_WEEK_THRESHOLD; // anything over the threshold
					hoursWorked = HOURS_PER_WEEK_THRESHOLD; // we know they are at least at the threshold
				}

				
				pay = (hourlyRate * hoursWorked) + (hourlyRate * overtimeHours * OVERTIME_MULTIPLIER);
				printf("Worker's pay this week is $%.2lf", pay);

				countHourlyWorkers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// commission
			case 3:
				// reset variables
				pay = grossWeeklySales = 0;

				// prompt the user for necessary values
				puts("");
				puts("Commission worker selected.");
				printf("%s", "Enter the gross weekly sales: $");
				scanf("%lf", &grossWeeklySales);

				// the pay can be calculated with this one line
				pay = COMMISSION_BASE + (grossWeeklySales * COMMISSION_MULTIPLIER);

				// output
				printf("Worker's pay this week is $%.2lf", pay);

				countCommissionWorkers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// piecework
			case 4:
				// reset variables
				pay = numberPieces = wagePerPiece = 0;

				// prompt the user for necessary values
				puts("");
				puts("Pieceworker selected.");
				printf("%s", "Enter the number of pieces: ");
				scanf("%lf", &numberPieces);
				printf("%s", "Enter the wage per piece: $");
				scanf("%lf", &wagePerPiece);

				// the pay can be calculated with this one line
				pay = numberPieces * wagePerPiece;

				// output
				printf("Worker's pay this week is $%.2lf", pay);

				countPieceworkers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// exit the menu
			case -1:
				break;

			// input not recognized
			default:
				puts("Invalid pay code.");
				break;
		}
	}
	// loop until user chooses to end
	while(payCode != -1);

	/**
	 * Output Totals
	 * these are the variables we have been tracking through the whole program
	 */
	puts("");
	printf("Number of Employees:\t\t\t\t%d\n",
			countManagers
			+ countHourlyWorkers
			+ countCommissionWorkers
			+ countPieceworkers
		);
	printf("Total number of managers paid:\t\t\t%d\n", countManagers);
	printf("Total number of hourly workers paid:\t\t%d\n", countHourlyWorkers);
	printf("Total number of commission workers paid:\t%d\n", countCommissionWorkers);
	printf("Total number of pieceworkers paid:\t\t%d\n", countPieceworkers);
	printf("Total value paid:\t\t\t$%.2lf\n", totalPay);
}

