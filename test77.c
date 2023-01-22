#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	FILE *fg;
	
	
	struct details{
		int _id;
		float _cost; 
		char First_name[20]; 
		char Second_name[20];
		int day, month, year, tr_id;
	}costumers;
	
	fg = fopen("Transaction.txt","r");
	if(fg == NULL)
	{
		printf("This file could not be open\n");
	}
	
	
}

