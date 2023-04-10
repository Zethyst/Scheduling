#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5
int Q[SIZE];
int front = -1;
int rear = -1;

int max(int a, int b)
{
    return a > b ? a : b;
}
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
}

int ENQUEUE(int data)
{

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    Q[rear] = data;
    return 0;
}
int DEQUEUE()
{
    int value;
    if (front == rear)
    {
        value = Q[front];
        Q[front] = 0;
        front = rear = -1;
    }
    else
    {
        value = Q[front];
        Q[front] = 0;
        front++;
    }
    // printf("\nThe value deleted: %d", value);
    return 0;
}
int PEEK()
{
    // printf("\nThe Topmost Element is: %d", Q[front]);
    return Q[front];
}
int main()
{
    int n, i, QT, count = 0, current_time = 0, completed = 0, visited[100] = {false};
    int index;
    float avg_wt, avg_tat;
    system("cls");
    printf("Enter number of process:");
    scanf("%d", &n);
    int BT[n], BT_remaining[n], AT[n], P[n], WT[n], TAT[n], CT[n], totalWT = 0, totalTAT = 0;
    printf("\nEnter Burst Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
        BT_remaining[i] = BT[i];
        P[i] = i + 1;
    }
    printf("\nEnter Arrival Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &AT[i]);
    }
    printf("Enter Quantum Time: ");
    scanf("%d", &QT);

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

    // Pushing the first process into the ready queue
    ENQUEUE(0);
    visited[0] = true;
    while (completed != n)
    {
        index = PEEK() - 1;
        DEQUEUE();
        if (BT_remaining[index] == BT[index])
        {
            current_time = max(current_time, AT[index]);
        }
        if (BT_remaining[index] - QT > 0)
        {
            BT_remaining[index] -= QT;
            current_time += QT;
        }
        else
        {
            current_time += BT_remaining[index];
            BT_remaining[index] = 0;
            completed++;

            CT[index] = current_time;
            TAT[index] = CT[index] - AT[index];
            WT[index] = TAT[index] - BT[index];

            totalTAT += TAT[index];
            totalWT += WT[index];
        }
        for (int i = 1; i < n; i++)
        {
            if (BT_remaining[i] > 0 && AT[i] <= current_time && visited[i] == false)
            {
                ENQUEUE(i);
                visited[i] = true;
            }
        }

        if (BT_remaining[index] > 0)
        {
            ENQUEUE(index);
        }
        if (isEmpty())
        {
            for (int i = 1; i < n; i++)
            {
                if (BT_remaining[i] > 0)
                {
                    ENQUEUE(i);
                    visited[i] = true;
                    break;
                }
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
