// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To convert infix expression to postfix expression using stack implementation by linked list
// FOR: CS 1412 Programming Principles II Section 002

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct stackNode
{
    char ele; 
    struct stackNode *next;
}; 

typedef struct stackNode StackNode;
StackNode *top=NULL;

void push(char ); 
char pop(); 
int is_operator(char ); 
int precedence(char ); 
void convertToPostfix( char infix[], char postfix[] ); 
int isEmpty(); 
void printStack(); 

int main()
{
	char infix[100], //Infix expression
		 postfix[100];//postfix expression
    printf("ENTER THE INFIX NOTATION: ");
    gets(infix);
    convertToPostfix(infix,postfix);
    printf("POSTFIX NOTATION\n");
    puts(postfix);
    getchar();
    return 0;
    
    
}

void push(char item)
{
	// NAME: push
	// INPUT PARAMETERS: char type-> element that needs to pushed in the stack 
	// OUTPUT: 
	// PURPOSE: To push element on top of stack 
    struct stackNode *tmp;
    tmp = (struct stackNode*)malloc(sizeof(struct stackNode));
    tmp->ele = item;
    if (isEmpty())
      tmp->next = NULL;
    else
      tmp->next = top;
    top = tmp;
}

char pop()
{
	// NAME: pop
	// INPUT PARAMETERS:
	// OUTPUT: returns the item removed from the stack
	// PURPOSE: To remove the top element from stack
	char item;
    if(top != NULL)
	{
      struct stackNode *temp = top;
      item = top->ele;
      top = temp->next;
      free(temp);
   }
   return item;
}

int is_operator(char symbol)
{
	// NAME: is_operator
	// INPUT PARAMETERS: element that needs to be checked if it is an operator or not
	// OUTPUT: returns 1 if an operator else 0
	// PURPOSE: To check if elemwnt is an operator or not
    if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-'||symbol=='%')
    {
        return 1;
    }
    else
        return 0;
}

int precedence(char symbol)
{
	// NAME: precedence
	// INPUT PARAMETERS: element whose precedence needs to be checked
	// OUTPUT: returns 0,1,2,3 according to the precedence of the element
	// PURPOSE: To check the precedence of the operator
    if(symbol=='^')
    {
        return 3;
    }
    else if(symbol=='*'||symbol=='/'||symbol=='%')
    {
        return 2;
    }
    else if(symbol=='+'||symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void convertToPostfix( char infix[], char postfix[] )
{
	// NAME: convertToPostfix
	// INPUT PARAMETERS: infix and postfix expression char arrays
	// OUTPUT: 
	// PURPOSE: To cconvert infix epression to postfix expression
	char item,temp;
	int i=0,j=0;
	while(infix[i]!='\0')
    {
        item=infix[i];
        if(item=='(')
        {
            push(item);
        }
        else if(isdigit(item))
        {
            postfix[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            temp=pop();
            while(is_operator(temp)==1 && precedence(temp)>=precedence(item))
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
            push(temp);
            push(item);
        }
        else if(item==')')
        {
            temp=pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
        }
        else
        {
            printf("INVALID EXPRESSION");
            getchar();
            exit(0);
            
        }
        i++;
    }
    while(top!=NULL)
    {
		temp=pop();
		if (temp!='(')
			postfix[j]=temp;
			j++;
    }
    postfix[j]=='\0';
}

int isEmpty()
{
	// NAME: isEmpty
	// INPUT PARAMETERS: 
	// OUTPUT: 
	// PURPOSE: Check if the stack is empty or not
	
	if (top==NULL)
		return 1;
	else 
		return 0;
}

void printStack()
{
	// NAME: printStack
	// INPUT PARAMETERS: 
	// OUTPUT: 
	// PURPOSE: Print the stack
	if(isEmpty())
      printf("\nStack is Empty!!!\n");
    else
	{
      struct stackNode *temp = top;
      while(temp->next != NULL)
	  {
		printf("%c--->",temp->ele);
		temp = temp -> next;
	  }
	  printf("%c--->NULL",temp->ele);
	}

}


