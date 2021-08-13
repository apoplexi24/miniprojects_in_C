#include<stdio.h>

int main()
{
	int choice;

	printf("Matrix Operations \n1. Addition\n2. Subtraction\n3. Transpose\n4. Multiplication \n \n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			mat_add();
			break;
		case 2:
			mat_sub();
			break;
		case 3:
			mat_trans();
			break;
		case 4: 
			mat_mul();
		default:
			printf("Invalid Selection");
	}
	
	return 0;
}


int mat_add()
{
	printf("\n Addition of Matrix \n \n");
	int i,j;
	int m,n;
	int mat1[10][10],mat2[10][10],result[10][10];
	printf("Enter order of the matrices:\n ");
	scanf("%d %d", &m, &n);
	
	printf("\n Matrix 1 - Enter values of %d * %d matrix: \n", m, n);
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d",&mat1[i][j]);
		}	
	}
	printf("\n Matrix 2- Enter values of %d * %d matrix: \n", m, n);
	for(i = 0; i < m; i++)
	{
		for(j = 0 ; j < n; j++)
		{
			scanf("%d", &mat2[i][j]);
		}	
	}
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				result[i][j]=mat1[i][j]+mat2[i][j];
			}	
		}	
		
		printf("Addition of Matrix is:\n");
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				printf("%d\t",result[i][j]);
			}	
			printf("\n");
		}
		return 0;
	}

int mat_sub()
{
	printf("\n Subtraction of Matrix \n \n");
	int i,j;
	int m,n;
	int mat1[10][10],mat2[10][10],result[10][10];
	printf("Enter order of the matrices: \n");
	scanf("%d %d", &m, &n);
	printf("\n Matrix 1 - Enter values of %d * %d matrix: \n", m, n);
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d",&mat1[i][j]);
		}	
	}
	printf("Matrix 2- Enter values of %d * %d matrix: \n", m, n);
	for(i = 0; i < m; i++)
	{
		for(j = 0 ; j < n; j++)
		{
			scanf("%d", &mat2[i][j]);
		}	
	}
		
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			result[i][j]=mat1[i][j]-mat2[i][j];
		}	
	}
	printf("Subtraction of Matrix is:\n");
	for(i = 0 ; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t",result[i][j]);
		}	
		printf("\n");
	}	
	return 0;
}

int mat_trans()
{
	printf("\n Transpose of Matrix \n \n");
	int i,j;
	int m,n;
	int mat[10][10],result[10][10];
	printf("Enter order of the matrices: \n");
	scanf("%d %d", &m, &n);
	
	printf("\n Enter values of %d * %d matrix: \n", m, n);
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d",&mat[i][j]);
		}	
	}

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			result[i][j] = mat[j][i];
		}	
	}
	printf("Transpose of Matrix is:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t",result[i][j]);
		}	
		printf("\n");
	}
	
}

int mat_mul()
{
	printf("\n Multiplication of Matrix \n \n");
	int m, n, p, q, i, j, k, sum = 0;
	int mat1[10][10], mat2[10][10], mat3[10][10];

	printf("Enter number of rows and columns of Matrix 1 - \n");
	scanf("%d %d", &m, &n);
	printf("Enter elements of matrix 1: \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &mat1[i][j]);
	}
	printf("\nEnter number of rows and columns of Matrix 2 - \n");
	scanf("%d %d", &p, &q);

	if (n != p)
	printf("\nThe matrices can’t be multiplied with each other.\n");
	else
	{
		printf("\nEnter elements of Matrix 2: \n");

		for (i = 0; i < p; i++)
		{
			for (j = 0; j < q; j++)
				scanf("%d", &mat2[i][j]);
		}
		for (i = 0; i < m; i++) 
		{
			for (j = 0; j < q; j++) 
			{
				for (k = 0; k < p; k++) 
				{
					sum = sum + mat1[i][k]*mat2[k][j];
				}
			mat3[i][j] = sum;
			sum = 0;
			}
		}

		printf("\nProduct of the matrices:\n");

		for (i = 0; i < m; i++) 
		{
			for (j = 0; j < q; j++)
			{
				printf("%d\t", mat3[i][j]);
				
			}
		printf("\n");
		}
	}
}
