#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    float avg_wt, avg_tat;
    int n;
    bool is_completed[10] = {false};
    int current_time = 0, completed = 0;
    printf("Enter number of process:");
    scanf("%d", &n);
    int BT[n], BT_remaining[n], AT[n], P[n], WT[n], TAT[n], CT[n], totalWT = 0, totalTAT = 0;

    printf("\nEnter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
        BT_remaining[i]=BT[i];
        P[i] = i + 1;
    }
    printf("\nEnter Arrival Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &AT[i]);
    }
    while (completed != n) //! Loop till all processes are completed
    {
        int min_index = -1;
        int minimum = __INT_MAX__;
        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= current_time && is_completed[i] == 0)

            {
                if (BT_remaining[i] < minimum)
                {
                    minimum = BT_remaining[i];
                    min_index = i;
                }
                if (BT_remaining[i] == minimum)
                {
                    if (AT[i] < AT[min_index])
                    {
                        minimum = BT_remaining[i];
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)
        {
            current_time++;
        }
        else
        {
            BT_remaining[min_index]--;
            current_time++;
            if (BT_remaining[min_index] == 0)
            {

                CT[min_index] = current_time;
                TAT[min_index] = CT[min_index] - AT[min_index];
                WT[min_index] = TAT[min_index] - BT[min_index];

                totalTAT += TAT[min_index];
                totalWT += WT[min_index];

                completed++;
                is_completed[min_index] = true;
                current_time = CT[min_index];
            }
        }
    }
    avg_tat = (float)totalTAT / n;
    avg_wt = (float)totalWT / n;

    printf("\nProcess\tArival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++)
    {
        printf("\np%d\t\t %d\t%d\t\t %d\t\t\t%d", P[i], AT[i], BT[i], WT[i], TAT[i]);
    }

    printf("\n\nAverage Waiting Time=%.2f", avg_wt);
    printf("\nAverage Turnaround Time=%.2f", avg_tat);

    return 0;
}