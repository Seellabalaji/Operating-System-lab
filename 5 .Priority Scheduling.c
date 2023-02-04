#include<stdio.h>
#include<conio.h>
int main()
 {
   int x,n,p[10],pp[10],pt[10],w[10],t[10],awt,atat,i;
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("\n Enter process : time priorities \n");
   for(i=0;i<n;i++)
    {
      printf("\nProcess no %d : ",i+1);
      scanf("%d  %d",&pt[i],&pp[i]);
      p[i]=i+1;
    }
  for(i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
         x=pp[i];
         pp[i]=pp[j];
         pp[j]=x;
         x=pt[i];
         pt[i]=pt[j];
         pt[j]=x;
         x=p[i];
         p[i]=p[j];
         p[j]=x;
      }
   }
}
w[i]=0;
awt=0;
t[0]=pt[0];
atat=t[0];
for(i=1;i<n;i++)
 {
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+pt[i];
   atat+=t[i];
 }
printf("\n\n Job \t Burst Time \t Wait Time \t Turn Around Time   Priority \n");
for(i=0;i<n;i++)
  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",p[i],pt[i],w[i],t[i],pp[i]);
awt/=n;
atat/=n;
printf("\n Average Wait Time : %d \n",awt);
printf("\n Average Turn Around Time : %d \n",atat);
getch();
}


/*OUTPUT

Enter the total number of Processes: 4

Please Enter the  Burst Time and Priority of each process:

Enter the details of the process A
Enter the burst time: 6
Enter the priority: 3

Enter the details of the process B
Enter the burst time: 8
Enter the priority: 1

Enter the details of the process C
Enter the burst time: 9
Enter the priority: 4

Enter the details of the process D
Enter the burst time: 3
Enter the priority: 2


Process_name     Burst Time      Waiting Time     Turnaround Time
------------------------------------------------------------
          C               9              0               9
-----------------------------------------------------------
          A               6              9               15
-----------------------------------------------------------
          D               3              15              18
-----------------------------------------------------------
          B               8              18              26
-----------------------------------------------------------


 Average Waiting Time : 10.500000
 Average Turnaround Time: 17.000000

--------------------------------
