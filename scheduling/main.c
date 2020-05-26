#include <stdio.h>
#include "scheduling.h"

// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To schedule maintenance of aircrafts 
// FOR: CS 1412 Programming Principles II Section 002

#define MAX_CREW 3
#define MAX_MAINTENANCE 8

int main(int argc, char **argv)
{
	int number_crew, //The total number of crew that the user provides
		number_maintenance, //The total number of aircrafts that have to go for maintenance the user provides
		c, 
		i;
	char choice;
	crew_t crew[MAX_CREW]; //Array of structures of the crew
	maintenance_t maintenance[MAX_MAINTENANCE]; //array of structures of aircrafts for maintenance
	
	printf("Enter the total number of crews available(maximum is 3): "); //Assuming that the user will only enter the crew members that were given in the question
	scanf("%d",&number_crew);
	printf("Enter the total no. of aircrafts for maintainence(maximum is 8): ");//Assuming that the user will only enter the aircrafts that were given in the question
	scanf("%d",&number_maintenance); 
	
	scan_crew(&crew,number_crew);
	scan_maintenance(&maintenance,number_maintenance);
	
	printf("Do you want the cheapest way to get your work done? Enter 'y' for yes or 'n' for no: ");
	scanf(" %c",&choice);
	
	if (choice=='y')
	{
		for(i=0;i<number_maintenance;i++)
		{
			c=check_lowest_crew(maintenance[i]);
			crew[c].hours+=maintenance[i].hours;
			crew[c].id[crew[c].num]=maintenance[i].aircraft_id;
			crew[c].num+=1;
		}
	}
	else
	{
		for(i=0;i<number_maintenance;i++)
		{
			c=check_schedule_crew(maintenance[i],crew);
			crew[c].hours+=maintenance[i].hours;
			crew[c].id[crew[c].num]=maintenance[i].aircraft_id;
			crew[c].num+=1;
		}
	}
	
	print_crew(crew,number_crew);

	

	
}
