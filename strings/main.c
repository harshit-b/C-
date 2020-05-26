#include <stdio.h>
#include <string.h>

int youngest(int *,int );
double average(int *,int );
int main(int argc, char **argv)
{
	char name[6][40]={"Ryan, Elizabeth", "Mcintyre, Osborne", "Dumond, Kristin", "Larson, Lois", "Thorpe, Trinity", "Ruiz, Pedro"};
	char temp_name[40];
	int age[]={62,84,18,42,15,35},i,j,size,temp_age,min,young;
	double avg;
	size=6;
	printf("Original List");
	printf("\n------------------------------\n");
	for (i=0;i<size;i++)
	{
		printf("%s\t",name[i]);
		printf("\t%d\n",age[i]);
	}
	
	for (i=0; i<size-1; i++)
	{
		min=i;
		for(j=i+1; j<size; j++)
		{
			if (strcmp(name[j], name[min])<0)
			{
				min=j;
			}
		}
		strcpy(temp_name, name[i]); 
		strcpy(name[i], name[min]);  
		strcpy(name[min], temp_name);  
		temp_age=age[min];
		age[min]=age[i];
		age[i]=temp_age;
		
	}
	printf("\n\nAlphabitical List");
	printf("\n------------------------------\n");
	for (i=0;i<size;i++)
	{
		printf("%s\t",name[i]);
		printf("\t%d\n",age[i]);
	}
	printf("\n");
	young=youngest(age,size);
	printf("Youngest: %s  Age:%d\n",name[young],age[young]);
	printf("\n");
	avg=average(age,size);
	printf("Age Average: %.2f",avg);
	printf("\n");
	
	
}

int youngest(int age[],int size)
{
	int i,minimum=0;
	for(i=1;i<size;i++)
	{
		if (age[i]<age[minimum])
			minimum=i;
	}
	return minimum;
}

double average(int age[],int size)
{
	int i;
	double sum;
	printf("\n");
	for(i=0;i<size;i++)
	{
		sum+=age[i];
	}
	return sum/size;
}




