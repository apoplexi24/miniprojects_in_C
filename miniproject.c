#include<stdio.h>
#include<conio.h> // used for delay(), getch() etc
#include<windows.h> //gotoxy()
#include<string.h> //use for strcomp(), strcopy(), strlen() etc
#include<ctype.h> //use for toupper(), tolower(), etc
#include<stdlib.h>

char ans = 0;
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
void func_list(void);
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
	char Last_Name[10];
	char Contact_no[15];
	char Email[20];
	char Doctor[20];
	char Problem[20];
};

struct patient p, temp_c;
main(void)
{
	WelcomeScreen();
	Title();
//	LoginScreen();
	MainMenu();
}

void WelcomeScreen(void)
{	printf("\n\n\n\n\n\n\n\t\t\t\t##########################################");
	printf("\n\t\t\t\t#\t\t Welcome to \t \t#");
	printf("\n\t\t\t\t\t      JUPITER HOSPITAL \n");
	printf("\n\n\n\n\n\t\t\t\t##########################################");
	printf("\n\n\n\n\n Press any key to continue");
	getch();
	system("cls"); //clearing the screen here
}


void Title(void)
{
	printf("\n\n\t\t -------------------------------------------------------------");
	printf("\n\n\t\t                       JUPITER HOSPITAL        ");
	printf("\n\n\t\t -------------------------------------------------------------");
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
	scanf("%i", &choose);
	
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
	
	if(e > 3)
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
	ek = fopen("Record2.txt", "a"); //opening the file in write mode
	printf("\n\n\t\t\t\t Add Patient Record \n");
	
	int A = 0;
	do
	{
		A = 0;
		printf("\n\t\t\t First Name: ");
		scanf("%s", p.First_Name);
		p.First_Name[0]=toupper(p.First_Name[0]);
		if(strlen(p.First_Name) > 20 || strlen(p.First_Name) < 2)
		{
			printf("\n\t Invalid name entered. Pls check number of characters in name.\n");
			A = 1;
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
				A = 1;
			}
		}
	}
	while (A != 0);
	
	int B = 0;
	do
	{
		B = 0;
		printf("\n\t\t\t Last Name: ");
		scanf("%s", p.Last_Name);
		p.Last_Name[0]=toupper(p.Last_Name[0]);
		if(strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 2)
		{
			printf("\n\t Invalid name entered. Pls check number of characters in name.\n");
			B = 1;
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
				B = 1;
			}
		}
	}
	while (B != 0);
	
	// Gender of Patient entry

	do
	{
		B = 0;
		printf("\n\t\t\t Gender[F/M]: ");
		scanf(" %c", &p.Gender);
		if(toupper(p.Gender) == 'M' || toupper(p.Gender) == 'F')
		{
			B = 0;
		}
		else
		{
			printf("\n\t\t Gender field contains Invalid Character. Please enter either F or M.");	
			B = 1;
		}
	}
	while(B != 0);
	
	//Age entry
	printf("\n\t\t\t Age: ");
	scanf(" %i", &p.age);

	// Contact number
	int D = 0;
	do
	{
		D = 0;
		printf("\n\t\t\t Contact no: ");
		scanf("%s",p.Contact_no);
		if(strlen(p.Contact_no) != 10)
		{
			printf("\n\t Invalid Entry. Contact number must contain 10 numbers. Please enter number again.");
			D = 1;
		}
		else
		{
			for(b = 0; b < strlen(p.Contact_no);b++)
			{
				if(!isalpha(p.Contact_no[b]))
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
				printf("\n\t\t Contact number contains invalid characters. Please enter number again.");
				D = 1;
			}
		}
	}
	while(D != 0);
	
	// email entry
	do
	{
		{
		printf("\n\t\t\t Email: ");
		scanf("%s", p.Email);
		if(strlen(p.Email) > 20 || strlen(p.Email) < 8)
		printf("\n\t Invalid Entry. Range of email is 8 chars to 30 chars. Please enter email again. ");
		}
	}
	while(strlen(p.Email) > 20 || strlen(p.Email) < 8);
	
	// Problem entry
	
	int E = 0;
	do
	{
		E = 0;
		printf("\n\t\t\t Problem: ");
		scanf("%s", p.Problem);
		p.Problem[0] = toupper(p.Problem[0]);
		if(strlen(p.Problem) > 15 || strlen(p.Problem) < 3)
		{
			printf("\n\t Invalid Entry. Range of problem is from 3 chars to 15 chars.");
			E = 1;
		}
		else 
		{
			for(b = 0; b < strlen(p.Problem); b++)
			{
				if (isalpha(p.Problem[b]))
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
				printf("\n\t\t Problem contains invalid characters. Please enter problem again. ");
				E = 1;
			}
		}
	}
	while(E != 0);
	
	// prescribed doctor 
	int F = 0;
	do
	{
		F = 0;
		printf("\n\t\t\t Prescribed Doctor: ");
		scanf("%s", p.Doctor);
		p.Doctor[0]=toupper(p.Doctor[0]);
		if (strlen(p.Doctor) > 15 || strlen(p.Doctor) < 3)
		{
			printf("\n\t Invalid Entry. Range of Doctor name is 3 chars to 15 chars.");
			F = 1;
		}
		else
		{
			for(b = 0; b < strlen(p.Doctor); b++)
			{
				if(isalpha(p.Doctor[b]))
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if(valid == 0)
			{
				printf("\n\t\t Doctor Name contains invalid characters. Please enter Doctor name again.");
				F = 1;
			}
		}
	}
	while (F != 0);
	
	fprintf(ek, " %s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.Email, p.Problem, p.Doctor);
	printf("\n\n\t\t\t Information Recorded Successfully");
	fclose(ek); // ek file is closed
	
	int G = 0;
	do
	{
		G = 0;
		getch();
		printf("\n\n\t\t\t Do you want more records [Y/N]?: ");
		scanf(" %c", &ans);
		if(toupper(ans) == 'Y')
		{
			Add_rec();
		}
		else if(toupper(ans)=='N')
		{
			printf("\n\t\t Thank You. ");
			getch();
			MainMenu();
		}
		else
		{
			printf("\n\t\t Invalid Input \n");
			G = 1;
		}
	}
	while(G != 0);
}

// display records of patients
void func_list()
{
	int num = 1;
	system("cls");
	Title();
	FILE*ek;
	ek=fopen("Record2.txt","r");
	printf("\n\n\t\t\t\tList of Patient Records\n");
	while(fscanf(ek,"%s %s %c %i %s %s %s %s\n", &p.First_Name, &p.Last_Name, &p.Gender, &p.age, &p.Contact_no, &p.Email, &p.Problem, &p.Doctor)!=EOF)
	{
		printf("Patient Number - %d", num);
		printf("\n");
		printf("Full Name: ");
		printf("%s %s \n", p.First_Name, p.Last_Name);
		printf("Gender: %c \n", p.Gender);
		printf("Age: %i \n", p.age);
		printf("Email : %s \n", p.Email);
		printf("Contact Number: %s \n", p.Contact_no);
		printf("Problem: %s \n", p.Problem);
		printf("Assigned Doctor: %s \n \n", p.Doctor);
		num++;
	}

	fclose(ek);
	getch();
	MainMenu();
}

void Search_rec(void)
{
	char name[20];
	system("cls");
	Title(); //calling the Title function
	FILE *ek;
	ek=fopen("Record2.txt","r");
	printf("\n\n\t\t\t\tSearch Patient Records\n\n");
	gotoxy(12,8);
	printf("\n Enter the Patient Name to be viewed: ");
	scanf("%s",name);
	printf("\n\n");
	fflush(stdin); // clears output buffer
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if(strcmp(p.First_Name, name)==0)
		{
			printf("Patient Details of %s %s", p.First_Name, p.Last_Name);
			printf("\n");
			printf("Full Name: ");
			printf("%s %s \n", p.First_Name, p.Last_Name);
			printf("Gender: %c \n", p.Gender);
			printf("Age: %i \n", p.age);
			printf("Email : %s \n", p.Email);
			printf("Contact Number: %s \n", p.Contact_no);
			printf("Problem: %s \n", p.Problem);
			printf("Assigned Doctor: %s \n \n", p.Doctor);
		}
	}
	if(strcmp(p.First_Name, name)!=0)
	{
		gotoxy(5,10);
		printf("Record not found.");
		getch();
	}
	fclose(ek);
	int A;
	do
	{
		A = 0;
		getch();
		printf("\n\n\t\t\tDo you want to view more?[Y/N]");
		scanf("%c",&ans);
		if(toupper(ans)=='Y')
		{
			Search_rec();
		}
		else if(toupper(ans)=='N')
		{
			printf("\n\t\t Thank You!");
			getch();
			MainMenu();
		}
		else
		{
			printf("\n\tInvalid Input.\n");
			A = 1;
		}
	}
	while(A != 0);
}

void Edit_rec(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.txt","w+");
	   ek=fopen("Record2.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		MainMenu();
	   }
       	printf("\n\n\t\t\t Edit Patients Record \n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Patient : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			MainMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
		{
			if(strcmp(p.First_Name, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				printf("Patient Details of %s %s", p.First_Name, p.Last_Name);
				printf("\n");
				printf("Full Name: ");
				printf("%s %s \n", p.First_Name, p.Last_Name);
				printf("Gender: %c \n", p.Gender);
				printf("Age: %i \n", p.age);
				printf("Email : %s \n", p.Email);
				printf("Contact Number: %s \n", p.Contact_no);
				printf("Problem: %s \n", p.Problem);
				printf("Assigned Doctor: %s \n", p.Doctor);
				printf("\n \n \n New Record Details\n\n");
				printf("Enter New First Name: ");
				scanf("%s",p.First_Name);    
				printf("Enter Last Name: ");
				scanf("%s",p.Last_Name);
				printf("Enter Gender: ");
				scanf(" %c",&p.Gender);
				p.Gender=toupper(p.Gender);
				printf("Enter age: ");
				scanf(" %i",&p.age);
				printf("Enter Contact no: ");
				scanf("%s",p.Contact_no);
				printf("Enter New email: ");
				scanf("%s",p.Email);
				printf("Enter Problem: ");
				scanf("%s",p.Problem);
				p.Problem[0]=toupper(p.Problem[0]);
				printf("Enter Doctor: ");
			    scanf("%s",p.Doctor);
			    p.Doctor[0]=toupper(p.Doctor[0]);
			    printf("\nPress U charecter for the Uptxting operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Contact_no,p.Email,p.Problem,p.Doctor);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Contact_no,p.Email,p.Problem,p.Doctor);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("Record2.txt");
   	   rename("temp2.txt","Record2.txt");
		getch();
		MainMenu();		
}


void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp_file2.txt","w+");
	ek=fopen("Record2.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %c %i %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
			 &p.age, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.Email, p.Problem, p.Doctor);
		else 
		{
			printf("%s %s %c %i %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Contact_no, p.Email, p.Problem, p.Doctor);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		MainMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record2.txt");
		rename("temp_file2.txt","Record2.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		MainMenu();
	}
} 

