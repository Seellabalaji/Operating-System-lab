#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;
    printf("Enter the filename to open for reading \n");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    printf("Enter the filename to open for writing \n");
    scanf("%s", filename);
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("\nContents copied to %s", filename);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
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
