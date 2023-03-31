#include <stdio.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int main()
{
    float avg_wt, avg_tat;
    int n;
    printf("Enter number of process:");
    scanf("%d", &n);
    int BT[n], AT[n], P[n], WT[n], TAT[n], CT[n], totalWT = 0, totalTAT = 0, min, temp;

    printf("\nEnter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
        P[i] = i + 1;
    }
    printf("\nEnter Arrival Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &AT[i]);
    }

    // sorting according to arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (AT[i] == AT[j])
            {
                if (BT[i] > BT[j])
                {
                    swap(BT, i, j);
                    swap(P, i, j);
                }
            }
            else if (AT[i] > AT[j])
            {
                swap(AT, i, j);
                swap(BT, i, j);
                swap(P, i, j);
            }
        }
    }
    int run = 0,sum=AT[0];
    for (int i = 0; i < n; i++)
    {
        sum += BT[i];
        CT[i] = sum;
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        totalWT += WT[i];
        totalTAT += TAT[i];
    }

    avg_wt = (float)totalWT / n;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t\t %d\t\t %d\t\t\t%d", P[i], BT[i], WT[i], TAT[i]);
    }

    avg_tat = (float)totalTAT / n;
    printf("\n\nAverage Waiting Time=%.2f", avg_wt);
    printf("\nAverage Turnaround Time=%.2f", avg_tat);
}
