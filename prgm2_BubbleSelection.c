#include <stdio.h> 
// Function to perform bubble sort 
void bubbleSort(int arr[], int n) { 
    int i, j; 
    for (i = 0; i < n - 1; ++i) { 
        for (j = 0; j < n - i - 1; ++j) { 
            if (arr[j] > arr[j + 1]) { 
                // Swap arr[j] and arr[j+1] 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
// Function to perform selection sort 
void selectionSort(int arr[], int n) { 
    int i, j, minIndex; 
    for (i = 0; i < n - 1; ++i) { 
        minIndex = i; 
        for (j = i + 1; j < n; ++j) { 
            if (arr[j] < arr[minIndex]) { 
                minIndex = j; 
            } 
        } 
        // Swap arr[i] and arr[minIndex] 
        int temp = arr[i]; 
        arr[i] = arr[minIndex]; 
        arr[minIndex] = temp; 
    } 
 
 
} 
 
int main() { 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
     
    printf("Array before sorting:\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d ", arr[i]); 
    printf("\n"); 
 
    // Bubble Sort 
    bubbleSort(arr, n); 
    printf("Array after bubble sort (ascending order):\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d ", arr[i]); 
    printf("\n"); 
 
    // Selection Sort 
    selectionSort(arr, n); 
    printf("Array after selection sort (descending order):\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d ", arr[i]); 
    printf("\n"); 
 
    return 0; 
}