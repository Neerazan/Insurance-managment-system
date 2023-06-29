#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void transaction_details_admin();

void main(){
    transaction_details_admin();
}
void transaction_details_admin()
{
    int ID;
    int tr_id;
    char first_name[20];
    char second_name[20];
    float cost;
    int year, month, day;


    FILE *fn;
    fn = fopen("Transaction.txt", "r");
    if (fn == NULL)
    {
        printf("\n\t\t\t\tFile could not be open!");
        getch();
        return;
    }
    while (fscanf(fn, "%d %d %s %s %f %d %d %d", &tr_id, &ID, first_name, second_name, &cost, &day, &month, &year) == 8)
    {
        printf("%d %5d %10s %5s %10.2f %10d %d %d\n", tr_id, ID, first_name, second_name, cost, day, month, year);
    }
    fclose(fn);
}