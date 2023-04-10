#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
};

void calculation(struct process *ps, int n, int quantum)
{
    int i, j;
    int total_time = 0;
    int totalWT = 0;
    int totalTAT = 0;
    int WT[n], TAT[n], CT[n];

    // Run the simulation
    for (i = 0;; i++)
    {
        int done = 1;
        for (j = 0; j < n; j++)
        {
            if (ps[j].remaining_time > 0)
            {
                done = 0;
                if (ps[j].remaining_time > quantum)
                {
                    total_time += quantum;
                    ps[j].remaining_time -= quantum;
                }
                else
                {
                    total_time += ps[j].remaining_time;
                    ps[j].remaining_time = 0;
                    CT[j] = total_time;
                    TAT[j] = total_time - ps[j].arrival_time;
                    WT[j] = total_time - ps[j].burst_time - ps[j].arrival_time;
                    totalWT += WT[j];
                    totalTAT += TAT[j];
                }
            }
        }
        if (done == 1)
            break;
    }

    // Print the results
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaound Time\tCompletion Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", ps[i].pid, ps[i].burst_time, ps[i].arrival_time, WT[i], TAT[i], CT[i]);
    }
    printf("Average waiting time: %.2f\n", (float)totalWT / n);
    printf("Average turnaround time: %.2f\n", (float)totalTAT / n);
}

int main()
{
    int n, i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *ps = (struct process *)malloc(n * sizeof(struct process));
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time and arrival time for process %d: ", i + 1);
        scanf("%d%d", &ps[i].burst_time, &ps[i].arrival_time);
        // Initialize remaining time for each process
        ps[i].remaining_time = ps[i].burst_time;
        ps[i].pid = i + 1;
    }
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    calculation(ps, n, quantum);
    free(ps);
    return 0;
}