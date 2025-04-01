#include <stdio.h>

void shellsort(int arr[], int n)
{
    // shell's original sequence
    for(int gap = n/2;gap>0;gap/=2){
        for(int i = gap;i<n;i++){
            int key = arr[i];
            int j = i;
            while(j>=gap && arr[j-gap]>key){
                arr[j] = arr[j-gap];
                j-=gap;
            }
            arr[j] = key;
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
    shellsort(arr, size);
    printarray(arr, size);
    return 0;
}