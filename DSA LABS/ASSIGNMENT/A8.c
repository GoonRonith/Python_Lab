#include<stdio.h>
int count=1;
void toh(int n,char s,char d,char a){
    if(n>0){
    toh(n-1,s,a,d);
    printf("\n %d no of rings is placed from %c from %c",n,s,d);
    count++;
    toh(n-1,a,d,s);
    }

}

int main(){
    int n=3;
    printf("\n No of rings are->%d",n);
    char s='s';
    char d='d';
    char a='a';
    if(n>0){
        toh(n,s,d,a);
    }
}