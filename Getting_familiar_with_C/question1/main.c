#include <stdio.h>
	// AUTHOR: Harshit Bhargava
	// FILENAME: main.c
	// SPECIFICATION: To calculate mileage reimbursement
	// FOR: CS 1412 Programming Principles II Section 002
#define RATE_PER_MILE 0.35
int main(void)
{
	double beg_odo_reading; // Odometer reading at the beginning
	double end_odo_reading; // Odometer reading at the end
	double dif_reading; // Deifference between the end and beginning odometer reading
	double reimbursement; // Mileage reimbursement
	printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
	printf("Enter beginning odometer reading => ");
	scanf("%lf",&beg_odo_reading);
	printf("Enter ending odometer reading => ");
	scanf("%lf",&end_odo_reading);
	dif_reading=end_odo_reading-beg_odo_reading;
	reimbursement=dif_reading*RATE_PER_MILE;
	printf("You traveled %lf miles. At $0.35 per mile, your reimbursement is $ %lf.\n",dif_reading,reimbursement);
	return 0;
}
