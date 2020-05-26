// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To manage a database of flight records
// FOR: CS 1412 Programming Principles II Section 002

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_flight(int);
void delete_flight(int);
void update_flight(int);

typedef struct{
	int flight_number; //Flight number 
	char airline_code[2];//Airline code of the airline the flight is associated with
	char city_departure[50];
	char city_destination[50];
	int departure_time;
	int arrival_time;
	int departure_date;
	int arrival_date;
	int num_seats_fc_sold;//no. of seats sold in first class
	int num_seats_fc_available;//no. of seats available in first class
	int num_seats_coach_sold;//no. of coach seats sold
	int num_seats_coach_available;//no. of coach seats available
} flight_info_t;

int main(int argc, char **argv)
{
	int flight_count;//no. of flights in the database
	char userChoice;
	
	while (userChoice != 'Q') 
	{
        printf ("***************\n");
		printf("'A': Add flights\n");
        printf("'D': Delete a flight\n");
        printf("'U': Update a flight\n");
		printf("'Q': Quit\n");
        printf ("***************\n");
        printf ("Please enter a command: ");
        scanf("%s", &userChoice);  //Stores menu choice into variable userChoice
		
		
        if (userChoice == 'A')
		{
			printf("How many flights would you like to create: ");
			scanf("%i", &flight_count);
			create_flight(flight_count);
		}
        else if (userChoice == 'D')
            delete_flight(flight_count);
		else if (userChoice == 'U')
			update_flight(flight_count);
		else if (userChoice == 'Q') 
		{
            printf("The program will now quit.");
            return 0;
		}

	}
	
}

void 
create_flight(int flight_count)
{
	// NAME: create_flight
	// INPUT PARAMETERS: flight_count - no. of flights the user wants to store in the database
	// OUTPUT:
	// PURPOSE: creates records of flights in the database
	FILE* data;
	flight_info_t *flight_info; //Structure of the flight where flight information is stored

    flight_info = malloc(sizeof(flight_info_t) * flight_count);  

    int i;
    for (i = 0; i < flight_count; i++)
    {
        printf("Enter the flight number: ");
        scanf("%d", &flight_info[i].flight_number);

        printf("Enter the airline code: ");
        scanf(" %s", flight_info[i].airline_code);

        printf("Enter the city of departure: ");
        scanf(" %s", flight_info[i].city_departure);
		
		printf("Enter the destination: ");
        scanf(" %s", flight_info[i].city_destination);
		
		printf("Enter the departure time in 2400 hrs format: ");
        scanf("%d", &flight_info[i].departure_time);
		
		printf("Enter the departure date in the format MMDDYYYY: ");
        scanf("%d", &flight_info[i].departure_date);
		
		printf("Enter the arrival time in 2400 hrs format: ");
        scanf("%d", &flight_info[i].arrival_time);
		
		printf("Enter the arrival date in the format MMDDYYYY: ");
        scanf("%d", &flight_info[i].arrival_date);
		
		printf("Enter the number of seats available in first class: ");
        scanf("%d", &flight_info[i].num_seats_fc_available);
		
		printf("Enter the number of seats sold in first class: ");
        scanf("%d", &flight_info[i].num_seats_fc_sold);
		
		printf("Enter the number of seats available in coach: ");
        scanf("%d", &flight_info[i].num_seats_coach_available);
		
		printf("Enter the number of seats sold in coach: ");
        scanf("%d", &flight_info[i].num_seats_coach_sold);
		
    }
	
	
    if ( (data = fopen("flights.bin", "wb")) == NULL )
    {
        printf("Error opening file\n");
    }
	
	else
	{
		fwrite(flight_info, sizeof(flight_info_t) * flight_count, 1, data);
		fclose(data);
		
	}
	free(flight_info);
}

void 
delete_flight(int flight_count)
{
	// NAME: delete_flight
	// INPUT PARAMETERS: flight_count - no. of flights the user wants to store in the database
	// OUTPUT:
	// PURPOSE: deletes records of flights in the database
	FILE* data;
	int x = 0;
	int c=0;
    int flight_number;  // Temp string to compare to existing phonebook
    char airline_code[20];  //temp string

	if ((data = fopen("flights.bin", "rb")) == NULL)
    {
        printf("Error opening file\n");
    }
	
	else
	{
		flight_info_t *flight_info;
		flight_info=malloc(sizeof(flight_info_t));

		fread(flight_info, sizeof(flight_info) * flight_count, 1, data);

		fclose(data);
		
		printf("Enter the following details of the flight you want to delete");
		printf("\nEnter flight number: ");
		scanf("%d", &flight_number);
		printf("Enter airline code: ");
		scanf("%s", airline_code);

		for (x = 0; x < flight_count; x++)
		{
			if (flight_number==flight_info[x].flight_number)
			{
				for (x = 0; x < flight_count; x++)
				{
					if (strcmp(airline_code, flight_info[x].airline_code) == 0)
					{
						for (c = x - 1; c < flight_count - 1; c++)
							flight_info[c] = flight_info[c+1];
						flight_count--;
						break;
						printf("Flight Deleted Successfully");
					}
				}
				

			}
			else printf("Invalid entry--try again.\n");
		}
		free(flight_info);
		
	}
}

void 
update_flight(int flight_count)
{
	// NAME: create_flight
	// INPUT PARAMETERS: flight_count - no. of flights the user wants to store in the database
	// OUTPUT:
	// PURPOSE: updates records of flights in the database
	FILE* data;
	int x = 0;
    int flight_number;  // Temp string to compare to existing phonebook
    char airline_code[20];  //temp string

	if ((data = fopen("flights.bin", "rb")) == NULL)
    {
        printf("Error opening file\n");
    }
	
	else
	{
		flight_info_t *flight_info;
		flight_info=malloc(sizeof(flight_info_t));

		fread(flight_info, sizeof(flight_info) * flight_count, 1, data);

		fclose(data);
		
		printf("Enter the following details of the flight you want to update");
		printf("\nEnter flight number: ");
		scanf("%d", &flight_number);
		printf("Enter airline code: ");
		scanf("%s", airline_code);

		for (x = 0; x < flight_count; x++)
		{
			if (flight_number==flight_info[x].flight_number)
			{
				for (x = 0; x < flight_count; x++)
				{
					if (strcmp(airline_code, flight_info[x].airline_code) == 0)
					{
						printf("Enter the flight number: ");
						scanf("%d", &flight_info[x].flight_number);

						printf("Enter the airline code: ");
						scanf(" %s", flight_info[x].airline_code);

						printf("Enter the city of departure: ");
						scanf(" %s", flight_info[x].city_departure);
						
						printf("Enter the destination: ");
						scanf(" %s", flight_info[x].city_destination);
						
						printf("Enter the departure time in 2400 hrs format: ");
						scanf("%d", &flight_info[x].departure_time);
						
						printf("Enter the departure date in the format MMDDYYYY: ");
						scanf("%d", &flight_info[x].departure_date);
						
						printf("Enter the arrival time in 2400 hrs format: ");
						scanf("%d", &flight_info[x].arrival_time);
						
						printf("Enter the arrival date in the format MMDDYYYY: ");
						scanf("%d", &flight_info[x].arrival_date);
						
						printf("Enter the number of seats available in first class: ");
						scanf("%d", &flight_info[x].num_seats_fc_available);
						
						printf("Enter the number of seats sold in first class: ");
						scanf("%d", &flight_info[x].num_seats_fc_sold);
						
						printf("Enter the number of seats available in coach: ");
						scanf("%d", &flight_info[x].num_seats_coach_available);
						
						printf("Enter the number of seats sold in coach: ");
						scanf("%d", &flight_info[x].num_seats_coach_sold);
						
						printf("Flight Updated Successfully");
						
						break;

					}
				}
				

			}
			else printf("Invalid entry--try again.\n");
		}
		free(flight_info);
		
	}
}

