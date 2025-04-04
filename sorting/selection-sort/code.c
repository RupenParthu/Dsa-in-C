#include <stdio.h>

void selectionsort(int arr[], int n)
{
    int min;
    for(int i=0;i<n;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min!=i){
            int temp = arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
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
    selectionsort(arr, size);
    printarray(arr, size);
    return 0;
}