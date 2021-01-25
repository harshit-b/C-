// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To extract information of customers and their grocery list from an input file and log an output in an output file in a required format
// FOR: CS 2413 - 501/503 - Project 1

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


struct grocery_node{
	char name[25]; //Name of the Item
	float price; //The marked price (in dollars) of one item
	int number; //the number of said items in one customer's list
	struct grocery_node *next; //pointer to next grocery node in the grocery list 
}; //The grocery list

struct customer_node{
	float balance; //Amount of cash customer have on them
	char name[25]; //Name of customer
	float total; //Total amount for all the itmes purchased
	int items; //Total number of all the itmes purchased
	int rejected; // To determine if the customer was rejected or they were paid (1 - rejected, 0- not rejected)
	int express_register; //To determine whether the customer will go to express or regular register (1 - express, 0 - regular)
	struct grocery_node *grocery; // Head node of the grocery list for a particular customer
	struct customer_node *next; 
}*front=NULL, *rear=NULL; 

void insert_node(struct grocery_node **, char*, int, float);
struct grocery_node * get_node (char*, int, float);  
void output_file (struct grocery_node * start, FILE*); 

int main(int argc, char **argv)
{
	FILE *input; //Input file pointer 
	FILE *outp; //Output file pointer 
	char str[500], //Used to store each line of the file
		 grocery_name[25]="", //Used to store grocery name
		 number_str[5]="", //Used to store number of items of a particular product
		 arr[25][25], //Used to store each line of a file in array form using comma as the delimeter to form the elements of the array
		 c, 
		 *word; 
	int i, j, k, //Used to traverse the array to store all the information in respective structs
		name, // To determine if customer name has been extracted or not
		number; // Number of grocery items
	float price; // Price of a grocery item
	
	/* opening file for reading */
	input = fopen("input.txt" , "r");
	if(input == NULL) 
	{
		printf("Error opening file");
		return(-1);
	}
	/* ------------------------ */
	
	/* opening file for writing */
	outp = fopen("output.txt" , "w");
	if(outp == NULL) 
	{
		printf("Error opening file");
		return(-1);
	}
	/* ------------------------- */
	
	// Traversing each line of file to extract information and store it in structs.
	do
	{
		//Loop used to traverse each line of file until EOF
		if( fgets (str, 500, input)!=NULL ) 
		{
			/* Forming an array arr by using ',' as a delimiter to form elements */
			i=0; // Variable that will determine the number of customers as it will calculate number of line in the file and each line represents a customer
			word=strtok(str, ",");
			while (word != NULL) 
			{ 
				strcpy(arr[i],word);
				word = strtok(NULL, ","); 
				i++;
			}
			/*--------------------------------------------------------------------*/
			
			struct customer_node *newNode; //Head node for queue of customers
			newNode = (struct customer_node*)malloc(sizeof(struct customer_node)); //Dynamically allocating space in heap for customer node
			struct grocery_node *newGrocery; //Head node for grocery linked list 
			newGrocery = NULL; //Initializing head node for grocery linked list
			strcpy(newNode->name,""); //Initializing the member name as an empty string of the customer_node structure 
			newNode->total=0.0; // Initializing the member total and setting it to zero of the customer_node structure 
			newNode->items=0; // Initializing the member items and setting it to zero of the customer_node structure
			name=0; // Setting the variable name to zero
			
			/* Loop used to traverse the array made of each line to extract and store information in respective members of the respective structs */
			for(j=0;j<i;j++)
			{
				/* To extract the name and balance of the customer */
				if (name==0) // To check if the name of the customer has been extracted or not
				{
					// To check if fist character of the element j of the string is '{'
					if (*(*(arr+j)+0)==123) 
					{
						k=2; 
						/* Loop used to extract the customer's name. Traverses starting after the first '"' and runs till it hits a '"' */
						while (*(*(arr+j)+k)!=34) 
						{
							c=*(*(arr+j)+k); 
							strncat(newNode->name, &c, 1); // Concatenates each char c to the member name of the customer_node structure
							k++;
						}
						/* ------------------------------------------------------------------------------------------------------------ */
						
						newNode->balance=atof(*(arr+j+1)+1); // To extraxt balance of the customer, convert it into data type float and store it 
															 // in the member balance of the customer_node structure 
						newNode->next=NULL; 
						name=1; // To determine that customer name and balance has been traversed, extracted and stored in the customer_node structure
					}
					j++; // To skip the second element of the array since it is the balance of the customer which has already been extracted and stored in the customer_node struct

				}
				/* ------------------------------------------------------------------------------------------------------------------------------ */
				
				/* To extract all the grocery information and store it into the respective linked list */
				else
				{
					if (*(*(arr+j)+1)==91) // To check if first char of element j of array is '['
						k=4;
					else
						k=3;
					/* Loop to traverse the jth element of array and extract the grocery name*/
					while (*(*(arr+j)+k)!=34)
					{
						c=*(*(arr+j)+k);
						strncat(grocery_name, &c, 1);
						k++;
					}
					/* ------------------------------------------------------ */
					
					price=atof(*(arr+j+1)+1); // Extracts price of the respective grocery item and converts it into the data type float
					newNode->total+=price; // Stores the price of the grocery item into the member price of the grocery_node struct
					k=1;
					
					/* Loop to travers the jth element of array and extract the number of items of the respective grocery item */
					while (*(*(arr+j+2)+k)!=125)
					{
						c=*(*(arr+j+2)+k);
						strncat(number_str, &c, 1);
						k++;
					}
					/* -------------------------------------------------------------------------------------------------------- */
					
					number=atoi(number_str); // Converts number of items into data type int
					newNode->items+=number; // Stores the number of the grocery item into the member items of the grocery_node struct
					insert_node(&newGrocery, grocery_name, number, price); // Inserts a node to the grocery list with all the information of the grocery item 
					strcpy(number_str,""); 
					strcpy(grocery_name,"");
					j=j+2; // To skip the next two elements to jth element of the array as it has already been extracted and stored in the grocery_node structure 
					
				}
				/* ------------------------------------------------------------------------------------------------------------ */ 
			}
			/* ----------------------------------------------------------------------------------------------------------- */
			
			/* To determine if the customer will be rejected or not by checking if total price of grocery items is greater than balance of customre */
			if (newNode->total > newNode->balance) 
				newNode->rejected=1; // Customer is rejected 
			else
				newNode->rejected=0; // Customer is not rejected 
			/* ------------------------------------------------------------------------------------------------------------------------------------- */
			
			/* To determine if the customer will go to the express register or the the regular register by checking if the total number of items < 10 */
			if (newNode->items < 10)
				newNode->express_register=1; // Customer - express register 
			else
				newNode->express_register=0; // Customer - regular register 
			/* -------------------------------------------------------------------------------------------------------------------------------------- */
			
			/* Inserting customer_node to the queue of customeers */
			if(front == NULL)
			{
				front = rear = newNode;
			}
			else
			{
				rear->next = newNode;
				rear = newNode;
			}
			/* --------------------------------------------------- */
			
			output_file(newGrocery, outp); // Printing the output file with details of the particular customer 
		}
		else
			break;
	
	} while (1) ;
	fclose(input); // Closing input file 
	fclose(outp); // Closing output file
	printf("Please check for a file 'output.txt' in the working directory to see the output that was required!\n"); 
	return(0);
}

/*
   purpose:           insert_node inserts a node at the end of the list.
   input parameter:   struct grocery_node **start, char *data, int number, float price
   output parameter:  
   precondition:      *start must be initialized to an empty list or point to the first list node
   postcondition:     the new node initialized with data will be added to the end of the list
                      *start will point to the new list node if the list was empty                   
*/
void insert_node(struct grocery_node **start, char *data, int number, float price) 
{
  struct grocery_node * ptr;
  if (*start == NULL) {         // case when the list is empty 
    *start = get_node(data,number,price);    // allocate a new node initialized with the data and point the head of the list to the new node 
  }
  else {
    ptr = *start;               // case when the list is not empty 
    while(ptr->next != NULL) {  // traverse down the list so that ptr ends up pointing to the last node in the list 
      ptr = ptr->next;
    }
    ptr->next = get_node(data,number,price);  // allocate a new node initialized with the data and point the last node in the list to the new node 
  }
}

/* purpose:  get_node dynamically allocates a list node and initializes the member of the node 
   input parameter:  char *data, int number, float price
   output parameter: returns the list node
   precondition:  space must be available in the heap for the list node
   postcondition:  a list node is allocated from the heap intialized with data and NULL if space is available on the heap
*/

struct grocery_node * get_node (char *data, int number, float price) 
{
	struct grocery_node * ptr; // declare a list node pointer 
	ptr = (struct grocery_node *)malloc(sizeof(struct grocery_node)); // dynamicall allocate the list node from the heap
	strcpy(ptr->name, data); // Initialize the member name with data
	ptr->number=number; // Initialize the member name with data
	ptr->price=price; // Initialize the member price with price
	ptr->next = NULL;
	return(ptr);
}

/* purpose:  Print all the information of customer line by line in the required format
   input parameter:  struct grocery_node * start, FILE *outp 
   output parameter: 
   precondition:  The file pointed by the file pointer *outp should have been opened successfully
*/
void output_file (struct grocery_node * start, FILE *outp) 
{
	char str[100]=" ", c[10]; 
	struct customer_node *temp = front; 
	if(front == NULL)
		printf("\nQueue is Empty!!!\n");
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
	}
	struct grocery_node *ptr = start; // set ptr to the first node in the linked list */
	while(ptr != NULL) // while we have not encountered the end of the list */
	{
		sprintf(c, " %d ", ptr->number);
		strcat(str,c);          
		strcat(str,ptr->name);
		ptr = ptr->next; // go to the next node in the linked list */
	}
	//printf("%s\n", str); 
	if (temp->rejected==0)
	{
		if (temp->express_register==1)
			fprintf(outp, "%s paid $%.2f for %s at the express register\n", temp->name, temp->total, str);
		else
			fprintf(outp, "%s paid $%.2f for %s at the regular register\n", temp->name, temp->total, str);
	}
	else
		fprintf(outp, "%s was rejected at the express register\n", temp->name);
}

