#include<stdio.h>
	// AUTHOR: Harshit Bhargava
	// FILENAME: main.c
	// SPECIFICATION: To claculate 1/2 life of cobalt every year for next 5 years
	// FOR: CS 1412 Programming Principles II Section 002
#include<math.h>
#define HALF_LIFE 5.2727
#define C pow(2.71828,-0.693)
int main(void)
{
	double init_amount; //Initial amount of cobalt
	printf("Please enter the amount of the isotope cobalt-60 : ");
	scanf("%lf",&init_amount);
	printf("\n------------------------------------\n");
	printf("Years Elapsed		Amount Left \n");
	printf("    1		 	 %f\n",init_amount*pow(C,(1/HALF_LIFE)));
	printf("    2		 	 %f\n",init_amount*pow(C,(2/HALF_LIFE)));
	printf("    3		 	 %f\n",init_amount*pow(C,(3/HALF_LIFE)));
	printf("    4		 	 %f\n",init_amount*pow(C,(4/HALF_LIFE)));
	printf("    5		 	 %f\n",init_amount*pow(C,(5/HALF_LIFE)));
	printf("-------------------------------------\n");
}