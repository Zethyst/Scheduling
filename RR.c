#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, i,QT, count = 0, current_time = 0, completed = 0, visited[100] = {false};
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
    while (count != n)
    {
        for (int i = 0; i < n; i++)
        {
            if (BT_remaining[i] > QT)
            {
                BT_remaining[i] -= QT;
            }
        }
    }

    return 0;
}
