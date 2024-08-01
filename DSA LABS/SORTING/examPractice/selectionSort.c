#include<stdio.h>
#include<stdbool.h>

void printArray(int a[]){
    printf("\n");
 for (int i = 0; i < 3; i++)
    {
        printf("\t%d",a[i]);
    }
}

void selection_sort(int a[],int n){
    int temp;
 for (int i = 0; i < n; i++)
 {
    int minElm=a[i];
    int minElmPos=i;
    for(int j=i+1;j<n;j++){
        if(minElm > a[j]){
            minElm=a[j];
            minElmPos=j;
        }
    }
    temp=a[i];
    a[i]=minElm;
    a[minElmPos]=temp;
     printf("\niteration->%d",i+1);
        printArray(a);
 }
 
    
 
}


int main(){
    int a[]={5,4,3};
   selection_sort(a,3);
    // printArray(a);
    
    return 0;
}