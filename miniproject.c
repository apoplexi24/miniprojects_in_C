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
