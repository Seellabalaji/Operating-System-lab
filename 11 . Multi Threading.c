#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>  
#include<pthread.h>
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
} 
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}

/* Output
Before Thread
Printing GeeksQuiz from Thread
After Thread
--------------------------------
Process exited after 1.027 seconds with return value 0
Press any key to continue . . .
