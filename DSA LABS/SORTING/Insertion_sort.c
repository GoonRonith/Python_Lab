#include<stdio.h>
int main(){
    int a[100]={10,5,6,20,9};
    int n=5;

    for (int i = 1; i < n; i++)
    {   
        int j;
        int temp=a[i];
        for (j= i-1; j >= 0; j--)
        {
            if(a[j] > temp){
                a[j+1]=a[j];
            }
            else{
                break;
            }
        }
        a[j+1]=temp;
        
        
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n%d",a[i]);
    }
    

    return 0;
}