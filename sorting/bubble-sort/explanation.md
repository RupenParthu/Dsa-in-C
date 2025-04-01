# Bubble Sort in C

This repository contains an implementation of the **Bubble Sort** algorithm in C.

## 📝 Description

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

## 📜 Algorithm Explanation

1. Iterate through the array multiple times.
2. In each iteration, compare adjacent elements.
3. If the left element is greater than the right element, swap them.
4. The largest element bubbles up to its correct position after each full pass.
5. Repeat until the entire array is sorted.

## 🖥️ Code Implementation

```c
#include <stdio.h>

// Function to perform Bubble Sort
void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {  
                int temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
            }
        }
    }
}

// Function to print the sorted array
void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

// Main function
int main() {
    int arr[] = {43, 4, 67, 92, 97, 81, 14, 10, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    bubblesort(arr, size); // Sorting the array
    
    printf("Sorted array: ");
    printarray(arr, size);
    
    return 0;
}
