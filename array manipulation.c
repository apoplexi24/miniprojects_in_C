#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void insertpos_array();
void insert_beginning();
void insert_end();
void delpos_array();
void del_first();
void search_pos();
void search_element();
void reverse_array();

int main()
{
	while(1)
	{
		int choose;
		printf("\t\tMain Menu\n\n\t1) Insert at a position in the array.\n\t2) Insertion at beginning.");
		printf("\n\t3) Insert at end.\n\t4) Delete by position.\n\t5) Delete by element.\n\t6) Search by position.");
		printf("\n\t7) Search by element.\n\t8) Revert the array.\n\t9) Exit the program.\n\n");
		printf("Enter choice- ");
		scanf("%d", &choose);
		printf("\n");
		char number[8];
		switch(choose)
		{
			case 1:
				insertpos_array();
				getch();
				system("cls");
				break;
		
			case 2:
				insert_beginning();
				getch();
				system("cls");
				break;
			
			case 3:
				insert_end();
				getch();
				system("cls");
				break;
		
			case 4:
				delpos_array();
				getch();
				system("cls");
				break;
		
			case 5:
				del_first();
				getch();
				system("cls");
				break;
			
			case 6:
				search_pos();
				getch();
				system("cls");
				break;
			
			case 7:
				search_element();
				getch();
				system("cls");
				break;
				
			case 8:
				reverse_array();
				getch();
				system("cls");
				break;
			
			case 9:
				printf("End of Program.");
				exit(0);
				break;
		}	
	}
	
}
 
void insertpos_array()
{
	int n;
	printf("Enter size of array - ");
	scanf("%d", &n);
	int *arr = 0;
	arr = (int*) malloc ((n+2) * sizeof(int));
    int i, x, pos;
 	
 	printf("\nEnter %d elements: \n", n);
 	
 	for (i = 0; i < n; i++)
 	{
 		printf("\tEnter element %d : ", i+1);
 		scanf("%d", &arr[i]);
	}
	
    // print the original array
    printf("\nOriginal Array - ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    printf("Enter the element to be inserted in array - ");
    scanf("%d", &x);
 
	printf("To be inserted at position - ");
    scanf("%d", &pos);
 
    n++;
 
    // shift elements forward
    for (i = n-1; i >= pos; i--)
        arr[i] = arr[i - 1];
 
    // insert x at pos
    arr[pos - 1] = x;
 
    printf("\nThe updated array is - \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

void insert_beginning()
{
	int n;
	printf("Enter size of array - ");
	scanf("%d", &n);
	int *arr = 0;
	arr = (int*) malloc ((n+1) * sizeof(int));
    int i, x, pos;
 
	printf("\nEnter %d elements: \n", n);
 	for (i = 0; i < n; i++)
 	{
 		printf("\tEnter element %d : ", i+1);
 		scanf("%d", &arr[i]);
	}

    // print the original array
    printf("\nOriginal Array - ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    printf("Enter the element to be inserted at the beginning of array - ");
    scanf("%d", &x);
 	
 	// for insertion at beginning, pos = arr[0];
	pos = 1;
 
    n++;
 
    // shift elements forward
    for (i = n-1; i >= pos; i--)
        arr[i] = arr[i - 1];
 
    // insert x at pos
    arr[pos - 1] = x;
 
    printf("\nThe updated array is - \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}


void insert_end()
{
	int n;
	printf("Enter size of array - ");
	scanf("%d", &n);
	int *arr = 0;
	arr = (int*) malloc ((n+2) * sizeof(int));
    int i, x, pos;
 	
 	printf("\nEnter %d elements: \n", n);
 	
 	for (i = 0; i < n; i++)
 	{
 		printf("\tEnter element %d : ", i+1);
 		scanf("%d", &arr[i]);
	}
 
    // print the original array
    printf("\nOriginal Array - ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    printf("Enter the element to be inserted at the end of array - ");
    scanf("%d", &x);
 	
 	// for insertion at beginning, pos = arr[n-1];
	pos = n+1;
 
    n++;
 
    // shift elements forward
    for (i = n-1; i >= pos; i--)
        arr[i] = arr[i - 1];
 
    // insert x at pos
    arr[pos - 1] = x;
 
    printf("\nThe updated array is - \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}


void delpos_array()
{	
	int n;
	printf("Enter size of array - ");
	scanf("%d", &n);
	int *array = 0;
	array = (int*) malloc (n * sizeof(int));
	int position, c;

	printf("\nEnter %d elements: \n", n);
   
	for (c = 0; c < n; c++)
	{
		printf("\tEnter element %d : ", c+1);
		scanf("%d", &array[c]);
	}
	printf("\nEnter the position of element you want to delete: ");
	scanf("%d", &position);

	if (position >= n+1)
		printf("\nDeletion not possible.\n");
	else
	{
		printf("\nOriginal array: \n");
		for (c = 0; c < n; c++)
			printf("%d ", array[c]);
		
		for (c = position - 1; c < n - 1; c++)
		array[c] = array[c+1];

		printf("\nResultant array: \n");
		for (c = 0; c < n - 1; c++)
			printf("%d ", array[c]);
   }
   free(array);
}

void del_first()
{
	int n;
	printf("Enter size of array - ");
	scanf("%d", &n);
	int *array = 0;
	int *res = 0;
	array = (int*) malloc (n * sizeof(int));
	res = (int*) malloc (n * sizeof(int));
	int c;

	printf("\nEnter %d elements: \n", n);
   
	for (c = 0; c < n; c++)
	{
		printf("\tEnter element %d : ", c+1);
		scanf("%d", &array[c]);
	}
	
	int x;
	printf("\n Delete which number? - ");
	scanf("%d", &x);
	int i;
	
	int result = 0;
    for (i = 0; i < n; i++)
    {
        if (array[i] == x)    
    	{
    		result = 1;
    		break;
		}
		else
			result = 0;
	}
	
	if(result == 0)
	{
	
		printf("%d element is not present in the array, hence cannot be deleted.\n", x);
		for (c = 0; c < n+1; c++)
		{
			res[c] = array[c];
			return;
		}
	}
	else
	{
		res = (int *) realloc( res, (n-1)*sizeof(int) );
		if(i == 0)
			for(c = 0; c < n; c++)
			{
				res[c] = array[c+1];
			}
		else if (i == (n-1))
			for(c = 0; c < n-1; c++)
			{
				res[c] = array[c];
			}
		else
			for(c = 0; c <= (i-1); c++)
			{
				res[c] = array[c];
			}
			for(c = i+1; c < n; c++)
			{
				res[c-1] = array[c];
			}
	}
	
	printf("\nOriginal Array: \n");
		for (c = 0; c < n; c++)
			printf("%d ", array[c]);
	printf("\nResultant Array: \n");
	for (c = 0; c < n-1; c++)
	{
		printf("%d ", res[c]);
	}
	free(array);
	free(res);
}

void search_element()
{
	int n;
	printf("Enter size of array - ");
	scanf("%d", &n);
	int *array = 0;
	array = (int*) malloc (n * sizeof(int));
	int i;
	
	printf("\nEnter %d elements: \n", n);
	for (i = 0; i < n; i++)
 	{
 		printf("\tEnter element %d - ", i+1);
 		scanf("%d", &array[i]);
	}
	
	int x;
	printf("\n Enter element to search - ");
	scanf("%d", &x);
	
	int result = 0;
    for (i = 0; i < n; i++)
    {
        if (array[i] == x)
    	{
    		result = 1;
    		break;
		}
		else
			result = 0;
	}
	
	if(result == 1)
		printf("The number %d is present in the array at index number %d.", x, i);
	else if(result == 0)
		printf("The number %d is not present in the array.", x);
	
	free(array);
}

void search_pos()
{
	int n;
	printf("Enter size of array - ");
	scanf("%d", &n);
	int *array = 0;
	array = (int*) malloc ((n+2) * sizeof(int));
	int i;
	printf("\nEnter %d elements: \n", n);
	for (i = 0; i < n; i++)
 	{
 		printf("\tEnter element %d - ", i);
 		scanf("%d", &array[i]);
	}
	
	int pos;
	printf("Enter position to search element in - ");
	scanf("%d", &pos);
	
	if(pos < n)
		printf("Element in position %d is %d", pos, array[pos]);
	else
		printf("Element is out of array's scope.");
	free(array);
}

void reverse_array()
{
    int *ptr, n, i;
    printf("Number of elements: ");
    scanf("%d", &n);
    ptr = (int*) malloc (n * sizeof(int));
    printf("\nEnter %d Numbers:\n", n);
	for (i = 0; i < n; i++)
 	{
 		printf("\tEnter element %d : ", i+1);
 		scanf("%d", (ptr+i));
	}
    
    printf("\nOriginal Array: \n");
    for (i = 0; i < n; i++)
 	{
 		printf("%d ", ptr[i]);
	}
	
    printf("\nArray in Reverse Order: \n");
    for(i = n-1 ; i >= 0; i--)
    {
        printf("%d ",*(ptr + i));
    }
    free(ptr);
}

