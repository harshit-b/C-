// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: Simple Calculator
// FOR: CS 1412 Programming Principles II Section 002

#include <stdio.h>
#include <math.h>
void scan_data(char *,double *);

void do_next_op(double, char, double *);

int main(int argc, char **argv)
{
	double total=0,//The accumulated sum 
		   operand;//The nummber on which operation is to be performed
	char operator=' ';//To specify operation to be performed
	printf("Welcome to a simple Calculator\n");
	printf("The initial value is 0\n");
	printf("You can choose any of the following operators and enter the right operand leaving a space after the operator:\n");
	printf("+ addition\n");
	printf("- subtraction\n");
	printf("* multiply\n");
	printf("/ divide\n");
	printf("^ power(raise left operand to power of right operand)\n");
	printf("To quit press q0\n\n");
	do
	{
		printf("%.1f ",total);
		scan_data(&operator,&operand);
		do_next_op(operand,operator,&total);
		if ((operator!='q') && (operator!='Q'))
			printf("Result so far is %.1f\n\n",total);
	}while ((operator!='q') && (operator!='Q'));
	printf("Final result is %.1f\n",total);
	
}

void scan_data(char *operator, double *operand)
{
	// NAME: scan_data
	// INPUT PARAMETERS: Outut parameters to assign operator and operand values to the variables of calling function
	// OUTPUT: 
	// PURPOSE: Input operator and operand from user
	scanf(" %c%lf",operator, operand);
}

void do_next_op(double operand, char operator, double *total)
{
	// NAME: do_next_op
	// INPUT PARAMETERS: Two input parameter operator and operand and one output parameter total to assign the value of total to he calling function
	// OUTPUT: 
	// PURPOSE: Select the operation according to the operater and perform the operation and assign the value of total to the calling function
	switch (operator)
	{
		case '+': *total+=operand;
				  break;
		
		case '-': *total-=operand;
				  break;
				  
		case '*': *total*=operand;
				  break;
				  
		case '/': *total/=operand;
				  break;
				  
		case '^': *total=pow(*total,operand);
				  break;
				  
		case 'q': break;
		
		case 'Q': break;
		
		default: printf("You entered an invalid input\n");
	}
}
