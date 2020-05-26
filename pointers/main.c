#include <stdio.h>

// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To assist with calculation of intravenous rates of a hospital supply company
// FOR: CS 1412 Programming Principles II Section 002

int get_problem(void); //Function to display the user menu

void get_rate_drop_factor(double *,double *); //Function that inputs data from user for problem 1

void get_kg_rate_conc(double *,double *,double *); 

void get_units_conc(double *,double *); 

int fig_drops_min(double, double); 

int fig_ml_hr(int); 

int by_weight(double, double, double); 

int by_units(double, double);

int main()
{
	int choice, //Number corresponding the problem that the user wishes to solve
		hours, //The number of hours over which one liter is to be delivered
		result; //Result given by function corresponding to the problem selected by the user
	
	double rate, //Provided by user according to the problem selected
		   concentration, //Provided by user according to the problem selected
		   drop_factor, //Provided by user if problem 1 is selected in drops/ml
		   weight; //Patient's Weight in kg

	do
	{
		choice=get_problem();
		switch (choice)
		{
			case 1:
				get_rate_drop_factor(&rate,&drop_factor);
				result=fig_drops_min(rate,drop_factor);
				printf("The drop rate per minute is %d\n\n",result);
				break;
			case 2:
				printf("Enter number of hours for 1L=> ");
				scanf("%d",&hours);
				result=fig_ml_hr(hours);
				printf("\nThe rate in millilitres is %d\n\n",result);
				break;
			case 3:
				get_kg_rate_conc(&rate,&weight,&concentration);
				result=by_weight(rate,weight,concentration);
				printf("\nThe rate in millilitres is %d\n\n",result);
				break;
			case 4:
				get_units_conc(&rate,&concentration);
				result=by_units(rate,concentration);
				printf("\nThe rate in millilitres is %d\n\n",result);
				break;
			case 5:
				break;
			default:
				printf("\nInvalid Input!\n\n");
				break;
				
		} 
	
	}while (choice!=5);
	
}

int 
get_problem()
{
	// NAME: get_problem
	// INPUT PARAMETERS: No Input Parameters
	// OUTPUT: An integer, the number corresponding the problem the user wishes to solve
	// PURPOSE: Displays the user menu, then inputs and returns as the function value the problem number selected
	int choice; //The number corresponding to the problem that the user wishes to solve
	printf("Enter the number of the problem you wish to solve.\n");
	printf("\tGIVEN A MEDICAL ORDER IN		CALCULATE RATE IN\n");
	printf("(1) ml/hr & tubing drop factor			drops / min\n");
	printf("(2) 1 L for n hr				ml / hr\n");
	printf("(3) mg/kg/hr & concentration in mg/ml		ml/hr\n");
	printf("(4) units/hr & concentration in units/ml	ml / hr\n");
	printf("(5) QUIT\n\n");
	printf("Problem> ");
	scanf("%d",&choice);
	return choice;
}

void 
get_rate_drop_factor(double *ml_hr,double *drops_ml)
{
	// NAME: get_rate_drop_factor
	// INPUT PARAMETERS: double pointers *ml/hr and *drops_ml as output parameters to store data required for problem 1
	// OUTPUT: No output
	// PURPOSE: Prompts the user to enter the data required for problem 1, and sends this data back to the calling module via output parameters.
	printf("Enter rate in ml/hr=> ");
	scanf("%lf",ml_hr);
	printf("Enter tubing's drop factor(drops/ml)=> ");
	scanf(" %lf",drops_ml);
}

void
get_kg_rate_conc(double *mg_kg_hr,double *kg,double *mg_ml)
{
	// NAME: get_kg_rate_conc
	// INPUT PARAMETERS: double pointers *mg_kg_hr, *kg and *mg_ml as output parameters to store data required for problem 3
	// OUTPUT: No output
	// PURPOSE: Prompts the user to enter the data required for problem 1, and sends this data back to the calling module via output parameters.
	printf("Enter rate in mg/kg/hr=> ");
	scanf("%lf",mg_kg_hr);
	printf("Enter weight in kg=> ");
	scanf(" %lf",kg);
	printf("Enter concentration in mg/ml=> ");
	scanf(" %lf",mg_ml);
}

void
get_units_conc(double *units_hr,double *units_ml)
{
	// NAME: get_units_conc
	// INPUT PARAMETERS: double pointers *units/hr and *units_ml as output parameters to store data required for problem 4
	// OUTPUT: No output
	// PURPOSE: Prompts the user to enter the data required for problem 4, and sends this data back to the calling module via output parameters.
	printf("Enter rate in units/hr=> ");
	scanf("%lf",units_hr);
	printf("Enter concentration in units/ml=> ");
	scanf(" %lf",units_ml);
}

int 
fig_drops_min(double rate,double drop_factor)
{
	// NAME: fig_drops_min
	// INPUT PARAMETERS: two double type numbers, rate and drop_factor. Data required to calculate drops/min
	// OUTPUT: an integer drop_per_min
	// PURPOSE: Takes rate and drop factor as input parameters and returns drops/min (rounded to nearest whole drop) as function value.
	int drop_per_min;
	drop_per_min=(drop_factor*(rate/60))+0.5;
	return drop_per_min;
}

int
fig_ml_hr(int hours)
{
	// NAME: fig_ml_hr
	// INPUT PARAMETERS: An integer hours - the number of hours over which one liter is to be delivered. Data required to calculate ml/hour
	// OUTPUT: an integer ml_hr
	// PURPOSE: Takes as an input parameter the number of hours over which one liter is to be delivered and returns ml/hr (rounded) as function value.
	int ml_hr;
	ml_hr=(1000/hours)+0.5;
	return ml_hr;
}

int
by_weight(double rate,double weight, double conc)
{
	// NAME: by_weights
	// INPUT PARAMETERS: Three double type numbers: rate - rate in mg/kg/hr, weight - patient's weight in kg, conc - concentration of drug in mg/ml. Data required to calculate ml/hour
	// OUTPUT: an integer ml_hr
	// PURPOSE: Takes as input parameters rate in mg/kg/hr, patient weight in kg, and concentration of drug in mg/ml and returns ml/hr (rounded) as function value.
	int ml_hr;
	ml_hr=((rate*weight)/conc)+0.5;
	return ml_hr;
}

int
by_units(double rate,double conc)
{
	// NAME: by_units
	// INPUT PARAMETERS: Two double type numbers: rate - rate in units/hr, conc - concentration in units/ml. Data required to calculate ml/hour
	// OUTPUT: an integer ml_hr
	// PURPOSE: Takes as input parameters rate in units/hr and concentration in units/ml, and returns ml/hr (rounded) as function value
	int ml_hr;
	ml_hr=(rate/conc)+0.5;
	return ml_hr;
}


	

