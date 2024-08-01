#include <stdio.h>
#include <string.h>
char stack[100];
int top = -1;
void Push(char item)
{
    top += 1;
    stack[top] = item;
}
char Peek()
{
    return stack[top];
}
char Pop()
{
    int item = stack[top];
    top -= 1;
    return item;
}

void display(){
    int temp=top;
    printf("\n stack is->");
    while (temp!= -1)
    {
        printf("\t%d",stack[temp]);
        temp--;
    }
    
}
int calculate(int a,int b,char opretaor){
    if(opretaor=='+'){
        return a+b;
    }
    else if (opretaor=='-')
    {
        return a-b;
    }
        else if (opretaor=='*')
    {
        return a*b;
    }
    else if(opretaor=='^'){
        int pow=1;
        for (int i = 1; i <= b; i++)
        {
            pow=a*pow;
        }
        return pow;
        
    }
    return a/b;
    
}



int main(){
   char prefix[100];



    printf("Enter the prefix expression->");
    gets(prefix);
    
    
    for(int i=strlen(prefix)-1;i>=0;i--){
        
        if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/' || prefix[i]=='^' ){
            int a=Pop();
            int b=Pop();
            int sum=calculate(a,b,prefix[i]);
            Push(sum);
        }
        else{
            int curElm=(int) prefix[i]-48;
            Push(curElm);
        }


    }

    printf("\nEvaluated value of prefix expression is=>%d",Peek());
}