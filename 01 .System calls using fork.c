#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t fork(void);
pid_t p;
printf("before fork\n");
p=fork();
if(p==0)
{
printf("I am child having id %d\n",getpid());
printf("My parent's id is %d\n",getpid());
}
else{
printf("My child's id is %d\n",p);
printf("I am parent having id %d\n",getpid());
}
printf("Common\n");
return 0;
}

/* OUTPUT 


before fork
My child's id is 88973
I am parent having id 88972
Common
I am child having id 88973
My parent's id is 88973
Common


