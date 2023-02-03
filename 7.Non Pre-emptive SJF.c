#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\n priority P[%d]",i+1);
        scanf("%d",&pr[i]);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        p[i]=i+1;           
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
    avg_wt=total/n;      
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=total/n;     
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
	return 0;
}



/* OUTPUT

Enter Total Number of Process:3

Enter Burst Time and Priority

 priority P[1]2
Burst Time:7

 priority P[2]1
Burst Time:8

 priority P[3]3
Burst Time:9

Process     Burst Time          Waiting Time    Turnaround Time
P[2]              8                 0                   8
P[1]              7                 8                   15
P[3]              9                 15                  24

Average Waiting Time=7
Average Turnaround Time=15

--------------------------------
