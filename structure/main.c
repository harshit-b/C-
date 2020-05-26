#include <stdio.h>

// AUTHOR: Harshit Bhargava
// FILENAME: main.c
// SPECIFICATION: To scan and store information of products in a grocery store
// FOR: CS 1412 Programming Principles II Section 002

typedef struct {
	char name[20], //product name
	product_category, //category of the product
	aisle_side, //letter corresponding to the aisle side
	type; //type of the product
	int packaging_month, //month the product was packaged
	packaging_year, //year the product was packaged
	expiry_month, //month the product will expire
	expiry_year, //year the product will expire
	recieved_month, //year the product was recieved
	recieved_year, //month the product was recieved
	aisle_number, //aisle number
	cost; //cost of the product per unit
} product_t;

void get_product_data(char type, product_t *product);
void set_product_data(char type, product_t product);

int main(int argc, char **argv)
{
	char type;
	product_t product;
	printf("Following are the product types: \n");
	printf("M -> Meats\n");
	printf("P -> Produce\n");
	printf("D -> Dairy\n");
	printf("C -> Canned Goods\n");
	printf("N -. Nonfoods\n");
	printf("Enter the letter corresponding to the type of product's information you want to store: ");
	scanf("%c",&type);
	product.product_category=type;
	get_product_data(type,&product);
	set_product_data(type,product);
	printf("\n");
	
}

void get_product_data(char type, product_t *product)
{
	// NAME: get_product_data
	// INPUT PARAMETERS: char type-> signifies the product category 
	// OUTPUT: product_t *product->structure to store the information in
	// PURPOSE: To scan and store information of the product in a structure
	switch (type)
	{
		case 'M':
		case 'm': 
			printf("Enter the name of the product: ");
			scanf(" %s",&product->name);
			printf("Enter the kind of meat it is ('R' for red meat, 'P' for poultry, 'F' for fish): ");
			scanf(" %c",&product->type);
			printf("Enter the date of packaging in the format (MM YYYY): ");
			scanf("%d%d",&product->packaging_month,&product->packaging_year);
			printf("Enter the expiration date in the format (MM YYYY): ");
			scanf("%d%d",&product->expiry_month,&product->expiry_year);
			printf("Enter the unit cost in cents: ");
			scanf("%d",&product->cost);
			break;
		case 'P':
		case 'p':
			printf("Enter the name of the product: ");
			scanf("%s",&product->name);
			printf("Enter whether the product is vegetable or fruit('F' for fruit, 'V' for vegetable): ");
			scanf("%c",&product->type);
			printf("Enter the date the product was recieved in the format (MM YYYY): ");
			scanf("%d%d",&product->recieved_month,&product->recieved_year);
			printf("Enter the expiration date in the format (MM YYYY): ");
			scanf("%d",&product->cost);
			break;
		case 'D':
		case 'd':
			printf("Enter the name of the product: ");
			scanf("%s",&product->name);
			printf("Enter the expiration date in the format (MM YYYY): ");
			scanf("%d%d",&product->expiry_month,&product->expiry_year);
			printf("Enter the unit cost in cents: ");
			scanf("%d",&product->cost);
			break;
		case 'C':
		case 'c':
			printf("Enter the name of the product: ");
			scanf("%s",&product->name);
			scanf("%d%d",&product->expiry_month,&product->expiry_year);
			printf("Enter the unit cost in cents: ");
			scanf("%d",&product->cost);
			printf("Enter the aisle number(an integer): ");
			scanf("%d",&product->aisle_number);
			printf("Enter the aisle side (letter 'A' or 'B'): ");
			scanf("%c",&product->aisle_side);
			break;
		case 'N':
		case 'n':
			printf("Enter the name of the product: ");
			scanf("%s",&product->name);
			printf("Enter the kind of meat it is ('R' for red meat, 'P' for poultry, 'F' for fish): ");
			scanf("%c",&product->type);
			printf("Enter the aisle number(an integer): ");
			scanf("%d",&product->aisle_number);
			printf("Enter the aisle side (letter 'A' or 'B'): ");
			scanf("%c",&product->aisle_side);
			printf("Enter the unit cost in cents: ");
			scanf("%d",&product->cost);
			break;
	}
}
	
void set_product_data(char type, product_t product)
{
	// NAME: set_product_data
	// INPUT PARAMETERS: char type-> signifies the product category 
	// OUTPUT: product_t *product->structure which has the information stored of the product
	// PURPOSE: To print the information of the product stored in the structure on the screen
	switch (type)
	{
		case 'M':
		case 'm':
			printf("\nProduct Name: %s\n",product.name);
			printf("Product Category: %c\n",product.product_category);
			printf("Meat Type: %c\n",product.type);
			printf("Date of Packaging: %d %d\n",product.packaging_month,product.packaging_year);
			printf("Expiration Date: %d %d\n\n",product.expiry_month,product.expiry_year);
			break;
		case 'P':
		case 'p':
			printf("\nProduct Name: %s\n",product.name);
			printf("Product Category: %c\n",product.product_category);
			printf("Fruit or Vegetable: %c\n",product.type);
			printf("Date Recieved: %d %d\n\n",product.recieved_month,product.recieved_year);
			break;
		case 'D':
		case 'd':
			printf("\nProduct Name: %s\n",product.name);
			printf("Product Category: %c\n",product.product_category);
			printf("Expiration Date: %d %d\n\n",product.expiry_month,product.expiry_year);
			break;
		case 'C':
		case 'c':
			printf("\nProduct Name: %s\n",product.name);
			printf("Product Category: %c\n",product.product_category);
			printf("Expiration Date: %d %d\n",product.expiry_month,product.expiry_year);
			printf("Aisle: %d%c\n\n",product.aisle_number,product.aisle_side);
			break;
		case 'N':
		case 'n':
			printf("\nProduct Name: %s\n",product.name);
			printf("Product Category: %c\n",product.product_category);
			printf("Nonfoods Type: %c\n",product.type);
			printf("Aisle: %d%c\n\n",product.aisle_number,product.aisle_side);
			break;
	}
}


