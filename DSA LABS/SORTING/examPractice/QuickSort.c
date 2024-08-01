#include <stdio.h>
#include <stdbool.h>


int iteration=1;
void printArray(int a[]) {
    printf("\n");
    for (int i = 0; i < 6; i++) {
        printf("\t%d", a[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int s, int e) {
    int pivot=a[s];
    int count=0;
    for (int i = s+1; i < e; i++)
    {
        if(pivot > a[i]){
            count++;
        }
    }
    int pivotIndex=s+count;
    swap(&a[s],&a[pivotIndex]);
    int x=s,y=e-1;
    while (x < pivotIndex && pivotIndex < y){
        while (a[x]< pivot)
        {
            x++;
        }
          while (a[y] > pivot)
        {
            y--;
        }
        if(x < pivotIndex && pivotIndex < y){
            swap(&a[x],&a[y]);
        }
        
    }
    
    return pivotIndex;
    
}

void quick_sort(int a[], int s, int e) {
    if(s>=e) return;
    int p=partition(a,s,e);
    quick_sort(a,s,p);
    quick_sort(a,p+1,e);
   
}

int main() {
    int a[] = {27, 15, 39, 21, 28, 70};
    // int a[] = {6,5,4,3,2,1};
    quick_sort(a, 0, 6);
   printArray(a);
return 0;
}
