#include<stdio.h>
#include<string.h>
char stack[100];
int top = -1;
int idx=0;
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
    char item = stack[top];
    top -= 1;
    return item;
}
int main(){
    char infix[100],infix_rev[100],prefix_rev[100],prefix[100];
    printf("Enter infix expression->");
    gets(infix);


    for (int i = 0; i < strlen(infix); i++)
    {
        if(infix[strlen(infix)-(i+1)]!='\0' && infix[strlen(infix)-(i+1)]!='\n' ){
            infix_rev[i]=infix[strlen(infix)-(i+1)];
        }
        
    }

     for (int i = 0; i <= strlen(infix_rev); i++)
    {
       
        if((infix_rev[i]>='A' && infix_rev[i]<='Z') ||  (infix_rev[i]>='a' && infix_rev[i]<='z')){
            prefix_rev[idx]=infix_rev[i];
            idx++;
            
        }
        else{
            if(top==-1){
                Push(infix_rev[i]);
                

            }
            else{
                if((infix_rev[i]=='+' || infix_rev[i]=='-') &&  (stack[top]=='+' || stack[top]=='-')){
                Push(infix_rev[i]);
                
            }
            else if((infix_rev[i]=='*' || infix_rev[i]=='/') &&  (stack[top]=='*' || stack[top]=='/')){
                Push(infix_rev[i]);
              
            }
            else if((infix_rev[i]=='/' || infix_rev[i]=='*') &&  (stack[top]=='+' || stack[top]=='-')){
                Push(infix_rev[i]);
             
            }
            else if ((infix_rev[i] == '+' || infix_rev[i] == '-') && (stack[top] == '/' || stack[top] == '*' || stack[top] == '^'))
                {
                   
                    while (stack[top] != '+' && stack[top] != '-' && top != -1 && stack[top]!=')')
                    {
                        prefix_rev[idx] = Pop();
                        idx++;
                       
                    }
                Push(infix_rev[i]);
                
            }

            else if((infix_rev[i]==')') && (stack[top]=='+' || stack[top]=='-' || stack[top]=='/' || stack[top]=='*' || stack[top]=='^')){
                Push(infix_rev[i]);
              
            }

             else if((stack[top]==')') && (infix_rev[i]=='+' || infix_rev[i]=='-' || infix_rev[i]=='/' || infix_rev[i]=='*' || infix_rev[i]=='^')){
               Push(infix_rev[i]);
  
            }

                else if((infix_rev[i]=='(') && (stack[top]=='+' || stack[top]=='-' || stack[top]=='/' || stack[top]=='*' || stack[top]=='^')){
                    
                    while (stack[top] != ')')
                    {
                    prefix_rev[idx]=Pop();
                    idx++;
                    
                    }
                    Pop();
    
                
            }
            }
            

        }
         
    }


while(top!=-1){
    prefix_rev[idx]=Pop();
    idx++;
}

printf("\nprefix expression is->\n");
 for (int i = idx-1; i >=0 ; i--)
    {
        
        printf("%c",prefix_rev[i]);
    }
}