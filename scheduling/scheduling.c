/* scheduling.c
 *
 * abstract data type crew
 * abstract data type maintenance
 *
 * Type planet_t has these components:
 * int number, int skill, int cost_hour, int hours, int num, int id[AIRCRAFT_IDS];
 *
 * Operators:
 * scan_crew, check_lowest_crew, check_schedule_crew, scan_maintenance, crew_hours
*/

// AUTHOR: Harshit Bhargava
// FILENAME: scheduling.h
// SPECIFICATION: implemntation file for personal library for scheduling
// FOR: CS 1412 Programming Principles II Section 002

#include <stdio.h>
#include "scheduling.h"

void
print_crew(crew_t crew[], int number_crew)
{
	// NAME: print_crew
	// INPUT PARAMETERS: int number_crew - total number of crew 
					   //crew_t  crew[] - array of structures which stores information of all crews
	// OUTPUT: 
	// PURPOSE: Display all information in structure
	int i,j;
	for(i=0;i<number_crew;i++)
	{
		printf("\nCrew Number(0 or 1 or 2): %d\n",crew[i].number);
		printf("Skill Level: %d\n",crew[i].skill);
		printf("Cost of Crew Per Hour: %d\n",crew[i].cost_hour);
		printf("Hours the crew is assigned: %d\n",crew[i].hours);
		printf("Following are the AIRCRAFT IDs which the crew has been assigned to: \n");
		for(j=0;j<crew[i].num;j++)
			printf(" %d, ",crew[i].id[j]);
		printf("\n");
	}
	
}
/*
* Checks maintenance level required against the crew abilities and returns the number of the lowest-cost
* crew that can perform the maintenance. 
*/

void
print_maintenance(maintenance_t maintenance[], int number_maintenance) /* input - one crew structure */
{
	// NAME: print_maintenance
	// INPUT PARAMETERS: int number_crew - total number of aircrafts for maintenance; maintenance_t  maintenance[] - array of structures which stores information of all aircrafts for maintenance
	// OUTPUT: 
	// PURPOSE: Display all information in structure
	int i;
	for(i=0;i<number_maintenance;i++)
	{
		printf("\nAircraft ID: %d\n",maintenance[i].aircraft_id);
		printf("Level of maintenance: %d\n",maintenance[i].level);
		printf("Number of hours required: %d\n",maintenance[i].hours);
	}
}


int
check_lowest_crew(maintenance_t maintenance) /* input - maintenance */
{
	// NAME: check_lowest_crew
	// INPUT PARAMETERS:maintenance_t  maintenanceb- structures which stores information of aircraft for maintenance
	// OUTPUT: 
	// PURPOSE: Checks maintenance level required against the crew abilities and returns the number of the lowest-cost crew that can perform the maintenance. 
	if (maintenance.level==3)
		return 2;
	
	else if(maintenance.level==2)
		return 1;
	
	else if(maintenance.level==1)
		return 0;
	else
		return -1;
}

int
check_schedule_crew(maintenance_t maintenance, crew_t crew[]) /* input - maintenance*/
{
	// NAME: check_schedule_crew
	// INPUT PARAMETERS:maintenance_t  maintenanceb- structures which stores information of aircraft for maintenance
	// OUTPUT: 
	// PURPOSE: checks the maintenance level required against the crew abilities and current schedule and returns the number of the qualified crew that will be free to perform the maintenance at the earliest time. If more than one crew
	//          satisfies the function’s constraints, the number of the lowest-cost qualified crew is returned
	if (maintenance.level==3)
		return 2;
	else if (maintenance.level==2)
	{
		if (crew[2].hours<16)
			return 2;
		else
			return 1;
	}
	else
	{
		if (crew[2].hours<16)
			return 2;
		else if (crew[1].hours<16)
			return 1;
		else
			return 0;
	}
}

/*
*  Integer returned as
* function result is success/failure/EOF indicator.
* 1 => successful input of planet
* 0 => error encountered
* EOF => insufficient data before end of file
* In case of error or EOF, value of type maintenance_t output argument is
* undefined.
*/
void
scan_maintenance(maintenance_t *maintenance, int number_maintenance) /* output - address of planet_t structure to fill */
{
	// NAME: scan_maintenance
	// PARAMETERS: int number_maintenance - total number of aircrafts for maintenance; maintenance_t  *maintenance[] - array of structures which stores information of all aircrafts for maintenance
	// OUTPUT: 
	// PURPOSE: Fills a type maintenence_t structure with input data.

	int i,result=0,value;
	for (i=0;i<number_maintenance;i++)
	{
		printf("Enter the aircraft id that needs to be worked upon: ");
		result=scanf("%d",&value);
		if (result!=0)
		{
			if (value==7899)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=1;
				maintenance[i].hours=8;
			}
			else if (value==3119)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=1;
				maintenance[i].hours=6;
			}
			else if (value==7668)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=1;
				maintenance[i].hours=4;
			}
			else if (value==2324)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=2;
				maintenance[i].hours=4;
			}
			else if (value==1123)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=2;
				maintenance[i].hours=8;
			}
			else if (value==7555)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=2;
				maintenance[i].hours=4;
			}
			else if (value==6789)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=3;
				maintenance[i].hours=2;
			}
			else if (value==7888)
			{
				maintenance[i].aircraft_id=value;
				maintenance[i].level=3;
				maintenance[i].hours=10;
			}
			else
				printf("Invalid Input");
			
		}
		else
			printf("Invalid Input");
	}
}


void
scan_crew(crew_t *crew, int total_crew) /* output - address of crew_t structure to fill */
{
	// NAME: scan_maintenance
	// PARAMETERS: int total_ - total number of aircrafts for maintenance; maintenance_t  *maintenance[] - array of structures which stores information of all aircrafts for maintenance
	// OUTPUT: 
	// PURPOSE: Fills a type maintenence_t structure with input data.
	int i,result=0,value;
	for (i=0;i<total_crew;i++)
	{
		printf("Enter the crew number: ");
		result=scanf("%d",&value);
		if (result!=0)
		{
			if (value==0)
			{
				crew[i].number=value;
				crew[i].skill=1;
				crew[i].cost_hour=200;
				crew[i].hours=0;
				crew[i].num=0;
			}
			else if (value==1)
			{
				crew[i].number=value;
				crew[i].skill=2;
				crew[i].cost_hour=300;
				crew[i].hours=0;
				crew[i].num=0;
			}
			else if (value==2)
			{
				crew[i].number=value;
				crew[i].skill=3;
				crew[i].cost_hour=400;
				crew[i].hours=0;
				crew[i].num=0;
			}
			else
				printf("Invalid Input");
			
		}
		else
			printf("Invalid Input");
	}
}