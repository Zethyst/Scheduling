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
    int BT[n], AT[n], P[n], WT[n], TAT[n], CT[n], totalWT = 0, totalTAT = 0;

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
    while (completed != n)  //!Loop till all processes are completed
    {
        int min_index = -1;  //set a invalid value incase no process executes and the cpu is ideal
        int minimum = __INT_MAX__;  //a way to make sure comparing condition gets executed
        for (int i = 0; i < n; i++)  //each time loop runs till the 5 processes
        {
            if (AT[i] <= current_time && is_completed[i] == 0)  //making sure only those processes are checked which have arrived in the ready queue and also not completed, this completed tag makes sure only those processes are selected which are not completed, eliminates the need to swap processes to the top
            // This condition gets you this process with arrival time (0)
            {
                if (BT[i] < minimum)  //This condition gets you the minimum BT process among a bunch of processes which have arrived, also selects the first process BT when the iteration starts
                {
                    minimum = BT[i];
                    min_index = i;
                }
                if (BT[i] == minimum)  //Although this condition runs every time, but its main purpose starts only when the above condition fails and the two BTs are equal in that case, the previous BT whose value is same is compared with this current BT whose value is same. The one who arrived first is selected.
                {
                    if (AT[i] < AT[min_index]) //comparing current i [same value] with previous min_index [same value]
                    {
                        minimum = BT[i];
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1)  //if at all a process is not found and the cpu is ideal, increase the time by 1
        {
            current_time++;
        }
        else
        {
            CT[min_index] = current_time + BT[min_index];
            TAT[min_index] = CT[min_index] - AT[min_index];
            WT[min_index] = TAT[min_index] - BT[min_index];

            totalTAT += TAT[min_index];
            totalWT += WT[min_index];

            completed++;
            is_completed[min_index] = true;
            current_time = CT[min_index];
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