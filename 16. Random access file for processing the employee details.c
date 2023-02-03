#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	char name[30];
	int id;
	double salary;
}
Employee;
int main()
{
	int n,i;
	printf("Enter the number of employees:\n ");
	scanf("%d",&n);
	Employee employees[n];
	printf("Enter %d Employee Details \n ",n);
	for (i=0;i<n;i++)
	{
		printf("Employee %d :- \n",i+1);
		printf("Name:");
		scanf("%s",&employees[i].name);
		
		printf("Id:");
		scanf("%d",&employees[i].id);
		
		printf("Salary:");
		scanf("%lf",&employees[i].salary);
		
		char ch = getchar();
		printf("\n");
	}
	printf("------------ All Employees Details ------------\n");
	for(i=0;i<n;i++)
	{
		printf("Name \t");
		printf("%s\n",employees[i].name);
		
		printf("Id \t");
		printf("%d\n",employees[i].id);
		
		printf("Salary \t");
		printf("%2lf\n",employees[i].salary);
		
		printf("\n");
	}
	return 0;
}


/* OUTPUT 

Enter the number of employees:
 2
Enter 2 Employee Details
 Employee 1 :-
Name:balaji
Id:192111666
Salary:150000

Employee 2 :-
Name:murali
Id:192111072
Salary:175000

------------ All Employees Details ------------
Name    balaji
Id      192111666
Salary  150000.000000

Name    murali
Id      192111072
Salary  175000.000000


--------------------------------
