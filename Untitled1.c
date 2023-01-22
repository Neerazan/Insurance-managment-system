#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	FILE *fs;
	int ID_db;
    int tr_id;
    char first_name[20];
    char second_name[20];
    int cost;
    int day, month, year;
    fs = fopen("Transaction.txt","r");
    if(fs == NULL)
    {
    	printf("\t\t\t\tFile could not be open");
	}
	//1  1002           gokul pathak   50000.00 19/7/2021
	printf("Hello world 2");
    while(fscanf(fs,"%d %d %s %s %f %d %d %d",&tr_id,&ID_db,first_name,second_name,&cost,&day,&month,&year)==8)
    {
    	printf("Hello world\n");
    	printf("%d %d", tr_id, ID_db);getch();
    	printf("%s", first_name);
	}
}
