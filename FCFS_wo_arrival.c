#include <stdio.h>
int main(void)
{
    int AT[5] = {0, 0, 0, 0, 0};
    int BT[5] = {6, 2, 8, 3, 4};
    int WT[5], CT[5], TAT[5];
    int sum = 0;
    int sumTAT = 0, sumWT = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < 5; i++)
    {
        sum += BT[i];
        CT[i] = sum;
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", (i + 1), AT[i], BT[i], CT[i], TAT[i], WT[i]);

        sumTAT += TAT[i];
        sumWT += WT[i];
    }
    printf("\nAverage Turnaround Time: %d\n", (sumTAT / 5));
    printf("Average of Waiting Time: %d\n", (sumWT / 5));
    return 0;
}