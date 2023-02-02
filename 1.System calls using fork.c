#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("Process ID : %d\n",getpid());
	printf("Parent process ID : %d\n",getpid());
	return 0;
}


//OUTPUT//
//Process ID : 34732
//Parent process ID : 34725
