#include<stdio.h>
#include<conio.h> // used for delay(), getch() etc
#include<windows.h> //gotoxy()
#include<string.h> //use for strcomp(), strcopy(), strlen() etc
#include<ctype.h> //use for toupper(), tolower(), etc
#include<stdlib.h>

char ans = 0;
int ok;
int b, valid = 0;

// functions being declared
void WelcomeScreen(void); // WelcomeScreen function
void Title(void); //Title function
void MainMenu(void); // Main Menu function
void LoginScreen(void); // Login Screen function
void Add_rec(void); // function to Add patient record
void Search_rec(void); // function to search patent record
void Edit_rec(void); // function to edit patient record
void Dlt_rec(void); // function to delete patient record
void ex_it(void); // exit function

void gotoxy(short x, short y)
{
	COORD pos = {x, y}; // sets co-ordinates in (x,y)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// global variables
struct patient
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};

struct patient p, temp_c;
main(void)
{
	WelcomeScreen();
	Title();
	LoginScreen();
}

void WelcomeScreen(void)
{	printf("\n\n\n\n\n\n\n\t\t\t\t##########################################");
	printf("\n\t\t\t\t#\t\t Welcome to \t \t#");
	printf("\t\t\t\n Sans Hospital \n");
	printf("\n\n\n\n\n\n\n\t\t\t\t##########################################");
	printf("\n\n\n\n\n Press any key to continue");
	getch();
	system("cls"); //clearing the screen here
}


void Title(void)
{
	printf("\n\n\t\t ----------------------------------------------------------");
	printf("\n\t\t\t\t Sans Hospital        ");
	printf("\n\t\t-------------------------------------------------------------");
}


void MainMenu(void)
{
	system("cls");
	int choose;
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n\n\t\t\t\t Choose from 1 to 6: ");
	scanf("%d", &choose);
	
	switch(choose)
	{
		case 1:
			Add_rec();
			break;
		case 2:
			func_list();
			break;
		case 3:
			Search_rec();
			break;
		case 4:
			Edit_rec();
			break;
		case 5:
			Dlt_rec();
			break;
		case 6:
			ex_it();
			break;
		default:
			printf("\t\t\t Invalid entry. Please enter correct option: ");
			getch();	
	}
}

void ex_it(void)
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tThank you for visiting. ");
	getch();
}

void LoginScreen(void)
{
	int e = 0;
	char Username[25];
	char Password[15];
	char original_Username[25]="shiva";
	char original_Password[15]="1234";
	do
	{
		printf("\n\n\n\n\t\t\t\t Enter your Username and Password: ");
		printf("\n\n\n\t\t\t\t\t Username: ");
		scanf("%s", &Username);
		printf("\n\n\t\t\t\t\t Password: ");
		scanf("%s", &Password);
		if (strcmp(Username, original_Username) == 0 && strcmp(Password, original_Password) == 0)
		{
			printf("\n\n\n\t\t\t\t\t Login Successful ");
			getch();
			MainMenu();
			break;
		}
		else 
		{
			printf("\n\t\t\t Password is incorrect. Please Try Again. ");
			e++;
			getch();
		}
	} 
	while (e <= 2);
	
	if(e>3)
	{
		printf("You have crossed the limit. Exiting program.");
		getch();
		ex_it();
	}
	system("cls");
	
}

void Add_rec(void)
{
	system("cls");
	Title();
	char ans;
	FILE*ek;
	ek=fopen("Record2.dat", "a"); //opening the file in write mode
	printf("\n\n\t\t\t\t Add Patient Record \n");
	
	A:
	printf("\n\t\t\t First Name: ");
	scanf("%s", p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name) > 20 || strlen(p.First_Name) < 2)
	{
		printf("\n\t Invalid name entered. Pls check number of characters in name.\n");
		goto A;
	}
	else
	{
		for(b = 0; b < strlen(p.First_Name); b++)
		{
			if(isalpha(p.First_Name[b]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First Name contains invalid characters. Please try again.\n");
			goto A;
		}
	}
	
	B:
	printf("\n\t\t\t Last Name: ");
	scanf("%s", p.Last_Name);
	p.Last_Name[0]=toupper(p.Last_Name[0]);
	if(strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 2)
	{
		printf("\n\t Invalid name entered. Pls check number of characters in name.\n");
		goto B;
	}
	else
	{
		for(b = 0; b < strlen(p.Last_Name); b++)
		{
			if(isalpha(p.Last_Name[b]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last Name contains invalid characters. Please try again.\n");
			goto B;
		}
	}
}
