#include<stdio.h>
	// AUTHOR: Harshit Bhargava
	// FILENAME: main.c
	// SPECIFICATION: To calculate monthly payment for a car purchase
	// FOR: CS 1412 Programming Principles II Section 002
#include<math.h>
int main(void)
{
	double price_car; // Price of the Car
	double down_payment; // Down Payment made by the user
	double principal; // Money borrowed : Price of the car - Down Payment
	double annual_rate; // Annual interest rate 
	double monthly_rate; // Monthly interest rate
	int num_of_payments; // Total number of payments
	double monthly_payment; // Amount to be paid per month
	double exponent; // extra variable to calculate (1+(monthly_rate))^-(num_of_payments)
	printf("Calculate Monthly Payment for a Car Purchase\n");
	printf("\nPrice of the Car => ");
	scanf("%lf",&price_car);
	printf("Enter your down payment  => ");
	scanf("%lf",&down_payment);
	principal=price_car-down_payment;
	printf("Please enter your annual interest rate => ");
	scanf("%lf",&annual_rate);
	monthly_rate=annual_rate/12;
	printf("Please enter your total number of payments => ");
	scanf("%d",&num_of_payments);
	exponent=pow(1+monthly_rate,num_of_payments);
	monthly_payment=(monthly_rate*principal)/(1-(1/exponent));
	printf("\nThe amount you borrowed is $ %.2lf\n",principal);
	printf("Your monthly payment is $ %.2lf\n",monthly_payment);
}