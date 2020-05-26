#include <stdio.h>

// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To implement binary search using recursion
// FOR: CS 1412 Programming Principles II Section 002

int binary_search(int *,int ,int ,int );
void sort(int arr[], int size);

int main(int argc, char **argv)
{
	int size=0, //size of the array
	i, //iterator
	search, //user input for the number they want to search
	result; //index of the number found
	int arr[size];
	printf("Input the number of elements to store in your array: ");
	scanf("%d",&size);
	printf("Input %d elements to the array\n",size);
	for(i=0;i<size;i++)
	{
		printf("element - %d: ",i);
		scanf("%d",&arr[i]);
	}
	sort(arr,size);
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("Input the number to search: ");
	scanf("%d",&search);
	result=binary_search(arr,0,size-1,search);
	if (result==-1)
		printf("\nThe number is not in in the array\n");
	else
		printf("\nFound number %d in index %d\n",search,result);
	
}

int binary_search(int arr[],int left,int right,int search)
{
	// NAME: binary_search
	// INPUT PARAMETERS: arr[]-array, left-left most element of the array, right-right most element of the array, search-element that is being searched
	// OUTPUT: An integer, index of the element that is being searched
	// PURPOSE: Search an element in an array
	int mid; //the middle element to break the array in two virtual arrays
	if (right>=left)
	{
		mid=(left+(right-1))/2;
		if (arr[mid]==search)
			return mid;
		else if(arr[mid]>search)
			return binary_search(arr,left,mid-1,search);
		else if(arr[mid]<search)
			return binary_search(arr,mid+1,right,search);
	}
	
	return -1;
}

void sort(int arr[], int size)
{
	// NAME: sort
	// INPUT PARAMETERS: arr[]-array, size-size of the array
	// OUTPUT: 
	// PURPOSE: sort the array in ascending order using selection sort
	int min,i,j,temp;
	for (i=0; i<size-1; i++)
	{
		min=i;
		for(j=i+1; j<size; j++)
		{
			if (arr[j]<arr[min])
			{
				min=j;
			}
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
}

