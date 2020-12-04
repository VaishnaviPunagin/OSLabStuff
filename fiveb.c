#include<stdio.h>
int mat[10][6];   //variable which has process id in 0th column, Arrival time in 1st column,
                          //Burst time in 2nd column, Completion time in 3rd column, waiting time in 4th column
                         // turnaround time in 5th column
   //To swap two values
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
       //Sort all the process according to the arrival time
void arrangeArrival(int num, int mat[][6])
{
    int i, j, k;
    for(i=0; i<num; i++)
    {
        for(j=0; j<num-i-1; j++)
        if(mat[j][1] > mat[j+1][1])
        for(k=0; k<5; k++)
                     swap(&mat[j][k], &mat[j+1][k]);
     }
}
   //Calculates the completion time, waiting timeand turnaround time
void completionTime(int num, int mat[][6]) //Completion time, tat
{
    int temp, val, low, i, j, k;
    mat[0][3] = mat[0][1] + mat[0][2];
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];

    for(i=1; i<num; i++)
    {
        temp = mat[i-1][3];
        low = mat[i][2];
        for(j=i; j<num; j++)
        {
            if(temp >= mat[j][1] && low >= mat[j][2])
            {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        for(k=0; k<6; k++)
        {
            swap(&mat[val][k], &mat[i][k]);
        }
    }
}

int main()
{
    int num, temp, i;

    printf("Enter number of Process: ");
    scanf("%d",&num);

    printf("...Enter the process ID...\n");
    for(i=0; i<num; i++)
    {
        printf("...Process  %d\n",i+1);
        printf("Enter Process Id: ");
        scanf("%d",&mat[i][0]);
        printf("Enter Arrival Time: ");
        scanf("%d",&mat[i][1]);
        printf("Enter Burst Time: ");
        scanf("%d",&mat[i][2]);
    }

    printf("Before Arrange...\n");
    printf("Process ID\tArrival Time\tBurst Time\n");
    for(i=0; i<num; i++)
    {
        printf("%d\t\t%d\t\t%d\n",mat[i][0],mat[i][1],mat[i][2]);
    }

    arrangeArrival(num, mat);
    completionTime(num, mat);
    printf("Final Result...\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<num; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",mat[i][0],mat[i][1],mat[i][2],mat[i][4],mat[i][5]);
    }
}
