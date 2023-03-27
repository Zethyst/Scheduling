#include <stdio.h>
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    int BT[20], P[20], WT[20], TAT[20], n, totalWT = 0, totalTAT = 0, temp;
    float avg_wt, avg_tat;
    printf("Enter number of process:");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
        P[i] = i + 1;
    }

    // sorting
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (BT[i] > BT[j])
            {
                swap(BT, i, j);
                swap(P, i, j);
            }
        }
    }

    WT[0] = 0;

    // finding the waiting time of all the processes
    for (int i = 1; i < n; i++)
    {
        WT[i] = 0;
        for (int j = 0; j < i; j++)
            // individual WT by adding BT of all previous completed processes
            WT[i] += BT[j];

        totalWT += WT[i];
    }

    avg_wt = (float)totalWT / n;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++)
    {
        // turnaround time of individual processes
        TAT[i] = BT[i] + WT[i];

        totalTAT += TAT[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d", P[i], BT[i], WT[i], TAT[i]);
    }

    avg_tat = (float)totalTAT / n;
    printf("\n\nAverage Waiting Time=%.2f", avg_wt);
    printf("\nAverage Turnaround Time=%.2f", avg_tat);
}