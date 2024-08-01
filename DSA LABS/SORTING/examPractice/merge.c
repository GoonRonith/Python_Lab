#include<stdio.h>
#include<stdbool.h>
int iteration=1;
void printArray(int a[]){
    printf("\n");
 for (int i = 0; i < 6; i++)
    {
        printf("\t%d",a[i]);
    }
}

void merge(int a[],int s,int e){
  int mid=(s+e)/2;
  int l1=mid-s+1;
  int l2=e-mid;
  int first[l1],seccod[l2];
  int k=s;
  for (int i = 0; i < l1 ; i++)
  {
    first[i]=a[k++];
  }
   for (int i = 0; i < l2 ; i++)
  {
    seccod[i]=a[k++];
  }

  int index1=0,index2=0;
  k=s;
  while (index1<l1 && index2<l2)
  {
   if(first[index1] < seccod[index2]){
    a[k++]=first[index1++];
   }
   else{
    a[k++]=seccod[index2++];
   }
    
  }
   while (index1<l1)
  {
    a[k++]=first[index1++];
  }
     while (index2<l2)
  {
    a[k++]=seccod[index2++];
  }
}


void mergesort(int a[],int s,int e){
   if(s>=e) return;
   int mid=(s+e)/2;
   mergesort(a,s,mid);
   mergesort(a,mid+1,e);
   merge(a,s,e);
     printf("\niteration->%d",iteration++);
    printArray(a);
}


int main(){
    int a[]={27,15,39,21,28,70};
    mergesort(a,0,5);
    // printArray(a);
    return 0;
}