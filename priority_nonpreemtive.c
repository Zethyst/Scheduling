#include <stdio.h>
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    int n, totalWT = 0, totalTAT = 0, temp, min, priority;
    float avg_wt, avg_tat;
    printf("Enter number of process:");
    scanf("%d", &n);
    int BT[n], P[n], AT[n], WT[n], TAT[n], CT[n], Pr[n];
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
    printf("\nEnter Priority: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &Pr[i]);
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
                    swap(Pr, i, j);
                }
            }
            else if (AT[i] > AT[j])
            {
                swap(AT, i, j);
                swap(BT, i, j);
                swap(P, i, j);
                swap(Pr, i, j);
            }
        }
    }
    int run = 0, sum = AT[0];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            min = i;
        }
        else
        {
            // designing a code which gives the process to execute
            for (int j = i; j < run - 1; j++) // run - 1 becoz k=j+1 might give out of range arrival process
            {
                min = j;
                for (int k = j + 1; k < run; k++)
                {
                    if (k >= n) // ensuring k never goes out of size n and gives garbage
                    {
                        goto label;
                    }
                    if (Pr[min] < Pr[k])
                    {
                        min = k;
                    }
                }
            }
        }
    label:
        sum += BT[min];
        CT[i] = sum;
        TAT[i] = CT[i] - AT[min];
        WT[i] = TAT[i] - BT[min];
        totalWT += WT[i];
        totalTAT += TAT[i];
        run += BT[min];
        // pushing the just executed process up so it doesn't not get repeated
        swap(AT, i, min);
        swap(BT, i, min);
        swap(P, i, min);
        swap(Pr, i, min);
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