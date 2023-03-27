#include <stdio.h>
int main(void)
{
    int AT[5] = {2, 5, 1, 0, 4};
    int BT[5] = {6, 2, 8, 3, 4};
    int WT[5], CT[5], TAT[5];
    int sum = 0;
    int sumTAT = 0, sumWT = 0;
    int min;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    //finding minimum arrival time
    for (int i = 0; i < 5; i++)
    {
        min = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (AT[min] > AT[j])
            {
                min = j;
            }
        }
        //calculating
        sum += BT[min];
        CT[i] = sum;
        TAT[i] = CT[i] - AT[min];
        WT[i] = TAT[i] - BT[min];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", (i + 1), AT[min], BT[min], CT[i], TAT[i], WT[i]);

        sumTAT += TAT[i];
        sumWT += WT[i];
        //pushing the mimimum arrival time behind 'i' so it wont interfere
        int temp = AT[min];
        AT[min] = AT[i];
        AT[i] = temp;
        //doing the same for burst time
        temp = BT[min];
        BT[min] = BT[i];
        BT[i] = temp;

    }
    printf("\nAverage Turnaround Time: %d\n", (sumTAT/5));
    printf("Average Waiting Time: %d\n", (sumWT/5));
    return 0;
}