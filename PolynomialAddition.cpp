#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int coeff;
	int pow;
	Node* next;
};

void readPolynomial(Node** poly)
{
	int coeff, exp, cont;
	 Node* temp = ( Node*)malloc(sizeof( Node));
	*poly = temp;
	do{
		printf("\n Coeffecient: ");
		scanf("%d", &coeff);
		printf("\n Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("\nHave more terms? 1 for y and 0 for no: ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = ( Node*)malloc(sizeof( Node));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);	
}

void displayPolynomial( Node* poly)
{
	printf("\nPolynomial expression is: ");
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}

void addPolynomials( Node** result,  Node* first,  Node* second)
{
 	 Node* temp = ( Node*)malloc(sizeof( Node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = ( Node*)malloc(sizeof( Node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = ( Node*)malloc(sizeof( Node));
 		temp = temp->next;
 		temp->next = NULL;
 			
 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}

int main()
{

	 Node* first = NULL;
	 Node* second = NULL;
	 Node* result = NULL;

	printf("\nEnter the corresponding data:-\n");
	printf("\nFirst polynomial:\n");
	readPolynomial(&first);
	displayPolynomial(first);
	printf("\nSecond polynomial:\n");
	readPolynomial(&second);
	displayPolynomial(second);
	addPolynomials(&result, first, second);
	displayPolynomial(result);
	return 0;
}