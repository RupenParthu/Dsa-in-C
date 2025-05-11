#include <stdio.h>
#include <stdlib.h>

#define MAX 100  
#define BASE 10 

void bucketSort(int array[], int n);
void distributeToBuckets(int array[], int n, int position);
void mergeBuckets(int array[], int buckets[BASE][MAX], int bucketCounts[BASE]);

int main() {
    int array[] = {329, 457, 657, 839, 436, 720, 355, 647, 583, 123};
    int n = sizeof(array) / sizeof(array[0]); 

    printf("Original Array: ");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    bucketSort(array, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void bucketSort(int array[], int n) {
    int max = array[0];

    for (int i = 1; i < n; i++) {
        if (array[i] > max) max = array[i];
    }

    for (int position = 1; max / position > 0; position *= 10) {
        distributeToBuckets(array, n, position);
    }
}

void distributeToBuckets(int array[], int n, int position) {
    int buckets[BASE][MAX];  
    int bucketCounts[BASE] = {0};  

    for (int i = 0; i < n; i++) {
        int digit = (array[i] / position) % BASE;
        buckets[digit][bucketCounts[digit]++] = array[i];
    }

    mergeBuckets(array, buckets, bucketCounts);
}

void mergeBuckets(int array[], int buckets[BASE][MAX], int bucketCounts[BASE]) {
    int index = 0;

    for (int i = 0; i < BASE; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }
}
