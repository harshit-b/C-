#include <stdio.h>
	// AUTHOR: Harshit Bhargava
	// FILENAME: main.c
	// SPECIFICATION: To calculate monthly payment for a car purchase
	// FOR: CS 1412 Programming Principles II Section 002
int main(int argc, char **argv)
{
	int i, //for loop iterator
		barcode[12], //integer array of size 12 with each element being a digit of the 12-digit barcode given by user
		odd_sum=0, //sum of the digits on odd positions in the 12 digit barcode
		even_sum=0, //sum of the digits on even positions in the 12 digit barcode
		result, //(odd_sum*3)+even_sum to obtain check_digit
		check_digit; //digit to check with the last digit of the barcode to check if barcode is valid or not
	printf("Enter the 12 digits of the barcode seperated by spaces: ");
	for (i=0;i<12;i+=1)
	{
		scanf("%d",&barcode[i]);
	}
	for (i=0;i<11;i+=1)
	{
		if ((i+1)%2!=0)
			odd_sum+=barcode[i];
		else
			even_sum+=barcode[i];
	}
	printf("Result from step 1: %d\n",odd_sum*3);
	result=(odd_sum*3)+even_sum;
	printf("Result from step 2: %d\n\n",result);
	if (result%10==0)
		check_digit=0;
	else
		check_digit=10-(result%10);
	for (i=0;i<12;i+=1)
	{
		printf("%d",barcode[i]);
	}
	printf(":  ");
	
	if (check_digit==barcode[11])
		printf("validated\n");
	else
		printf("error in barcode\n");
}
