#include <stdio.h>
int main(void)
{
    int AT[6] = {10, 13, 18, 20, 27, 29};
    int BT[6] = {2, 3, 2, 5, 1, 2};
    int WT[6], CT[6], TAT[6], DT[6], IT[6];
    int sum = 0;
    int sumTAT = 0, sumWT = 0, sumIT = 0, sumBT = 0;
    int min;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tIT\n");
    // finding minimum arrival time
    DT[0] = 0;
    for (int i = 0; i < 6; i++)
    {
        min = i;
        for (int j = i + 1; j < 6; j++)
        {
            if (AT[min] > AT[j])
            {
                min = j;
            }
        }
        // calculating
        IT[i] = AT[i] - DT[i];
        sum += BT[min] + IT[i];
        CT[i] = sum;
        TAT[i] = CT[i] - AT[min];
        WT[i] = TAT[i] - BT[min];

        DT[i + 1] = BT[i] + AT[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", (i + 1), AT[min], BT[min], CT[i], TAT[i], WT[i], IT[i]);

        sumTAT += TAT[i];
        sumWT += WT[i];
        sumIT += IT[i];
        sumBT += BT[i];
        // pushing the mimimum arrival time behind 'i' so it wont interfere
        int temp = AT[min];
        AT[min] = AT[i];
        AT[i] = temp;
        // doing the same for burst time
        temp = BT[min];
        BT[min] = BT[i];
        BT[i] = temp;
    }
    int context_switch = sumBT * 5;
    float utilize = (float)sumBT / context_switch;
    printf("\nAverage Turnaround Time: %d\n", (sumTAT / 6));
    printf("Average Waiting Time: %d\n", (sumWT / 6));
    printf("Average Ideal Time: %d\n", (sumIT / 6));
    printf("CPU Utilization: %.1f", (utilize * 100));

    return 0;
}