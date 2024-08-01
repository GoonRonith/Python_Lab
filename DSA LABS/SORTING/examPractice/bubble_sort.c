#include<stdio.h>
#include<stdbool.h>

void printArray(int *a,int n){
    printf("\n");
 for (int i = 0; i < n; i++)
    {
        printf("\t%d",a[i]);
    }
}
int * bubbleSort(int a[],int n){
    bool flag;
    int temp;
   for (int i = 0; i < n; i++)
   {
    flag=false;
    for (int j = 0; j < n-(i+1); j++)
    {
        if(a[j] > a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            flag=true;
        }
    }
    if(!flag) break;
   }
   
   return a;
}



int main(){
    int a[]={1,2,3};
    int *b=bubbleSort(a,3);
    printArray(b,3);
    return 0;
}