#include <stdio.h>
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int main(void)
{
    int a[5] = {2, 4, 6, 2, 3};
    swap(a, 1, 2);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}