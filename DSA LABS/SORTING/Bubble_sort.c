#include<stdio.h>
#include<stdbool.h>

void printArray(int *a){
    printf("\n");
 for (int i = 0; i < 6; i++)
    {
        printf("\t%d",a[i]);
    }
}
int * bubbleSort(int a[],int n){
    int temp;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag=false;
        for(int j = 0; j < n-(i+1); j++)
        {
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=true;
            }
            
        }
   
        if(!flag) break;
        // printf("\niteration->%d",i+1);
        // printArray(a);
        
    }
   return a;
}



int main(){
    int a[]={27,15,39,21,28,70};
    int *b=bubbleSort(a,6);
    printArray(b);
    return 0;
}