#include<stdio.h>
	// AUTHOR: Harshit Bhargava
	// FILENAME: main.c
	// SPECIFICATION: To generate a reciept in a music shop
	// FOR: CS 1412 Programming Principles II Section 002
#define SALES_TAX 5.0
int main(void)
{
	double purchase; //The purchase amount 
	double discount_amount; //Discount ammount that will be duducted from purchase
	double discounted_total; //Amount after deducting the discount
	double tax_amount; //The tax amount that will be added 
	double final_price; //Final price after adding tax and dedcting discount
	char purchaser; //To determine if the purchaser is a teacher or not 
	double discount; //Discount that will applied to the purchase
	
	printf("Please enter the total purchase: $");
	scanf("%lf",&purchase);
	printf("Press 't' if the purchaser is a teacher else press 'n': ");
	scanf(" %c",&purchaser);
	
	if(purchaser=='t' || purchaser=='T')
	{
		if(purchase>100)
			discount=12;
		else
			discount=10;
	}
	else
		discount=0;
	
	discount_amount=(discount/100)*purchase;
	discounted_total=purchase-discount_amount;
	tax_amount=(SALES_TAX/100)*discounted_total;
	final_price=tax_amount+discounted_total;
	
	printf("\nTotal purchases			$ %.2f\n",purchase);
	if (discount!=0)
	{
	printf("Teacher's discount (%.1f%%)	$ %.2f\n",discount,discount_amount);
	printf("Discounted Total		$ %.2f\n",discounted_total);
	}
	printf("Sales Tax (%.1f%%)		$ %.2f\n",SALES_TAX,tax_amount);
	printf("Total				$ %.2f\n\n",final_price);
}