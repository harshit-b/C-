#include<stdio.h>
	// AUTHOR: Harshit Bhargava
	// FILENAME: main.c
	// SPECIFICATION: To claculate weekly salary of different type of employees in a company
	// FOR: CS 1412 Programming Principles II Section 002
int main()
{
	int paycode=0, //code for specific type of worker
		status_paycode=0, //check if correct data type has been entered
		hours, //no. of hours worked by an hourly worker
		items, //no. of items made by a piecewise worker
		manager=0, //no. of managers 
		hourly_worker=0, //no. of hourly workers
		commision_worker=0, //no. of commision workers
		piece_worker=0; //no. of piecewise workers
		
	double manager_salary, //salary of manager to be entered
		   hourly_wage, //hourly wage of the hourly worker to be entered 
		   hw_pay, //calculated pay of hourly worker according to hours worked by the worker
		   weekly_sales, //weekly sales of the company
		   cw_pay, //calculated pay of commision worker
		   item_price, //price per piece
		   pw_pay; //calculated pay of piecewise worker
	
	do
	{
		printf("\nEnter paycode (-1 to end): ");
		status_paycode=scanf("%d",&paycode);
		if (status_paycode==0)
		{
			printf("You had to enter a no.\n");
			paycode=0;
			break;
			
		}
		
		else
		{
		switch (paycode)
		{
			case 1: 
				printf("Mangaer Selected\n");
				printf("Enter Weekly Salary: $");
				scanf("%lf",&manager_salary);
				printf("The manager's pay is: $%.2f\n",manager_salary);
				manager++;
				break;
			
			case 2:
				printf("Hourly Worker Selected\n");
				printf("Enter Hourly Wage: $");
				scanf("%lf",&hourly_wage);
				printf("Enter the number of hours worked: ");
				scanf("%d",&hours);
				if (hours>40)
					hw_pay=(40*hourly_wage)+((hours-40)*(1.5*hourly_wage));
				else
					hw_pay=hours*hourly_wage;
				printf("The hourly worker pay is: $%.2f\n",hw_pay);
				hourly_worker++;
				break;
			case 3:
				printf("Commision Worker Selected\n");
				printf("Enter the gross weekly sales: $");
				scanf("%lf",&weekly_sales);
				cw_pay=250+(0.057*weekly_sales);
				printf("Commision Worker's pay: $%.2f\n",cw_pay);
				commision_worker++;
				break;
			case 4:
				printf("Piecewise Worker Selected\n");
				printf("Enter the fixed amount of money for each item produced: $");
				scanf("%lf",&item_price);
				printf("Enter the no. of items produced: ");
				scanf("%d",&items);
				pw_pay=items*item_price;
				printf("The pieceworker's pay is $%.2f\n",pw_pay);
				piece_worker++;
				break;
			case -1:
				break;
			default:
				printf("Invalid paycode\n");
		}
		}
		
	}while (paycode!=-1);
	
	if (paycode==-1)
	{
		printf("\nTotal number of managers paid: %d\n",manager);
		printf("Total number of hourly workers paid: %d\n",hourly_worker);
		printf("Total number of commision workers paid: %d\n",commision_worker);
		printf("Total number of piece workers paid: %d\n",piece_worker);
	}
	
			
}

