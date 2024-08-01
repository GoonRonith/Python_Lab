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
        return b+a;
    }
    else if (opretaor=='-')
    {
        return b-a;
    }
        else if (opretaor=='*')
    {
        return b*a;
    }
    else if(opretaor=='^'){
        int pow=1;
        for (int i = 1; i <= a; i++)
        {
            pow=b*pow;
        }
        return pow;
        
    }
    return b/a;
    
}
int main(){
   char postfix[100];

    printf("Enter the postfix expression->");
    gets(postfix);
    
    int i=0;
    while (postfix[i] != '\0'){
        
        if(postfix[i]>='0' && postfix[i]<='9'){
            int curElm=(int) postfix[i]-48;
            Push(curElm);
        }
        else{
            int a=Pop();
            int b=Pop();
            int sum=calculate(a,b,postfix[i]);
            Push(sum);
        }

        i++;
    }

    printf("\nEvaluated value of postfix expression is=>%d",Peek());
}