 #include<stdio.h>
 void main()
 {
 
 	FILE *fc;
    char password_db[30];
    int ID_db;
    int age_f;
    char city_f[30];
    char gender_f[30];
    char number_f[11];
    char first_name_f[20];
    char second_name_f[20];
    char _email[30];
    int id;
    
    fc = fopen("subscribe.txt", "r");
    if (fc = NULL)
    {
        printf("\n\t\t\t\tFile could not be open!"); getch(); return;
    }
    
	printf("%d",id);
    printf("\n\t\t\t\tHello world 1");
    while(fscanf(fc,"%d %s %s %d %s %s %s %s %s", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) == 9)
    {
    	if(id == ID_db)
    	{
    		printf("%d %s %s %d %s %s %s %s %s\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, number_f, _email, password_db);
        	
		}
		getch();
		
    }
    fclose(fc);
	
}

/*fc = fopen("subscribe.txt", "r");
    if (fc = NULL)
    {
        printf("\n\t\t\t\tFile could not be open!"); getch(); return;
    }
    
	printf("%d",ID);
    printf("\n\t\t\t\tHello world 1");
    while(fscanf(fc,"%d %s %s %d %s %s %s %s %s", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) == 9)
    {
    	if(ID == ID_db)
    	{
    		printf("%d %s %s %d %s %s %s %s %s\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, number_f, _email, password_db);
        	
		}
		getch();
		
    }
    fclose(fc);
    
    printf("HELLO WORLE 3");*/
