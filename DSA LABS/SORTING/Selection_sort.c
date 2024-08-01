#include<stdio.h>
int main(){
    int a[100]={5,4,1,2,3};
    int n=5;

   for (int i = 0; i < n; i++)
   {
        int j;
        int smallElmPos=i;
        int temp;
        int min=a[i];
        for (j = i+1; j < n; j++)
        {
            if(min > a[j]){
                min=a[j];
                smallElmPos=j;
                
            }
        }

        temp=a[i];
        a[i]=min;
        a[smallElmPos]=temp;  
    
   }
   
    for (int i = 0; i < n; i++)
    {
        printf("\n%d",a[i]);
    }
    
    return 0;
}