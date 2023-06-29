#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void claim_process(int ID);
void all_user();
void subscribe_plan(int ID);
void customer_details();
void user_menu(int id);
void user_login();
void admin();
void admin_menu();
void create_account();
int generate_id();
void costumer_data(int id);
void transaction_details(int id);
void costumer_plan_type(int id);
void transaction_details_admin();
void File_update(float balance, int id);
int transaction_id();
void update_transaction(int id, float balance, char f_name[], char l_name[]);
void claim(float balance, int id);

//............MAIN ...............//
void main()
{

    int option;
main:
    system("cls");
    printf("\n\n\t-----------------------------------\n\t||\tWELCOME TO ZeeMediLife\t||\n\t-----------------------------------");
    printf("\n\n");
    printf("\n\t\t1. Creat account");
    printf("\n\t\t2. Admin Login");
    printf("\n\t\t3. Costumer Login");
    printf("\n\t\t4. Exit\n");
    printf("\n\tChoose your option: ");
    scanf("%d", &option);
    fflush(stdin);
    if (option == 1)
    {
        create_account();
        getch();
        main();
    }

    else if (option == 2)
    {
        admin();
        getch();
        main();
    }
    else if (option == 3)
    {
        user_login();
        getch();
        main();
    }
    else if (option == 4)
    {
        return;
    }
    else
    {
        printf("\n\tInvalid optioin");
        char rm;
        printf("\n\tDo you wanto to continue? | 'Y' for yes | and | 'N'| for No ");
        scanf("%s", &rm);
        if (rm == 'y' || rm == 'Y')
        {
            goto main;
        }
        else
        {
            return;
        }
    }
}

//......user login  function..........//
void user_login()
{
    int ID;
    char password_[30];
    char password_db[30];
    int ID_db;
    int age_f;
    char city_f[30];
    char gender_f[30];
    char number_f[11];
    char first_name_f[20];
    char second_name_f[20];
    char _email[20];
    int _ch_;
    FILE *fn;
    system("cls");

    do
    {
        fn = fopen("subscribe.txt", "r");
        printf("\t|| Login menu ||\n\n");
        printf("\n\tEnter your ID:          ");
        scanf("%d", &ID);
        fflush(stdin);
        printf("\n\tEnter your Password:    ");
        gets(password_);
        fflush(stdin);
        if (fn == NULL)
        {
            printf("\n\tFile could not be open");
            return;
        }

        while (fscanf(fn, "%d %s %s %d %s %s %s %s %s\n", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) != EOF)
        {
            fflush(stdin);
            if ((ID == ID_db) && (strcmp(password_db, password_) == 0))
            {
                fclose(fn);
                printf("\n\tLogin Successfully!!!");
                printf("\n\tPress any key to continue to the Menu");
                getch();
                user_menu(ID);
                return;
            }
        }

        printf("\n\tWrong username or password!!!\n\tTry again!!");
        printf("\n\n\tDo you watnt to Try again? (y-yes | n-no): ");
        fclose(fn);
        scanf("%c", &_ch_);
        fflush(stdin);
        if (_ch_ == 'y' || _ch_ == 'Y')
        {
            continue;
        }
        else if (_ch_ == 'n' || _ch_ == 'N')
        {

            main();
        }

    } while (1);
}

// ................ MENU function...........................//
void user_menu(int ID)
{
    int choose;
top:
    system("cls");
    printf("\n\t-------------------\n\t|| Costumer Menu ||\n\t-------------------\n\n");
    printf("\n\t1. Subscribe plan");
    printf("\n\t2. Claim");
    printf("\n\t3. View transaction details");
    printf("\n\t4. View details");
    printf("\n\t5. view your plan details");
    printf("\n\t6. Exit");
    printf("\n\n\tSelect your option: ");
    scanf("%d", &choose);
    fflush(stdin);

    if (choose == 1)
    {
        subscribe_plan(ID);
        getch();
        user_menu(ID);
    }
    else if (choose == 2)
    {
        claim_process(ID);
        getch();
        user_menu(ID);
    }
    else if (choose == 3)
    {
        transaction_details(ID);
        getch();
        user_menu(ID);
    }
    else if (choose == 4)
    {
        costumer_data(ID);
        getch();
        user_menu(ID);
    }
    else if (choose == 5)
    {
        costumer_plan_type(ID);
        getch();
        user_menu(ID);
    }
    else if (choose == 6)
    {
        main();
    }

    else
    {
        printf("\n\tInvalid optioin");
        char rm;
        printf("\n\tDo you wanto to continue? | 'Y' for yes | and | 'N'| for No ");
        scanf("%s", &rm);
        if (rm == 'y' || rm == 'Y')
        {
            goto top;
        }
        else
        {
            return;
        }
    }
}

void admin()
{
    char password_db[] = "admin@64";
    char username_db[] = "admin";
    char username[10];
    char passowrd[10];

    while (1)
    {
        printf("\n\n\t\t\t|| NOTE: USERNAME: admin and PASSWORD: admin@64 ||\n");
        printf("\n\tUsername: ");
        scanf("%s", &username);
        printf("\n\tPassword: ");
        scanf("%s", &passowrd);

        if (strcmp(password_db, passowrd) == 0 && strcmp(username_db, username) == 0)
        {
            printf("\n\t Admin login successfully\n\n\n");
            admin_menu();
            // return;
        }
        else
        {
            printf("\n\tWrong Id or password");
            char rm;
            printf("\n\tDo you wanto to continue? | 'Y' for yes | and | 'N'| for No ");
            scanf("%s", &rm);
            if (rm == 'y' || rm == 'Y')
            {
                continue;
            }
            else
            {
                return;
            }
        }
    }
}

void admin_menu()
{
    system("cls");
    int a;
top:
    printf("\n\n\t\t|| ADMIN MENU ||\n\n");
    printf("\n\t1. View users");
    printf("\n\t2. View user's plan");
    printf("\n\t3. View user's transaction details");
    printf("\n\t4. Exit");
    printf("\n\n\tEnter your option please: ");
    scanf("%d", &a);

    if (a == 1)
    {
        customer_details();
        getch();
        admin_menu();
    }
    else if (a == 2)
    {
        all_user();
        getch();
        admin_menu();
    }
    else if (a == 3)
    {
        transaction_details_admin();
        getch();
        admin_menu();
    }
    else if (a == 4)
    {
        main();
    }
    else
    {
        printf("\n\tInvalid optioin");
        char rm;
        printf("\n\tDo you wanto to continue? | 'Y' for yes | and | 'N'| for No ");
        scanf("%s", &rm);
        if (rm == 'y' || rm == 'Y')
        {
            goto top;
        }
        else
        {
            main();
        }
    }
}

// creat account function//
void create_account()
{

    char first_name[10];
    char second_name[10];
    int _age;
    char _gender[7];
    char _city[30];
    char _number[11];
    char _password[20];
    char _password_[20];
    char _email[30];
    int ID;

    // deisplaying schemes
    printf("\n\n\n\t\t\t\t\t\t\t\t-----------------------------------\n\t\t\t\t\t\t\t\t||\tWELCOME TO ZeeMediLife\t ||\n\t\t\t\t\t\t\t\t-----------------------------------");
    printf("\n\n\n\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t|| PAYMENT METHOD\t\tPLAN 120\t\tPLAN 150\t\tPLAN 200 ||");
    printf("\n\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t|| Monthly premium\t\t120\t\t\t150\t\t\t200      ||\n");
    printf("\t\t\t\t||\t\t\t\t\t\t\t\t\t\t\t ||");
    printf("\n\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t|| Annual claim limit\t\t120,000\t\t\t150,000\t\t\t200,000  ||\n");
    printf("\t\t\t\t||\t\t\t\t\t\t\t\t\t\t\t ||");
    printf("\n\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t|| Lifetime claim limit\t\t600,000\t\t\t750,000\t\t\t1,000,000||\n");
    printf("\t\t\t\t||\t\t\t\t\t\t\t\t\t\t\t ||");
    printf("\n\t\t\t\t-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t|| Benifits ||\n\n");
    printf("\t\t\t\t*************************************************************************************************************************\n");
    printf("\t\t\t\t\t\t\t\t\t\t\tEligibility Amount(RM)\n\t\t\t\tTypes of Claim\t  -------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\tPlan 120\t\t\t\tPlan 150\t\t\t\tplan200\n");
    printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\tRoom Charges\t\t120/day\t\t\t\t\t150/day\t\t\t\t\t200/day\n\n");
    printf("\n\t\t\t\tICU charges\t\t250/day\t\t\t\t\t400/day\t\t\t\t\t700/day\n");
    printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\tHospital Supplies and\n\t\t\t\tServices\n\t\t\t\t-----------------------");
    printf("\n\t\t\t\tSurgical Fees\t\t\t\t\tAs Charged Subject to approval by ZeeMedLife\n\t\t\t\t-----------------------");
    printf("\n\t\t\t\tOther Fees\n");
    printf("\t\t\t\t*************************************************************************************************************************\n");
    printf("\n\n\t\t\t\tPress any key to continue!");
    getch();
    printf("\n\n\t\t\t\tPLEASE ENTER YOUR DETAILS TO CREATE AN ACCOUNT:\n\n");

    //.................Creat account.......................//

    system("cls");
    printf("\n\tEnter your first name:   ");
    gets(first_name);
    fflush(stdin);
    printf("\n\tEnter your second name:  ");
    gets(second_name);
    fflush(stdin);
    printf("\n\tEnter your Age:          ");
    scanf("%d", &_age);
    fflush(stdin);
    printf("\n\tEnter your gender:       ");
    gets(_gender);
    fflush(stdin);
    printf("\n\tEnter your city name:    ");
    gets(_city);
    fflush(stdin);
    printf("\n\tEnter your phone number: ");
    gets(_number);
    fflush(stdin);
    printf("\n\tEnter your Email:        ");
    gets(_email);
    fflush(stdin);
    system("cls");
    while (1)
    {
        system("cls");
        printf("\tCreate password:      ");
        gets(_password);
        fflush(stdin);
        printf("\n\tRetype your password: ");
        gets(_password_);
        fflush(stdin);
        if (strcmp(_password_, _password) == 0)
        {
            ID = generate_id();
            printf("\n\tYour user id is: %d", ID);
            printf("\n\tRemember your user ID and password!");
            break;
        }
        else
        {
            system("cls");
            printf("\n\n");
            printf("\tyou entered different passwords!!\n");
            printf("\tplease try again\n\n");
            printf("\tpress enter to continue!\n\n");
            getch();
        }
    }

    FILE *fn;
    fn = fopen("subscribe.txt", "a");
    fprintf(fn, "%5d\t%15s\t%15s\t%4d\t%10s\t%15s\t%15s\t%30s\t%10s\n", ID, first_name, second_name, _age, _gender, _city, _number, _email, _password);

    fclose(fn);
    printf("\n\tAccount created Successfully");
    getch();
    return main();
}

int generate_id()
{

    char password_[30];
    char password_db[30];
    int ID_db;
    int age_f;
    char city_f[30];
    char gender_f[30];
    char number_f[11];
    char first_name_f[20];
    char second_name_f[20];
    char _email[20];

    FILE *fn;
    fn = fopen("subscribe.txt", "r");
    int ID = 1000;
    while (fscanf(fn, "%d\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) == 9)
    {
        if (ID_db > ID)
        {
            ID = ID_db;
        }
    }
    fclose(fn);
    return (ID + 1);
}

//...................function for claim..................//

void claim(float expenses, int id)
{
    FILE *fz;
    float cl_amount;
    int id_f, age_f, day, month, year;
    char first_name[20], second_name[20], gender_f[5], city_f[20], plan_type[10], claim_type[10];
    float claimable_amount;
    // printf("\n\t\t\t\t %f\t%d", expenses, id);
    getch();

    fz = fopen("claim_type.txt", "r");
    if (fz == NULL)
    {
        printf("\n\tFile could not be open");
    }

    while (fscanf(fz, "%d %s %s %d %s %s %s %s %f %d %d %d\n", &id_f, first_name, second_name, &age_f, gender_f, city_f, plan_type, claim_type, &claimable_amount, &day, &month, &year) == 12)
    {

        // printf("\n\t\t\t\t%d\t%f", id_f, claimable_amount);getch();
        if (id_f == id)
        {
            if (claimable_amount > expenses)
            {
                // printf("\t\t\\tHello world 2222");
                claimable_amount = claimable_amount - expenses;
                printf("\n\tClaimed successfully");
                fclose(fz);
                update_transaction(id, expenses, first_name, second_name);
            }
            else if (claimable_amount < expenses)
            {
                cl_amount = expenses - claimable_amount;
                printf("\n\tYou can only claim only %f amount", claimable_amount);
                printf("\n\tYou haven't able to claim %f amount because claimable balance doesnot cover all expenses", cl_amount);
                claimable_amount = 0;
                fclose(fz);
                update_transaction(id, claimable_amount, first_name, second_name);
            }
        }
    }
}

//...................function for update transaction..............//
void update_transaction(int _id, float _cost, char First_name[], char Second_name[])
{
    FILE *fy;
    fy = fopen("Transaction.txt", "a");
    time_t rawtime = time(NULL);
    struct tm *ptm;
    ptm = localtime(&rawtime);
    fprintf(fy, "%d %d %s %s %f %d %d %d\n",transaction_id(), _id, First_name, Second_name, _cost, ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
    fclose(fy);
    File_update(_cost, _id);
    return  user_menu(_id);
}

//...................function for generate transaction id.................//
int transaction_id()
{
    int ID_db;
    int tr_id;
    char first_name_f[20];
    char second_name_f[20];
    int cost;
    int day, month, year;

    FILE *fn;
    fn = fopen("Transaction.txt", "r");
    int ID = 1;
    while (fscanf(fn, "%d %d %s %s %f %d %d %d", &tr_id, &ID_db, first_name_f, second_name_f, &cost, &day, &month, &year) == 8)
    {
        // printf("\tUpdate transaction id");
        if (tr_id > ID)
        {
            ID = tr_id;
        }
    }
    fclose(fn);
    return (ID + 1);
}

//..............function for update file...............//
void File_update(float _balance, int _id)

{
    FILE *fk, *fn1;
    // printf("file update");
    // printf("%d %f", _id, _balance);
    time_t rawtime = time(NULL);
    struct tm *ptm;
    int id_f;
    char first_name[20], second_name[20], gender_f[7], city_f[20], plan_type[20], claim_type[20];
    int age_f, day, month, year;
    float balance;
    char old_name[] = "claim_type_TMP.txt";
    char new_name[] = "claim_type.txt";

    fk = fopen("claim_type.txt", "r");
    if (fk == NULL)
    {
        printf("\n\tFile could not be open!");
        return;
    }

    fn1 = fopen("claim_type_TMP.txt", "w");
    if (fn1 = NULL)
    {
        printf("\n\tFile could not be open!");
        return;
    }

    while (fscanf(fk, "%d %s %s %d %s %s %s %s %f %d %d %d", &id_f, first_name, second_name, &age_f, gender_f, city_f, plan_type, claim_type, &balance, &day, &month, &year) == 12)
    {
        if (_id == id_f)
        {
            fprintf(fn1, "%d %15s %s %4d %10s %15s %10s %10s %10f %d/%d/%d\n", id_f, first_name, second_name, age_f, gender_f, city_f, plan_type, claim_type, _balance, ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
        }

        else
        {
            fprintf(fn1, "%d\t%15s %s\t%4d %10s %15s %10s %10s %10f %d/%d/%d\n", id_f, first_name, second_name, age_f, gender_f, city_f, plan_type, claim_type, balance, ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
        }
    }

    fclose(fk);
    fclose(fn1);
    if (!remove(new_name))
    {
        printf("\n\tModifying File.......");
        getch();
    }
    if (!rename(old_name, new_name))
    {
        printf("\n\tFile saved successfully");
    }
    getch();
}

//...............view transaction details of costumers by admin.............//

void transaction_details_admin()
{
    int ID;
    int tr_id;
    char first_name[20];
    char second_name[20];
    float cost;
    int day, month, year;
    int id_f;
    int choise;


    FILE *fn;
    fn = fopen("Transaction.txt", "r");
    if (fn == NULL)
    {
        printf("\n\tFile could not be open!");
        getch();
        return;
    }

    printf("\t 1. View all transaction details.\n");
    printf("\t 2. View specific customer transaction details.\n");
    printf("\tChoose option: ");
    scanf("%d", &choise);

    if (choise == 1)
    {
        while (fscanf(fn, "%d %d %s %s %f %d %d %d", &tr_id, &ID, first_name, second_name, &cost, &day, &month, &year) == 8)
        {
            printf("%d %5d %10s %5s %10.2f %5d/%d/%d\n", tr_id, ID, first_name, second_name, cost, day, month, year);
        }
        fclose(fn);
        getch();
        return admin_menu();
    }
    else if (choise == 2)
    {
        printf("\n\n\tEnter ID: ");
        scanf("%d", &id_f);
        while (fscanf(fn, "%d %d %s %s %f %d %d %d", &tr_id, &ID, first_name, second_name, &cost, &day, &month, &year) == 8)
        {
            if (ID == id_f)
            {
                printf("%d %5d %10s %5s %10.2f %5d/%d/%d\n", tr_id, ID, first_name, second_name, cost, day, month, year);
            }

            // else{
            //     printf("\n\t Data not found..");
            //     getch();
            //     return admin_menu();
            // }
        }
        fclose(fn);
        getch();
        return admin_menu();
    }
    else
    {
        printf("\n\tInvalid Input, Try again..");
        return transaction_details_admin();
    }
}

//.......... view subscription details or insurance plan details by costumers...........//

void costumer_plan_type(int id)
{
    int _id, age_f, day, month, year;
    char f_name[15], s_name[15], gender[10], city[20], plan_type[10], claim_limit[10];
    float _balance;
    FILE *fn;
    fn = fopen("claim_type.txt", "r");
    if (fn == NULL)
    {
        printf("\n\tFile could not be open");
        return;
    }
    // printf("\n\t\t\t\tPlease enter your ID: ");
    // scanf("%d", &id);

    while (fscanf(fn, "%d %s %s %d %s %s %s %s %f %d %d %d\n", &_id, f_name, s_name, &age_f, gender, city, plan_type, claim_limit, &_balance, &day, &month, &year) == 12)
    {

        if (id == _id)
        {
            printf("\n%5d %15s %15s %4d %8s %10s %10s %10s %15.2f %5d/%d/%d\n", _id, f_name, s_name, age_f, gender, city, plan_type, claim_limit, _balance, day, month, year);
        }
    }
    fclose(fn);
    getch();
    return user_menu(id);
}

//.................transaction details for costumers.................//
void transaction_details(int ID)
{
    int tr_id;
    char first_name[20];
    char second_name[20];
    float cost;
    int day, month, year;
    int id_f;

    FILE *fn;
    fn = fopen("Transaction.txt", "r");
    if (fn == NULL)
    {
        printf("\n\tFile could not be open!");
        getch();
        return;
    }
    while (fscanf(fn, "%d %d %s %s %f %d %d %d\n", &tr_id, &id_f, first_name, second_name, &cost, &day, &month, &year) == 8)
    {
        if (ID == id_f)
        {
            printf("%d %5d %10s %5s %10.2f %5d/%d/%d\n", tr_id, ID, first_name, second_name, cost, day, month, year);
        }
    }
    fclose(fn);
    getch();
    return user_menu(ID);
}

//.........costumer data .............//
void costumer_data(int ID)
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

    fc = fopen("subscribe.txt", "r");
    if (fc == NULL)
    {
        printf("File could not be open!");
    }
    ////       1001	        Nirajan	         Dhakal	  20	      Male	        Pokhara	      980000000	          nirajan.44@gmail.com	 nirajan33
    while (fscanf(fc, "%d %s %s %d %s %s %s %s %s\n", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) == 9)
    {
        if (ID == ID_db)
        {
            printf("\n\nUser ID\t\t| Name\t   |   Age |  Gender\t | Address  |  phone number\t   |       Gmail\t|  Password |");
            printf("\n_____________________________________________________________________________________________________________________");
            printf("\n\n %d %15s %s %4d %8s %15s %15s %30s %10s\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, number_f, _email, password_db);
        }
    }
    fclose(fc);
    getch();
    return user_menu(ID);
}

//........view costumers details by admin.........//

void customer_details()
{

    FILE *fa;
    char password_db[30];
    int ID_db;
    int age_f;
    char city_f[30];
    char gender_f[30];
    char number_f[11];
    char first_name_f[20];
    char second_name_f[20];
    char _email[30];
    int choose;
    int ID;
    fa = fopen("subscribe.txt", "r");
    if (fa == NULL)
    {
        printf("File could not be open");
    }
customer_details:
    system("cls");
    printf("\n\t\t\t\t1. View all costumer's details\n\t\t\t\t2. View individual costumer's details\n");
    printf("\n\t\t\t\tEnter your option: ");
    scanf("%d", &choose);
    if (choose == 1)
    {
        printf("\n\nUser ID\t\t| Name\t   |   Age |  Gender\t | Address  |  phone number\t   |       Gmail\t|  Password |");
        printf("\n_____________________________________________________________________________________________________________________");
        while (fscanf(fa, "%d %s %s %d %s %s %s %s %s\n", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) == 9)
        {
            printf("\n%d %15s %s %4d %8s %15s %15s %30s %10s\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, number_f, _email, password_db);
        }
        fclose(fa);
        getch();
        return admin_menu();
    }
    else if (choose == 2)
    {
        printf("\n\t\t\t\tEnter ID: ");
        scanf("%d", &ID);
        while (fscanf(fa, "%d %s %s %d %s %s %s %s %s\n", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) == 9)
        {
            if (ID == ID_db)
            {
                printf("\n\nUser ID\t\t| Name\t   |   Age |  Gender\t | Address  |  phone number\t   |       Gmail\t|  Password |");
                printf("\n_____________________________________________________________________________________________________________________");
                printf("\n\n %d %15s %s %4d %8s %15s %15s %30s %10s\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, number_f, _email, password_db);
            }
        }
        fclose(fa);
        getch();
        return admin_menu();
    }
    else
    {
        printf("\tInvalid option please try again....");
        getch();
        goto customer_details;
    }
}

// ...................function for subscribe plan....................//

void subscribe_plan(int ID)
{
    FILE *fb;
    FILE *fm;
    char first_name_f[10];
    char second_name_f[10];
    char city_f[30];
    char gender_f[7];
    char number_f[11];
    char password_db[20];
    char _email[20];
    int ID_db;
    int age_f;
    int _choise_;
    int _fees;
    char z;
    int days;
    char rl;
    char rm;
    char ch;
    char rn;
    char claim_type[] = "annual";
    char claim_type1[] = "lifetime";
    char plan_type4[] = "plan:150";
    char plan_type[] = "plan:120";
    char plan_type1[] = "plan:150";
    char plan_type2[] = "plan:200";
    char plan_type3[] = "plan:120";
    char plan_type5[] = "plan:200";
    float claimable_amount[5];
    claimable_amount[5] = 1000000;
    claimable_amount[4] = 750000;
    claimable_amount[3] = 600000;
    claimable_amount[2] = 200000;
    claimable_amount[1] = 150000;
    claimable_amount[0] = 120000;
    time_t rawtime = time(NULL);
    struct tm *ptm;
    ptm = localtime(&rawtime);

    fb = fopen("subscribe.txt", "r");
    if (fb == NULL)
    {
        printf("\tFile could not be open");
    }
    fm = fopen("claim_type.txt", "a");
    if (fm == NULL)
    {
        printf("file could not be open");
    }

    while (fscanf(fb, "%d %s %s %d %s %s %s %s %s\n", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, number_f, _email, password_db) == 9)
    {
        if (ID == ID_db)
        {
            if (age_f < 15 || age_f > 54)
            {
                printf("\n\tSorry no service avaliable for you..");
                break;
            }

            else if (age_f >= 41 && age_f <= 54)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t|| Services avaliable for you ||\n\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\t\t\t\tPAYMENT METHOD\t\t\tPLAN 120\t\t\t\tPLAN 150\t\t\t\tPLAN 200\n\t\t\t\t-------------------------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\tMonthly Premium\t\t\tNot Avaliable\t\t\t\tNot Abaliable\t\t\t\t200\n\n");
                printf("\t\t\t\tAnnual Claim Limit\t\tNot Avaliable\t\t\t\tNot Avaliable\t\t\t\t200,000\n\n");
                printf("\t\t\t\tLifetime Claim Limit\t\tNot Avaliable\t\t\t\tNot Avaliable\t\t\t\t1,000,000\n");
                printf("\t\t\t\t*************************************************************************************************************************\n\n\n\n");
                printf("\n\t\t\t\t\t\t\t\t\t\t|| Benifits ||\n\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t\tEligibility Amount(RM)\n\t\t\t\tTypes of Claim\t  -------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\t\t\t\tPlan 120\t\t\t\tPlan 150\t\t\t\tplan200\n");
                printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\tRoom Charges\t\t120/day\t\t\t\t\t150/day\t\t\t\t\t200/day\n\n");
                printf("\n\t\t\t\tICU charges\t\t250/day\t\t\t\t\t400/day\t\t\t\t\t700/day\n");
                printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\tHospital Supplies and\n\t\t\t\tServices\n\t\t\t\t-----------------------");
                printf("\n\t\t\t\tSurgical Fees\t\t\t\t\tAs Charged Subject to approval by ZeeMedLife\n\t\t\t\t-----------------------");
                printf("\n\t\t\t\tOther Fees\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\tPress any key to continue!");
                getch();
            }
            else if (age_f <= 20)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t|| Services avaliable for you ||\n\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\t\t\t\tPAYMENT METHOD\t\t\tPLAN 120\t\t\t\tPLAN 150\t\t\t\tPLAN 200\n\t\t\t\t-------------------------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\tMonthly Premium\t\t\t120\t\t\t\t\t150\t\t\t\t\t200\n\n");
                printf("\t\t\t\tAnnual Claim Limit\t\t120,000\t\t\t\t\t150,000\t\t\t\t\t200,000\n\n");
                printf("\t\t\t\tLifetime Claim Limit\t\t600,000\t\t\t\t\t750,000\t\t\t\t\t1,000,000\n");
                printf("\t\t\t\t*************************************************************************************************************************\n\n\n\n");
                printf("\n\t\t\t\t\t\t\t\t\t\t|| Benifits ||\n\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t\tEligibility Amount(RM)\n\t\t\t\tTypes of Claim\t  -------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\t\t\t\tPlan 120\t\t\t\tPlan 150\t\t\t\tplan200\n");
                printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\tRoom Charges\t\t120/day\t\t\t\t\t150/day\t\t\t\t\t200/day\n\n");
                printf("\n\t\t\t\tICU charges\t\t250/day\t\t\t\t\t400/day\t\t\t\t\t700/day\n");
                printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\tHospital Supplies and\n\t\t\t\tServices\n\t\t\t\t-----------------------");
                printf("\n\t\t\t\tSurgical Fees\t\t\t\t\tAs Charged Subject to approval by ZeeMedLife\n\t\t\t\t-----------------------");
                printf("\n\t\t\t\tOther Fees\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\n\tPress any key to continue!");
                getch();
            }
            else if (age_f >= 21 && age_f <= 40)
            {
                printf("\n\n\t\t\t\t\t\t\t\t\t|| Services avaliable for you ||\n\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\t\t\t\tPAYMENT METHOD\t\t\tPLAN 120\t\t\t\tPLAN 150\t\t\t\tPLAN 200\n\t\t\t\t-------------------------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\tMonthly Premium\t\t\tNot Avaliable\t\t\t\t150\t\t\t\t\t200\n\n");
                printf("\t\t\t\tAnnual Claim Limit\t\tNot Avaliable\t\t\t\t150,000\t\t\t\t\t200,000\n\n");
                printf("\t\t\t\tLifetime Claim Limit\t\tNot Avaliable\t\t\t\t750,000\t\t\t\t\t1,000,000\n");
                printf("\t\t\t\t*************************************************************************************************************************\n\n\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t\t\t|| Benifits ||\n\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\t\t\t\t\t\t\t\t\t\t\tEligibility Amount(RM)\n\t\t\t\tTypes of Claim\t  -------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\t\t\t\tPlan 120\t\t\t\tPlan 150\t\t\t\tplan200\n");
                printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\tRoom Charges\t\t120/day\t\t\t\t\t150/day\t\t\t\t\t200/day\n\n");
                printf("\n\t\t\t\tICU charges\t\t250/day\t\t\t\t\t400/day\t\t\t\t\t700/day\n");
                printf("\t\t\t\t-------------------------------------------------------------------------------------------------------------------------");
                printf("\n\t\t\t\tHospital Supplies and\n\t\t\t\tServices\n\t\t\t\t-----------------------");
                printf("\n\t\t\t\tSurgical Fees\t\t\t\t\tAs Charged Subject to approval by ZeeMedLife\n\t\t\t\t-----------------------");
                printf("\n\t\t\t\tOther Fees\n");
                printf("\t\t\t\t*************************************************************************************************************************\n");
                printf("\n\tPress any key to continue!");
                getch();
            }
            else
            {
                printf("\n\tYou are not eligible for Insurance!");
                break;
            }

            system("cls");
        top:
            printf("\n\tSelect your claim type\n");
            printf("\n\t a.annual claim limit\n\t l.Lifetime claim limit\n\n");
            printf("\n\n\tSelect your option: ");
            scanf("%s", &z);
            if (z == 'a')
            {
            top_head:
                system("cls");
                printf("\n\tyou have selected annual claim limit");
                printf("\n\t 1.plan 120\n\t 2.Plan 150\n\t 3.plan 200");
                printf("\n\n\tSelect your option: ");

                scanf("%d", &_choise_);
                if (_choise_ == 1)
                {
                    if (age_f <= 20)
                    {
                        printf("\n\tYou have selected plan 120");
                        fprintf(fm, "%5d\t%15s\t%15s\t%4d\t%10s\t%15s\t%10s\t%10s\t%.2f\t%d %d %d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type, claim_type, claimable_amount[0], ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
                        printf("\n\n\t Annually claimable amount : %.2f", claimable_amount[0]);
                        getch();
                        fclose(fm);
                        return user_menu(ID);
                    }
                    else
                    {
                        printf("\n\t You are not eligible");
                        printf("\n\t Press any key to continue");
                        getch();
                        goto top_head;
                    }
                }

                else if (_choise_ == 2)
                {
                    if (age_f <= 40)
                    {
                        printf("\n\tYou have selected plan:150");
                        fprintf(fm, "%5d\t%15s\t%15s\t%4d\t%10s\t%15s\t%10s\t%10s\t%.2f\t%d %d %d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type1, claim_type, claimable_amount[1], ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
                        printf("\n\n\tAnually claimable amount : %.2f", claimable_amount[1]);
                        getch();
                        fclose(fm);
                        return user_menu(ID);
                    }
                    else
                    {
                        printf("\n\t You are not eligible");
                        printf("\n\t Press any key to continue");
                        getch();
                        goto top_head;
                    }
                }

                else if (_choise_ == 3)
                {
                    if (age_f <= 54)
                    {
                        printf("\n\tYou have selected plan 200");
                        fprintf(fm, "%5d\t%15s\t%15s\t%4d\t%10s\t%15s\t%10s\t%10s\t %.2f\t%d %d %d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type2, claim_type, claimable_amount[2], ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
                        printf("\n\n\tAnually claimable amount : %.2f", claimable_amount[2]);
                        getch();
                        fclose(fm);
                        return user_menu(ID);
                    }
                    else
                    {
                        printf("\n\t You are not eligible");
                        printf("\n\t Press any key to continue");
                        getch();
                        goto top_head;
                    }
                }
                else
                {
                    printf("\n\tInvalid optioin");
                    printf("\n\tDo you wanto to continue? | 'Y' for yes | and | 'N'| for No ");
                    scanf("%s", &rn);
                    if (rn == 'y' || rn == 'Y')
                    {
                        goto top_head;
                    }
                    else
                    {
                        return user_menu(ID);
                    }
                }
            }

            //.............................for lifetile claim limit................................//

            else if (z == 'l')
            {
            head_top:
                printf("\n\tyou have selected lifetime claim limit");
                printf("\n\t 1.plan 120\n\t 2.Plan 150\n\t 3.plan 200");
                printf("\n\n\tSelect your option: ");
                scanf("%d", &_choise_);
                if (_choise_ == 1)
                {
                    if (age_f <= 20)
                    {
                        printf("\n\tYou have selected plan:120");
                        fprintf(fm, "%5d\t%15s\t%15s\t%4d\t%10s\t%15s\t%10s\t%10s\t%.2f\t%d %d %d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type3, claim_type1, claimable_amount[3], ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
                        printf("\n\n\tLifetime claimable amount : %.2f", claimable_amount[3]);
                        getch();
                        fclose(fm);
                        return user_menu(ID);
                    }
                    else
                    {
                        printf("\n\t You are not eligible");
                        printf("\n\t Press any key to continue");
                        getch();
                        goto head_top;
                    }
                }
                else if (_choise_ == 2)
                {
                    if (age_f <= 40)
                    {
                        printf("\n\tYou have selected plan 150");
                        fprintf(fm, "%5d\t%15s\t%15s\t%4d\t%10s\t%15s\t%10s\t%10s\t%.2f\t%d %d %d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type4, claim_type1, claimable_amount[4], ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
                        printf("\n\n\tLifetime claimable amount : %.2f", claimable_amount[4]);
                        getch();
                        fclose(fm);
                        return user_menu(ID);
                    }
                    else
                    {
                        printf("\n\t You are not eligible");
                        printf("\n\t Press any key to continue");
                        getch();
                        goto head_top;
                    }
                }
                else if (_choise_ == 3)
                {
                    if (age_f <= 54)
                    {
                        printf("\n\tYou have selected plan:200");
                        fprintf(fm, "%5d\t%15s\t%15s\t%4d\t%10s\t%15s\t%10s\t%10s\t %.2f\t%d %d %d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type5, claim_type1, claimable_amount[5], ptm->tm_mday, ptm->tm_mon + 1, ptm->tm_year + 1900);
                        printf("\n\n\tLifetime claimable amount : %.2f", claimable_amount[5]);
                        getch();
                        fclose(fm);
                        return user_menu(ID);
                    }
                    else
                    {
                        printf("\n\t You are not eligible");
                        getch();
                        printf("\n\t Press any key to continue");
                        goto head_top;
                    }
                }
                else
                {
                    printf("\n\tInvalid optioin");
                    printf("\n\tDo you wanto to continue? | 'Y' for yes | and | 'N'| for No ");
                    scanf("%s", &rl);
                    if (rl == 'y' || rl == 'Y')
                    {
                        goto head_top;
                    }
                    else
                    {
                        return;
                    }
                }
            }

            else
            {
                printf("\n\tInvalid optioin");
                printf("\n\tDo you wanto to continue? | 'Y' for yes | and | 'N'| for No ");
                scanf("%s", &rm);
                if (rm == 'y' || rm == 'Y')
                {
                    goto top;
                }
                else
                {
                    return;
                }
            }
        }
    }
}

//........view costumers plan..........//

void all_user()
{

    FILE *fd;
    int choose, option, _option;
    char _choose[10];
    char first_name_f[10];
    char second_name_f[10];
    int age_f, day, month, year;
    char city_f[30];
    char gender_f[7];
    char plan_type[8];
    int ID_db;
    char claim_limit[10];
    float balance_f;
    fd = fopen("claim_type.txt", "r");
    if (fd == NULL)
    {
        printf("File could not be open");
    }
you:
    printf("\t1. choose costumer type\n\t2. All costumer");
    printf("\n\tChoose your option: ");
    scanf("%d", &option);
    fflush(stdin);
    if (option == 2)
    {
        while (fscanf(fd, "%d %s %s %d %s %s %s %s %f %d %d %d", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, plan_type, claim_limit, &balance_f, &day, &month, &year) == 12)
        {
            printf("\n%5d %15s %15s %4d %8s %10s %10s %10s %15.2f %5d/%d/%d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type, claim_limit, balance_f, day, month, year);
        }
        fclose(fd);
    }
    else if (option == 1)
    {
    me:
        printf("\t1. Search by ID and Age\n\t2. Search by claim limit and plan type");
        printf("\n\tChoose your option: ");
        scanf("%d", &_option);
        fflush(stdin);
        if (_option == 1)
        {
            printf("\tEnter Age or ID: ");
            scanf("%d", &choose);
            fflush(stdin);
            while (fscanf(fd, "%d %s %s %d %s %s %s %s %f %d %d %d", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, plan_type, claim_limit, &balance_f, &day, &month, &year) == 12)
            {
                if (age_f == choose || ID_db == choose)
                {
                    printf("\n%5d %15s %15s %4d %8s %10s %10s %10s %15.2f %5d/%d/%d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type, claim_limit, balance_f, day, month, year);
                }
            }
            fclose(fd);
        }
        else if (_option == 2)
        {
            printf("\tEnter your claim limit or Plan type: ");
            scanf("%s", _choose);
            fflush(stdin);
            printf("%s", _choose);
            getch();
            while (fscanf(fd, "%d %s %s %d %s %s %s %s %f %d %d %d", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, plan_type, claim_limit, &balance_f, &day, &month, &year) == 12)
            {
                if ((strcmp(_choose, plan_type) == 0) || (strcmp(_choose, claim_limit) == 0))
                {
                    printf("\n%5d %15s %15s %4d %8s %10s %10s %10s %15.2f %5d/%d/%d\n", ID_db, first_name_f, second_name_f, age_f, gender_f, city_f, plan_type, claim_limit, balance_f, day, month, year);
                }
            }
            fclose(fd);
        }
        else
        {
            printf("\tInvalid option");
            printf("\n\tress any key to continue\n");
            getch();
            goto me;
        }
    }
    else
    {
        printf("\n\tInvalid option");
        printf("\n\tpress any key to continue\n");
        getch();
        goto you;
    }
}

//........claim process.............//
void claim_process(int ID)
{
    FILE *fh;
    int days;
    char first_name_f[10];
    char second_name_f[10];
    int age_f, day, month, year;
    char city_f[30];
    char gender_f[7];
    char plan_type[8];
    int ID_db;
    char claim_limit[10];
    float balance_f;
    int opt;
    int sefee, sfee, ofee;
    float total_expenses = 0;
    fh = fopen("claim_type.txt", "r");
    if (fh == NULL)
    {
        printf("File could not be open");
    }
    // printf("Enter your ID: ");
    // scanf("%d",&test_id); fflush(stdin);
    while (fscanf(fh, "%d %s %s %d %s %s %s %s %f %d %d %d\n", &ID_db, first_name_f, second_name_f, &age_f, gender_f, city_f, plan_type, claim_limit, &balance_f, &day, &month, &year) == 12)
    {

        if (ID == ID_db)
        {
            // printf(plan_type);
            if (strcmp(plan_type, "plan:150") == 0)
            {
                // printf("\t\t\t\tPlan type 150");
                getch();
                printf("\n\tDid you use hospital room?\n");
                printf("\n\t1. Yes\n\t2. NO");
                printf("\n\tSelect your option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    printf("\n\tHow many days do you spend in hospital rooms ?: ");
                    scanf("%d", &days);
                    total_expenses = total_expenses + days * 150;
                }
                

                printf("\n\tDid you use ICU?");
                printf("\n\t1. Yes\n\t2. NO\n");
                printf("\n\tChoose option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    printf("\n\tHow many days do you use ICU?: ");
                    scanf("%d", &days);
                    fflush(stdin);
                    total_expenses = total_expenses + (days * 400);
                }
                

                printf("\n\tAny surgery?\n");
                printf("\n\t1. Yes\n\t2. No\n");
                printf("\n\tChoose option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    printf("\n\tEnter surgery fee: ");
                    scanf("%d", &sfee);
                    fflush(stdin);
                    total_expenses = total_expenses + sfee;
                }
                
                

                printf("\n\tHospital supplies and service fees: ");
                scanf("%d", &sefee);
                fflush(stdin);
                printf("\n\tOther fees: ");
                scanf("%d", &ofee);
                fflush(stdin);
                total_expenses = total_expenses + sefee + ofee;
                printf("\n\tTotal expenses = %f", total_expenses);
                claim(total_expenses, ID_db);
                File_update(total_expenses, ID_db);
            }
            else if (strcmp(plan_type, "plan:120") == 0)
            {
                printf("\n\tDid you use hospital room?\n");
                printf("\n\t1. Yes\n\t2. NO");
                printf("\n\tSelect your option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    printf("\n\tHow many days do you spend in hospital rooms ?: ");
                    scanf("%d", &days);
                    fflush(stdin);
                    total_expenses = total_expenses + days * 120;
                }
                
                

                printf("\n\tDid you use ICU?");
                printf("\n\t1. Yes\n\t2. NO");
                printf("\n\tSelect your option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    int Days;
                    printf("\n\tHow many days do you use ICU?: ");
                    scanf("%d", &days);
                    fflush(stdin);
                    total_expenses = total_expenses + (days * 250);
                }
                
                printf("\n\tIf you did surgery?");
                printf("\n\t1. Yes\n\t2. NO");
                printf("\n\tSelect your option: ");
                scanf("%d", &opt);
                if (opt == 1)
                {
                    printf("\n\tEnter surgery fee: ");
                    scanf("%d", &sfee);
                    fflush(stdin);
                    total_expenses = total_expenses + sfee;
                }
                

                printf("\n\tHospital supplies and service fees: ");
                scanf("%d", &sefee);
                fflush(stdin);
                printf("\n\tOther fees: ");
                scanf("%d", &ofee);
                fflush(stdin);
                total_expenses = total_expenses + sefee + ofee;
                printf("\n\tTotal expenses = %f", total_expenses);
                claim(total_expenses, ID_db);
                File_update(total_expenses, ID_db);
            }

            else if (strcmp(plan_type, "plan:200") == 0)
            {
                printf("\n\tDid you use hospital room?\n");
                printf("\n\t1. Yes\n\t2. NO");
                printf("\n\tSelect your option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    printf("\n\tHow many days do you spend in hospital rooms ?");
                    scanf("%d", &days);
                    fflush(stdin);
                    total_expenses = total_expenses + days * 200;
                }
                

                printf("\n\tDid you use ICU?");
                printf("\n\t1. Yes\n\t2. NO");
                printf("\n\tSelect your option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    printf("\n\tHow many days do you use ICU?: ");
                    scanf("%d", &days);
                    total_expenses = total_expenses + (days * 700);
                }
                

                printf("\n\tAny surgery?");
                printf("\n\t1. Yes\n\t2. NO");
                printf("\n\tSelect your option: ");
                scanf("%d", &opt);
                fflush(stdin);
                if (opt == 1)
                {
                    printf("\n\tEnter surgery fee: ");
                    scanf("%d", &sfee);
                    fflush(stdin);
                    total_expenses = total_expenses + sfee;
                }
                

                printf("\n\tHospital supplies and service fees: ");
                scanf("%d", &sefee);
                fflush(stdin);
                printf("\n\tOther fees: ");
                scanf("%d", &ofee);
                fflush(stdin);
                total_expenses = total_expenses + sefee + ofee;
                printf("\n\tTotal expenses = %f", total_expenses);
                getch();

                claim(total_expenses, ID_db);
                File_update(total_expenses, ID_db);
            }
        }
    }
}
