#include <stdio.h>

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {43, 4, 67, 92, 97, 81, 14, 10, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, size);
    printarray(arr, size);
    return 0;
}