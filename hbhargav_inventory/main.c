// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To implement a system that:
//					1. Manages the inventory system for a grocery store
//					2. Checks out queues of customers with grocery items
//					3. Provides a menu (with specific syntax ) to perform either of the above
// FOR: CS 2413 - 501/503 - Project 3

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define SIZE 10

//Representation of items in the inventory 
struct item{
	int key; //The item’s identification number (This will be used as the key)
	char name[20]; //The name describing the item
	int threshold; //The point at which the store needs to order more of that item
	int stock; //The number of that item currently in stock
	double price; //The price of that item, in $
};

struct customer_node{
	double cash; //Amount of cash each customer have on them
	char name[25]; //Name of customer
	int items; //Total number of items purchased by the customer
	int grocery[10][2]; // Grocery list of each customer
	struct customer_node *next; 
}*front=NULL, *rear=NULL; 

struct item* hashArray[SIZE]; 
struct item* dummyItem;
struct item* DataItem;

int hashCode(int ); 
void read_inventory();
void read_customers();
void display_item();
void insert_item(int, char *, int , int , double ); 
struct item *search_item(int ); 
struct item* delete_item(struct item* ); 
void sub_operation(char *);
void checkout();
void output_file();


int main(int argc, char **argv)
{
	char operation[50], // String variable to store instruction for sub-operation under the menu option - Manage the Inventory
		 checkout_op[20]; //String variable to store the checkout instruction and the name of the file containing information of customers
	int option; // Int variable to store the option of the operation from the menu that the user provides
	read_inventory(); // Function to read information of the grocery itmes in the inventory and store it in a hash table
	read_customers(); // Function to rad information of the customers and store it in a queue
	
	/* Menu of the program */
	do
	{
		printf("Please select any of the following operations from the menu below: \n");
		printf("\t1. Check-out queue of customers\n");
		printf("\t2. Manage Inventory\n");
		printf("\t3. Close program\n");
		printf("Please enter the number associated to the program that you would like to perform (1, 2 or 3) : ");
		scanf("%d",&option); // Takes the input of the option of the operation that the user would like to provide 
		if (option==1) // Checks if the option provided by user is 1
		{
			printf("Please type checkout and name of the file containing information of the customer in the form 'checkout <filename>': ");
			getchar();
			gets(checkout_op); 
			checkout(); // Function to check out each customer in the file which is provided by the user 
		}
		if (option==2) // Checks if the option provided by user is 2 
		{
			printf("Please type in istruction for any of the operatios below that you would like to perform: \n");
			printf("\tadd item (syntax: add <key> <name> <threshold> <stock> <price>): \n");
			printf("\tdelete item (syntax: delete <key>: \n");
			printf("\trestock item (syntax: restock <key> <amount>: \n");
			printf("\trestock all (syntax: restock all): \n");
			printf("\treturn to main menu (syntax: return): \n");
			getchar();
			gets(operation); // Takes the input of instructiion for any of the sub operations under the menu - Manage the Inventory and stores it in the variable - operation
			sub_operation(operation); // Function to perform sub operation according to the input provided by the user which is stored in the variable operation
		}
		
	} while(option!=3);
	/* ------------------------------------------------------------------------------------------------------------------------------------------ */
	output_file(); // Function to cloase the program and update any changes made to the inventory text file
}

/* purpose:  Read information of items that are stored in the file "iventory.txt"
   input parameter:
   output parameter: 
   precondition:
*/
void read_inventory()
{
	FILE *input; //File pointer
	char str[100], //Stores each line from the file one by one as we traverse the whole file
		 arr[3][25], //Store information of each item in an array after seperating all the information that is in the variable str
		 name[20]="", //Stores the name of the item as we extract the information from the file 
		 key_str[5]="", //Stores the key of the item as we extract the information from the file as a string 
		 threshold_str[10]="", //Stores the threshold of the item as we extract the information from the file as a string
		 stock_str[10]="", //Stores the stock number of the item as we extract the information from the file as a string
		 price_str[10]="", //Stores price of the item as we extract information from the file as a string
		 *word,
		 c; 
	
	int i, 
		k, 
		key=0, //Stores the key of the item as we extract the information from the file
		stock=0, //Stores the threshold of the item as we extract the information from the file
		threshold=0; //Stores the threshold of the item as we extract the information from the file
	
	double price=0.0; //Stores price of the item as we extract information from the file
	
	/* Attempt to open file for reading successfuly */
	input = fopen("inventory.txt" , "r");
	if(input == NULL) 
	{
		printf("Error opening file");
	}
	/* ------------------------------------------- */
	
	/* Loop to traverse the file and extract information of all itmes line by line */
	do
	{
		/* Extract line from the file and storing it in the variable str. Seperate the information of the item stored in the line 
		   and storing the information in the respective variables of the struct-item */
		if( fgets (str, 100, input)!=NULL ) 
		{
			/* This process is used to parse the line and seperate the information of the item and store it in an array arr */
			i=0; 
			word=strtok(str, ","); // Separate the string in two parts by usinng the first ',' found as the delimeter and store the first half in the variable word 
			while (word != NULL) 
			{ 
				strcpy(arr[i],word); // Store word in the array
				word = strtok(NULL, ","); // Separate the string in two parts by usinng the first ',' found as the delimeter and store the first half in the variable word
				i++;
			}
			/* ------------------------------------------------------------------------------------------------------------ */
			
			/* This process is to extract key of the item from the array arr */
			k=1; 
			while (*(*(arr+0)+k)!='\0') // Traverses the array arr characcter by character untile '\0' character found
			{
				c=*(*(arr+0)+k); //Stores the kth element of the array arr in c
				strncat(key_str, &c, 1); // Concatenates character c to the string - key_str
				k++; // Increments k by 1
			}
			key=atoi(key_str); // Converts the string contained in key_str to int and store it in the variable key
			/* ------------------------------------------------------------- */
			
			/* This process is to extract the name of the item from the array arr */
			k=2; 
			while (*(*(arr+1)+k)!=34) // Traverses the array arr characcter by character untile '"' character found
			{
				c=*(*(arr+1)+k); //Stores the kth element of the array arr in c
				strncat(name, &c, 1); // Concatenates character c to the string - name
				k++; // Increments k by 1
			}
			/* ------------------------------------------------------------------ */

			/* This process is to extract the threshold of the item from the array arr */
			k=0; 
			while (*(*(arr+2)+k)!='\0') // Traverses the array arr characcter by character untile '\0' character found
			{
				c=*(*(arr+2)+k); // Stores the kth element of the array arr in c
				strncat(threshold_str, &c, 1); // Concatenates character c to the string - threshold_str
				k++; // Increments k by 1
			}
			threshold=atoi(threshold_str); // Converts the string contained in threshold_str to int and store it in the variable threshold
			/* ----------------------------------------------------------------------- */
			
			/* This process is to extract the stock of the item from the array arr */
			k=0; 
			while (*(*(arr+3)+k)!='\0') // Traverses the array arr characcter by character untile '\0' character found
			{
				c=*(*(arr+3)+k); // Stores the kth element of the array arr in c
				strncat(stock_str, &c, 1); // Concatenates character c to the string - stock_str
				k++; // Increments k by 1
			}
			stock=atoi(stock_str); // Converts the string contained in stoack_str to int and store it in the variable stock
			/* ----------------------------------------------------------------------- */
			
			/* This process is to extract the price of the item from the array arr */
			k=0; 
			while (*(*(arr+4)+k)!=125) 
			{
				c=*(*(arr+4)+k); // Traverses the array arr characcter by character untile '}' character found
				strncat(price_str, &c, 1); // Concatenates character c to the string - price_str
				k++; // Increments k by 1
			}
			price=atof(price_str); // Converts the string contained in price_str to double and store it in the variable price
			/* ----------------------------------------------------------------------- */
			
			insert_item(key, name, threshold, stock, price); // Function to insert information of item to hash table 

			strcpy(name,"");
			strcpy(threshold_str,"");
			strcpy(key_str,"");
			strcpy(price_str,"");
			strcpy(stock_str,"");
			

		}
		
		else
			break;
	} while(1);
	/* -------------------------------------------------------------------------------- */
	fclose(input); // Closing file 
}

/* purpose:  Read information of customers 
   input parameter:
   output parameter: 
   precondition:
*/
void read_customers()
{
	FILE *input; //Input file pointer
	
	char str[500], // Used to store each line of the file
		 customer_name[25]="", // Used to store name of the customer
		 customer_cash_str[5]="", // Used to store number of items of a particular product
		 grocery_key_str[4]="", // Used to store key of the item in the grocery list
		 grocery_amount_str[10]="", // Used to store the number of item to be purchased in the grocery list
		 arr[25][25], //Used to store each line of a file in array form using comma as the delimeter to form the elements of the array
		 c, 
		 *word;
	
	int i, j, k, count, // Used as loop variables
		name; // To check if the name of the customer has been extracted or not;
	
	/* opening file for reading */
	input = fopen("test.txt" , "r");
	if(input == NULL) 
	{
		printf("Error opening file");
	}
	/* ------------------------ */
	
	// Traversing each line of file to extract information of customers and store it in queue.
	do
	{
		//Loop used to traverse each line of file until EOF 
		if( fgets (str, 500, input)!=NULL ) 
		{
			/* This process is used to parse the line and seperate the information of the item and store it in an array arr */
			i=0; // Variable that will determine the number of customers as it will calculate number of line in the file and each line represents a customer
			word=strtok(str, ","); // Separate the string in two parts by usinng the first ',' found as the delimeter and store the first half in the variable word 
			while (word != NULL) 
			{ 
				strcpy(arr[i],word); // Store word in the array
				word = strtok(NULL, ","); // Separate the string in two parts by usinng the first ',' found as the delimeter and store the first half in the variable word 
				i++;
			}
			/*--------------------------------------------------------------------*/
			
			struct customer_node *newNode; //Head node for queue of customers
			newNode = (struct customer_node*)malloc(sizeof(struct customer_node)); //Dynamically allocating space in heap for customer node
			
			strcpy(newNode->name,""); //Initializing the member name as an empty string of the customer_node structure 
			newNode->cash=0.0; // Initializing the member cash and setting it to zero of the customer_node structure 
			name=0; // Setting the variable name to zero
			
			count=0; // Used to determine the number of grocery items in the grocery list of each customer  
			/* Loop used to traverse the array made of each line to extract and store information in respective members of the respective structs */
			for(j=0;j<i;j++)
			{
				/* To extract the name and cash of the customer */
				if (name==0) // To check if the name of the customer has been extracted or not
				{
					// To check if fist character of the element j of the string is '{'
					if (*(*(arr+j)+0)==123) 
					{
						k=2; 
						/* Loop used to extract the customer's name. Traverses starting after the first '"' and runs till it hits a '"' */
						while (*(*(arr+j)+k)!=34) // Traverses the array arr characcter by character untile '"' character found
						{
							c=*(*(arr+j)+k); //Stores the kth element of the array arr in c
							strncat(customer_name, &c, 1); // Concatenates character c to the string - customer_name
							k++; // Increments k by 1
						
						}
						/* ------------------------------------------------------------------------------------------------------------ */
						strcpy(newNode->name, customer_name); // Stores the customer name in the name variable in the variable name of customer_node structure 

						k=1;
						/* Loop used to extract the cash available with customer */
						while (*(*(arr+j+1)+k)!='\0') // Traverses the array arr characcter by character untile '\0' character found
						{
							c=*(*(arr+j+1)+k); //Stores the kth element of the array arr in c
							strncat(customer_cash_str, &c, 1); // Concatenates character c to the string - customer_cash_str
							k++; // Increments k by 1
						}
						/* ------------------------------------------------------------------------------------------------------------ */
						
						newNode->cash=atof(customer_cash_str); // To extract cash available with the customer, convert it into data type float and store it 
															 // in the member cash of the customer_node structure 

						newNode->next=NULL; 
						name=1; // To determine that customer name and balance has been traversed, extracted and stored in the customer_node structure
					}
					j++; // To skip the second element of the array since it is the cash of the customer which has already been extracted and stored in the customer_node struct

				}
				/* ------------------------------------------------------------------------------------------------------------------------------ */
				
				/* To extract all the grocery information and store it into array grocery of the customer_node structure */
				else
				{
					if (*(*(arr+j)+1)==91) // To check if first char of element j of array is '['
						k=3;
					else
						k=2;
						
					/* Loop to traverse the jth element of array and extract the grocery key*/
					while (*(*(arr+j)+k)!='\0') // Traverses the array arr characcter by character untile '\0' character found
					{
						c=*(*(arr+j)+k); //Stores the kth element of the array arr in c
						strncat(grocery_key_str, &c, 1);  // Concatenates character c to the string - customer_cash_str
						k++; // Increments k by 1
					}
					/* ------------------------------------------------------ */
					
					newNode->grocery[count][0]=atoi(grocery_key_str);
					
					k=1;
					/* Loop to travers the j+1th element of array and extract the number of items of the respective grocery item */
					while (*(*(arr+j+1)+k)!=125) // Traverses the array arr characcter by character untile '\0' character found
					{
						c=*(*(arr+j+1)+k); //Stores the kth element of the array arr in c
						strncat(grocery_amount_str, &c, 1); // Concatenates character c to the string - customer_cash_str
						k++; // Increments k by 1
					}
					/* -------------------------------------------------------------------------------------------------------- */
					
					newNode->grocery[count][1]=atoi(grocery_amount_str); // Converts number of items into data type int
					count++; // Increments count by 1
					strcpy(customer_name,""); 
					strcpy(grocery_amount_str,"");
					strcpy(customer_cash_str,"");
					strcpy(grocery_key_str,"");
					j=j+1; // To skip the j+1th element of the array as it has already been extracted and stored in the grocery array 
					
				}
				/* ------------------------------------------------------------------------------------------------------------ */ 
			}
			newNode->items=count;
			/* ----------------------------------------------------------------------------------------------------------- */
			
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
		}
		else
			break;
	
	} while (1) ;
	fclose(input); // Closing input file 
}

int hashCode(int key) 
{
   return key % SIZE;
}

/* 
   purpose:  Inserts a item in the hash table 
   input parameter: int key - key of the grocery item to be searched in the hash table, int threshold - restock threshold of the item, int stock - number of items in the inventory, double price - price of the grocery item
   output parameter: char *name - name of the grocery item
   precondition: 
*/
void insert_item(int key, char *name, int threshold, int stock, double price) 
{
	/* Initialize a variable of struct-item and store information of the item in the respective variables of the struct-item */
	struct item *DataItem = (struct item*) malloc(sizeof(struct item));
	strcpy(DataItem->name, name);
	DataItem->threshold = threshold;  
	DataItem->key = key;
	DataItem->price = price;
	DataItem->stock = stock;
	/* ---------------------------------------------------------------------------------------------------------------------- */
	
	/* This is the process to add the item to the hash table using division method as the method of hashing the key*/ 
	//get the hash 
	int hashIndex = hashCode(key);

	//move in array until an empty or deleted cell
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) 
	{
		//go to next cell
		++hashIndex;
		
		//wrap around the table
		hashIndex %= SIZE;
	}
	
	hashArray[hashIndex] = DataItem;
	/* ------------------------------------------------------------------------------------------------------------ */
}

/* purpose:  Searches a item in the hash table using the key provided by the user and returning the item structure 
   input parameter: int key - key of the grocery item to be searched in the hash table
   output parameter: 
   precondition: 
*/
struct item *search_item(int key) 
{
   //get the hash 
   int hashIndex = hashCode(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

/* purpose:  Deletes a item given in output parameter stored in the hash table
   input parameter:
   output parameter: struct item* DataItem - Item that the user wants to delete 
   precondition: The function returns the item that is being deleted 
*/
struct item* delete_item(struct item* DataItem) 
{
	int key = DataItem->key;

	//get the hash 
	int hashIndex = hashCode(key);

	//move in array until an empty
	while(hashArray[hashIndex] != NULL) 
	{

		if(hashArray[hashIndex]->key == key) 
		{
			struct item* temp = hashArray[hashIndex]; 

			//assign a dummy item at deleted position
			hashArray[hashIndex] = dummyItem; 
			return temp;
		}
			
		//go to next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= SIZE;
	}      

	return NULL;        
}

/* purpose:  Executes an operation according to the instruction given by the user 
   input parameter:
   output parameter: char *operation - The instruction input that the user provides 
   precondition: The instruction should be according to the syntax otherwise the function does not perform any operation 
*/
void sub_operation(char *operation)
{
	struct item *DataItem = (struct item*) malloc(sizeof(struct item));
	//struct item *temp = (struct item*) malloc(sizeof(struct item));
	int i, 
		key, // Item’s identification number
		restock, // Amount of the item to be restocked 
		threshold, // The restock threshold of the item
		stock; // Amount of item
	char arr[6][20],
		 *word;
	double price;
	
	/* This process is to seperate all the words in the input instruction provided by the user and store it in an array arr */
	i=0;
	word=strtok(operation, " ");
	while (word != NULL) 
	{ 
		strcpy(arr[i],word);
		word = strtok(NULL, " "); 
		i++;
	}
	/* -------------------------------------------------------------------------------------------------------------------- */
	
	/* to check if the first word in the input provided by the user is add and then perform the operation accordingly */
	if (strcmp(arr[0],"add")==0)
	{
		key=atoi(arr[1]);
		threshold=atoi(arr[3]);
		stock=atoi(arr[4]);
		price=atof(arr[5]);
		insert_item(key, arr[2], threshold, stock, price);
	}
	/* ------------------------------------------------------------------------------------------------------------- */
	
	/* to check if the first word in the input provided by the user is delete and then perform the operation accordingly */
	else if (strcmp(arr[0],"delete")==0)
	{
		key=atoi(arr[1]);
		DataItem=search_item(key);
		delete_item(DataItem);
	}
	/* ----------------------------------------------------------------------------------------------------------------- */
	
	/* to check if the first word in the input provided by the user is restock and second word is not all and then perform the operation accordingly */
	else if (strcmp(arr[0],"restock")==0 && strcmp(arr[1],"all")!=0)
	{
		key=atoi(arr[1]);
		restock=atoi(arr[2]);
		DataItem=search_item(key);
		DataItem->stock+=restock;		
	}
	/* -------------------------------------------------------------------------------------------------------------------------------------------- */
	
	/* to check if the first word in the input provided by the user is restock and second word is all and then perform the operation accordingly */
	else
	{
		int i = 0;
	
		for(i = 0; i<SIZE; i++) 
		{
			if(hashArray[i] != NULL)
			{
				if (hashArray[i]->stock < hashArray[i]->threshold)
					hashArray[i]->stock = hashArray[i]->threshold;
			}
		}

	}
	/* -------------------------------------------------------------------------------------------------------------------------------------------- */
	printf("\n");
}

/* purpose: Checkout all the customers in the text file provided by the user in the input parameter. 
 *          Check if the user will be rejected or not by checking if customer has enough cash to buy all things in the cart.
 *          Print a reciept of all customers to an output file.
   input parameter: 
   output parameter: 
   precondition: The information of the customers in the text file should be in a proper syntax.
*/
void checkout()
{
	struct item *DataItem = (struct item*) malloc(sizeof(struct item));
	FILE *outp; //File pointer
	int count, // To count the number of items in the grocery list of each customer 
		key,// Item’s identification number
		i=0,// Couter variable to store the key of items in grocery list whose stock is less than threshold
		j,
		arr[10];
	double total; // Running total of customer's purchases 
	
	/* Attempt to open file for writing successfully */
	outp = fopen("test_reciept.txt" , "w"); 
	if(outp == NULL) // To check if the file opened successfully or not
	{
		printf("Error opening file");
	}
	/* ------------------------ */
	
	/* To traverse information of each customer stored in the queue */
	struct customer_node *temp = front; 
	if(front == NULL) // To check if the queue is empty or not
		printf("\nQueue is Empty!!!\n");
	else // Dequeue each customer in the queue until the queue is empty
	{
		do
		{
			count=0; // Counter variable to go through the grocery list of each customer 
			total=0.0; // Running total of cost of all grocery items purchased by the customer 
			fprintf(outp,"Customer - %s\n\n",temp->name); 
			/* Loop to traverse through all the grocery itmes in the grocery list of each customer and perform required operations */
			while (count<temp->items)
			{
				key=temp->grocery[count][0]; // obtain the key of the grocery item in the grocery list of the customer and store it in the variable key
				DataItem=search_item(key); // Search the item associated with the key in the inventory stored in the hash table and store the associated structure of the grocery item in the variable - DataItem
				total=total+((DataItem->price)*(temp->grocery[count][1])); // Increase the total cost by the price of the grocery item multiplied by the amount of grocery item
				fprintf(outp,"%s x%d @ $%.2lf\n\n", DataItem->name, temp->grocery[count][1], DataItem->price);
				count++; // Increment count by 1
			}
			/* -------------------------------------------------------------------------------------------------------------------- */
			fprintf(outp,"Total: $%.2lf\n", total);
			if (temp->cash > total) // Check if the cash available with the customer is greater than the toal cost of all grocery items purchased
			{
				count=0;
				while (count<temp->items)
				{
					key=temp->grocery[count][0]; // obtain the key of the grocery item in the grocery list of the customer and store it in the variable key
					DataItem=search_item(key); // Search the item associated with the key in the inventory stored in the hash table and store the associated structure of the grocery item in the variable - DataItem
					DataItem->stock=DataItem->stock-temp->grocery[count][1]; // Subtract the stock of the grocery item by the number of item purchased by the customer
					if ((DataItem->stock) < (DataItem->threshold)) // Check if the stock of the grocery item is less than the restock threshold 
					{
						arr[i]=key; // store the key of the grocery item in an array arr
						i++; // increment i by 1
					}
					count++; // increment count by 1
				}
				fprintf(outp,"Thank you, come back soon!\n");
				fprintf(outp,"----------------------------------------------------------\n\n");
			}
			else // Condition if cash available with the customer is less than the total cost of all grocery items 
			{
				fprintf(outp, "Customer did not have enough money and was REJECTED\n");
				fprintf(outp, "Thank you, come back soon!\n");
				fprintf(outp, "----------------------------------------------------------\n\n");
			}
			temp = temp->next; 
		}while(temp!= NULL);
		
		if (i>=1) // Condition to check if there is any 1 grocery item whose stock is less than threshold and then print the warning message 
		{
			printf("\n\nWarning! The following Item(s) may need to be restocked:\n");
			for (j=0;j<i;j++)
			{
				DataItem=search_item(arr[j]); 
				printf("%d (%s): %d remain in stock, replenishment threshold is %d\n", DataItem->key, DataItem->name, DataItem->stock, DataItem->threshold);
			}
			printf("\n");
		}
	}
	/* --------------------------------------------------------------------------------------------------------- */
	fclose(outp);
}

/* 
	purpose: Update the inventory text file according if any changes made in the program
   
*/
void output_file()
{
	int i;
	
	FILE *outp; //File pointer
	
	/* opening file for reading */
	outp = fopen("inventory.txt" , "w");
	if(outp == NULL) 
	{
		printf("Error opening file");
	}
	/* ------------------------ */
	
	for(i = 0; i<SIZE; i++) 
	{

		if(hashArray[i] != NULL)
		{
			if (hashArray[i]->key<10)
				fprintf(outp, "{00%d, %c%s%c, %d, %d, %.2lf}\n", hashArray[i]->key, 34, hashArray[i]->name, 34, hashArray[i]->threshold, hashArray[i]->stock, hashArray[i]->price);
			else if (hashArray[i]->key<100)
				fprintf(outp, "{0%d, %c%s%c, %d, %d, %.2lf}\n", hashArray[i]->key, 34, hashArray[i]->name, 34, hashArray[i]->threshold, hashArray[i]->stock, hashArray[i]->price); 
			else if (hashArray[i]->key<1000)
				fprintf(outp, "{%d, %c%s%c, %d, %d, %.2lf}\n", hashArray[i]->key, 34, hashArray[i]->name, 34, hashArray[i]->threshold, hashArray[i]->stock, hashArray[i]->price); 
		}
	}

	printf("\n");
	fclose(outp);
}