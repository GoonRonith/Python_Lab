#include<stdio.h>
#include<stdbool.h>

void printArray(int a[]){
    printf("\n");
 for (int i = 0; i < 3; i++)
    {
        printf("\t%d",a[i]);
    }
}

void insertion_sort(int a[],int n){
    int temp,j,iteration=1;
  for (int i = 1; i < n; i++)
  {
    temp=a[i];
    for (j = i-1; j>=0; j--)
    {
      if(a[j]> temp){
        a[j+1]=a[j];
      }  
      else{
        break;
      }
    }
    a[j+1]=temp;
    printf("\niteration->%d",iteration++);
    printArray(a);
  }
   
}


int main(){
    int a[]={5,4,3};
    insertion_sort(a,3);
//   printArray(n);
    
    return 0;
}