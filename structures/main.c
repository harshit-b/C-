#include <stdio.h>
#include <ctype.h>
#define CURRENT_YEAR 2020

// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To scan and store information of patients in a hospital
// FOR: CS 1412 Programming Principles II Section 002

typedef struct{
	int month; //month of the date of the birth of the patient
	int day; //day of the date of the birth of the patient
	int year; //year of the date of the birth of the patient 
}dob_t; 

typedef struct{
	char first_name[100]; //first name of the patient
	char last_name[100]; //last name of the patient
	char gender[30]; //gender of the patient
	dob_t dob; //date of birth of the patient
	double height; //height of the patient
	double weight; //weight of the patient
}healthProfile_t;

void set_data(healthProfile_t *healthProfile);
void bmi_values();
void health(healthProfile_t healthProfile);
void heart_rate(int );

int main(int argc, char **argv)
{
	healthProfile_t healthProfile;
	set_data(&healthProfile);
	health(healthProfile);
	bmi_values();

	
}

void set_data(healthProfile_t *healthProfile)
{
	// NAME: set_data
	// INPUT PARAMETERS: 
	// OUTPUT: healthProfile_t *health_profile-> health profile of the patient
	// PURPOSE: To scan and store information of the product in a the structure healthProfile_t
	printf("Enter the patient's first name: ");
	scanf(" %s",&healthProfile->first_name);
	printf("Enter the patient's last name: ");
	scanf(" %s",&healthProfile->last_name);
	printf("Enter the patient's gender: ");
	scanf(" %s",&healthProfile->gender);
	printf("Enter the patient's date of birth in the format (MM DD YYYY) : ");
	scanf("%d %d %d",&healthProfile->dob.month,&healthProfile->dob.day,&healthProfile->dob.year);
	printf("Enter the patient's height (in cm): ");
	scanf("%lf",&healthProfile->height);
	printf("Enter the patient's weight (in kg): ");
	scanf("%lf",&healthProfile->weight);
	
}

void bmi_values()
{
	// NAME: bmi_values
	// INPUT PARAMETERS:
	// OUTPUT: 
	// PURPOSE: To display the body mass index value to categorise people according to their bmi
	printf("BMI VALUES\n");
	printf("Underweight: less than 18.5\n");
	printf("Normal: between 18.5 and 24.9\n");
	printf("Overweight: between 25 and 29.9\n");
	printf("Obese: 30 or greater\n\n");
}

void health(healthProfile_t healthProfile)
{
	// NAME: health
	// INPUT PARAMETERS: struct healthProfile_t type-> health profile of the patient
	// OUTPUT: 
	// PURPOSE: To display health attributes of the patients
	int age; //age of the patient
	double bmi; //body mass index of the patient
	double height; //height of the patient in metres
	
	age = CURRENT_YEAR - healthProfile.dob.year;
	height=healthProfile.height/100;
	bmi=healthProfile.weight/(height*height);
	printf("\n%s's Health",healthProfile.first_name);
	printf("\nAge : %d\n",age);
	heart_rate(age);
	printf("BMI : %.1lf\n\n",bmi);
}

void heart_rate(int age)
{
	// NAME: heart_rate
	// INPUT PARAMETERS: int age -> age of the patient
	// OUTPUT: 
	// PURPOSE: To display the maximum heart rate and target heart rate of the patient according to their age
	if (age<30)
	{
		printf("Maximum heart rate: %d\n",200);
		printf("Target heart rate: %d-%d\n",100,170);
	}
	else if (age>30 && age<35)
	{
		printf("Maximum heart rate: %d\n",190);
		printf("Target heart rate: %d-%d\n",95,162);
	}
	else if (age>35 && age<40)
	{
		printf("Maximum heart rate: %d\n",185);
		printf("Target heart rate: %d-%d\n",93,157);
	}

	else if (age>40 && age<45)
	{
		printf("Maximum heart rate: %d\n",180);
		printf("Target heart rate: %d-%d\n",90,153);
	}
	else if (age>45 && age<50)
	{
		printf("Maximum heart rate: %d\n",175);
		printf("Target heart rate: %d-%d\n",88,149);
	}
	else if (age>50 && age<55)
	{
		printf("Maximum heart rate: %d\n",170);
		printf("Target heart rate: %d-%d\n",85,145);
	}
	else if (age>55 && age<60)
	{
		printf("Maximum heart rate: %d\n",165);
		printf("Target heart rate: %d-%d\n",83,140);
	}
	else if (age>60 && age<65)
	{
		printf("Maximum heart rate: %d\n",160);
		printf("Target heart rate: %d-%d\n",80,136);
	}
	else if (age>65 && age<70)
	{
		printf("Maximum heart rate: %d\n",155);
		printf("Target heart rate: %d-%d\n",78,132);
	}
	else if (age>70)
	{
		printf("Maximum heart rate: %d\n",150);
		printf("Target heart rate: %d-%d\n",75,128);
	}
}

