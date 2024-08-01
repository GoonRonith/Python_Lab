#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void swap(int* a, int* b);
int partition(int a[], int s, int e);
void quick_sort(int a[], int s, int e);
void bubbleSort(int arr[], int n);
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    const int size = 1000; 

    int arr1[size], arr2[size];
    clock_t start, end;
    double cpu_time_used;

    
    generateRandomArray(arr1, size);
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
// int arr1[] = {27, 15, 39, 21, 28, 70};
// int arr2[] = {27, 15, 39, 21, 28, 70};
   
    start = clock();
    quick_sort(arr1, 0, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f seconds\n", cpu_time_used);
    // printArray(arr1,6);
    
    start = clock();
    bubbleSort(arr2, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f seconds\n", cpu_time_used);

    return 0;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int s, int e) {
    int count = 0;
    int pivot = a[s];
    for (int i = s + 1; i < e; i++) {
        if (pivot > a[i]) {
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(&a[s], &a[pivotIndex]);
    int x = s, y = e - 1;  
    while (x < pivotIndex && y > pivotIndex) {
        while (a[x] < pivot) {
            x++;
        }
        while (a[y] > pivot) {
            y--;
        }
        if (x < pivotIndex && y > pivotIndex) {
            swap(&a[x++], &a[y--]);  
        }
    }
    return pivotIndex;
}


void quick_sort(int a[], int s, int e) {

    if (s >= e) return;
    int pivotIndex = partition(a, s, e);
    quick_sort(a, s, pivotIndex);
    quick_sort(a, pivotIndex + 1, e);


}


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Adjust the range as needed
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
