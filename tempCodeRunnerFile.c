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