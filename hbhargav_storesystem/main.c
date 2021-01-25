// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: implement a system that stores customer loyalty accounts at a grocery store, then processes basic orders for said customers.
// FOR: CS 2413 - 501/503 - Project 2

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct customer_account{
	int id; //A unique 4 digit ID number (0-9999)
	char name[20]; //The customer’s name 
	double balance; //Amount of store credit customers have accrued
	struct customer_account *left; // root node for left sub-tree
	struct customer_account *right; // root node for right sub-tree
};

struct customer_account *tree; // Initializing pointer for root node for binary search tree of customer accounts
struct customer_account *tree_search; 

void create_tree(struct customer_account *); 
struct customer_account * minValueNode(struct customer_account *);
struct customer_account* deleteNode(struct customer_account *, int );
void process(struct customer_account *);
struct customer_account *insert(struct customer_account *, char *, int , double);
void postorder(struct customer_account *, FILE *);
void inorder(struct customer_account *, FILE *);
void preorder(struct customer_account *, FILE *);
void print_preorder(struct customer_account *);
void read_customers();
void quit(struct customer_account *);\

int main(int argc, char **argv)
{
	char str[50],
		 arr[4][25],
		 *word;
	int i,
		id;
	double balance;
	create_tree(tree);
	read_customers();
	
	print_preorder(tree);
	printf("\n");
	printf("\n");
	printf("Write statement to perform operation : ");
	gets(str);
	i=0;
	word=strtok(str, " ");
	while (word != NULL) 
	{ 
		strcpy(arr[i],word);
		word = strtok(NULL, " "); 
		i++;
	}
	
	if (strcmp(arr[0],"add")==0)
	{
		id=atoi(arr[1]);
		balance=atof(arr[3]);
		tree=insert(tree, arr[2], id, balance);
	}
	
	else if (strcmp(arr[0],"delete")==0)
	{
		id=atoi(arr[1]);
		tree=deleteNode(tree, id);
	}
	
	else if (strcmp(arr[0],"process")==0)
	{
		process(tree);
	}
	
	else if (strcmp(arr[0], "quit")==0)
	{
		quit(tree);
	}
	
	printf("\n");
	print_preorder(tree);
	printf("\n\n");
}

void create_tree(struct customer_account *tree)
{
	tree = NULL;
}

void postorder(struct customer_account *tree, FILE *outp)
{
	if(tree != NULL)
	{
		postorder(tree->left, outp);
		postorder(tree->right, outp);
		fprintf(outp, "{%d, %s, %.2lf}", tree->id, tree->name, tree->balance);
		fprintf(outp, "\n");
	}
}

void inorder(struct customer_account *tree, FILE *outp)
{
	if(tree != NULL)
	{
		inorder(tree->left, outp);
		fprintf(outp, "{%d, %s, %.2lf}", tree->id, tree->name, tree->balance);
		fprintf(outp, "\n");
		inorder(tree->right, outp);
	}
}

void preorder(struct customer_account *tree, FILE *outp)
{
	if(tree != NULL)
	{
		fprintf(outp, "{%d, %s, %.2lf}", tree->id, tree->name, tree->balance);
		fprintf(outp, "\n");
		preorder(tree->left, outp);
		preorder(tree->right, outp);
	}
}

void print_preorder(struct customer_account *tree)
{
	if(tree != NULL)
	{
		printf("\n%s\t", tree->name);
		printf("%d\t",tree->id);
		printf("%.2lf\t",tree->balance);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

struct customer_account * minValueNode(struct customer_account* node) 
{ 
    struct customer_account* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}

struct customer_account* deleteNode(struct customer_account* tree, int id) 
{ 
    // base case 
    if (tree == NULL) return tree; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (id < tree->id) 
        tree->left = deleteNode(tree->left, id); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (id > tree->id) 
        tree->right = deleteNode(tree->right, id); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (tree->left == NULL) 
        { 
            struct customer_account *temp = tree->right; 
            free(tree); 
            return temp; 
        } 
        else if (tree->right == NULL) 
        { 
            struct customer_account *temp = tree->left; 
            free(tree); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct customer_account* temp = minValueNode(tree->right); 
  
        // Copy the inorder successor's content to this node 
        tree->id = temp->id; 
  
        // Delete the inorder successor 
        tree->right = deleteNode(tree->right, temp->id); 
    } 
    return tree; 
} 

struct customer_account *insert(struct customer_account *tree, char *name, int id, double balance)
{
	struct customer_account *ptr, *nodeptr, *parentptr;
	ptr = (struct customer_account*)malloc(sizeof(struct customer_account));
	strcpy(ptr->name, name);
	ptr->id=id;
	ptr->balance=balance;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			if(id < nodeptr->id)
				nodeptr=nodeptr->left;
			else
				nodeptr = nodeptr->right;
		}
		if(id < parentptr->id)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	return tree;
}

void read_customers()
{
	FILE *input;
	char str[100], //Used to store each line of the file
		 arr[3][25],
		 name[20]="",
		 id_str[5]="",
		 balance_str[10]="",
		 *word,
		 c;
	int i, k, id=0; //Used to traverse the array to store all the information in respective structs
	double balance=0.0;
	 /* opening file for reading */
	input = fopen("customers.txt" , "r");
	if(input == NULL) 
	{
		printf("Error opening file");
	}
	/* ------------------------ */
	
	// Traversing each line of file to extract information and store it in structs.
	do
	{
		//Loop used to traverse each line of file until EOF
		if( fgets (str, 100, input)!=NULL ) 
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
			
			k=1; 
			while (*(*(arr+0)+k)!='\0') 
			{
				c=*(*(arr+0)+k); 
				strncat(id_str, &c, 1); 
				k++;
			}
			id=atoi(id_str);
			
			k=2; 
			while (*(*(arr+1)+k)!=34) 
			{
				c=*(*(arr+1)+k); 
				strncat(name, &c, 1);
				k++;
			}

			
			k=1; 
			while (*(*(arr+2)+k)!=125) 
			{
				c=*(*(arr+2)+k); 
				strncat(balance_str, &c, 1); 
				k++;
			}
			balance=atof(balance_str);
			
			tree = insert(tree, name, id, balance);
			strcpy(name,"");
			strcpy(balance_str,"");
			strcpy(id_str,"");
		}
		
		else
			break;
	} while(1);
	fclose(input);
}

struct customer_account *search(struct customer_account *tree, int id)
{
	if(tree==NULL)
		return NULL;
	else	
	{
		if(tree->id==id)
			return tree;
		else if(id<tree->id)
			return search(tree->left, id);
		else
			return search(tree->right, id);
	}
}

void process(struct customer_account* tree) 
{
	char str[100], //Used to store each line of the file
		 arr[3][25],
		 id_str[5]="",
		 order_total_str[10]="",
		 *word,
		 c;
	int i, k, id=0; //Used to traverse the array to store all the information in respective structs
	double store_balance=0.0,
		   order_total=0.0,
		   payment_cash=0.0,
		   payment_balance;
	FILE *input;
	 /* opening file for reading */
	input = fopen("orders.txt" , "r");
	if(input == NULL) 
	{
		printf("Error opening file");
	}
	/* ------------------------ */
	
	printf("\n");
	// Traversing each line of file to extract information and store it in structs.
	do
	{
		//Loop used to traverse each line of file until EOF
		if( fgets (str, 100, input)!=NULL ) 
		{
			i=0; 
			word=strtok(str, ",");
			while (word != NULL) 
			{ 
				strcpy(arr[i],word);
				word = strtok(NULL, ","); 
				i++;
			}
			
			k=1; 
			while (*(*(arr+0)+k)!='\0') 
			{
				c=*(*(arr+0)+k); 
				strncat(id_str, &c, 1);
				k++;
			}
			
			id=atoi(id_str);
			
			k=1; 
			while (*(*(arr+1)+k)!=125) 
			{
				c=*(*(arr+1)+k); 
				strncat(order_total_str, &c, 1);
				k++;
			}
			/* ------------------------------------------------------------------------------------------------------------ */
			order_total=atof(order_total_str);
			tree_search=search(tree, id);
			store_balance=tree_search->balance;
			if (order_total>store_balance)
			{
				payment_cash=order_total-store_balance;
				payment_balance=store_balance;
				store_balance=0;
				
			}
			else
			{
				payment_cash=0;
				payment_balance=order_total;
				store_balance=store_balance-order_total;
				
			}
			
			printf("Customer %d, %s, payed $%.2lf from their store balance and $%.2lf at the register, $%.2lf remaining store balance\n", tree_search->id, tree_search->name, payment_balance, payment_cash, store_balance);
			
			tree_search->balance=store_balance;
			strcpy(order_total_str,"");
			strcpy(id_str,"");
		}
		
		else
			break;
	}while(1);
	fclose(input);
}

void quit(struct customer_account *tree)
{
	char order[100];
	FILE *outp;
	/* opening file for reading */
	outp = fopen("newcustomers.txt" , "w");
	if(outp == NULL) 
	{
		printf("Error opening file");
	}
	/* ------------------------ */
	
	printf("Please enter output format: pre, post, or in order: ");
	scanf("%s", order);
	
	if(strcmp(order, "pre")==0)
	{
		preorder(tree, outp);
		printf("Writing yo newcustomers.txt in pre-order, shutting down...\n");
	}
	else if(strcmp(order, "post")==0)
	{
		postorder(tree, outp);
		printf("Writing yo newcustomers.txt in post-order, shutting down...\n");
	}
	else if(strcmp(order, "in")==0)
	{
		inorder(tree, outp);
		printf("Writing yo newcustomers.txt in in-order, shutting down...\n");
	}
	
	fclose(outp);
}

