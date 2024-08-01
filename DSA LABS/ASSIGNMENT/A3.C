//Infix to Postfix
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
    char item = stack[top];
    top -= 1;
    return item;
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter the infix expression->");
    gets(infix);

    int i = 0, idx = 0;

    // TRAVERSE UNTIL THE INFIX EXPRESSION IS END
    while (infix[i] != '\0')
    {
        // WHEN TRAVERSING CHECK IF IT IS A CHARACTER THEN ADD INTO POSTFIX OTHERWISE PUSH INTO STACK
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            postfix[idx] = infix[i];
            idx++;
            // printf("%c----\n",infix[i]);
        }
        else if(infix[i]>='0' && infix[i]<='9'){
            postfix[idx] = infix[i];
            idx++;  
        }
        //
        else
        {
            // CHCEK IF STACK IS EMPTY THEN SIMPLY PUSH IT INTO STACK
            if (top == -1)
            {
                Push(infix[i]);
            }
            // OTHERWISE CHECK WITH  TOP OF THE STACK
            else
            {
                // char topElm=Peek();
                if ((infix[i] == '*' || infix[i] == '/' || infix[i] == '^') && (stack[top] == '+' || stack[top] == '-'))
                {
                    Push(infix[i]);
                }

                else if ((infix[i] == '^') && (stack[top] == '/' || stack[top] == '*'))
                {
                    Push(infix[i]);
                }

                else if ((infix[i] == '/' || infix[i] == '*') && (stack[top] == '*' || stack[top] == '/'))
                {
                    postfix[idx] = Pop();

                    idx++;
                    Push(infix[i]);
                }

                else if ((infix[i] == '+' || infix[i] == '-') && (stack[top] == '+' || stack[top] == '-'))
                {
                    postfix[idx] = Pop();
                    idx++;
                    Push(infix[i]);
                }
                else if((infix[i] == '*' || infix[i] == '/') && ( stack[top] == '^')){
                    while (stack[top] != '+' && stack[top] != '-' && top != -1)
                    {
                        postfix[idx] = Pop();
                        idx++;
                    }
                    if (stack[top] == '+' || stack[top] == '-')
                    {

                        postfix[idx] = Pop();
                        idx++;
                        Push(infix[i]);
                    }
                    else
                    {

                        Push(infix[i]);
                    }
                }
                else if ((infix[i] == '+' || infix[i] == '-') && (stack[top] == '/' || stack[top] == '*' || stack[top] == '^'))
                {

                    while (stack[top] != '+' && stack[top] != '-' && top != -1)
                    {
                        postfix[idx] = Pop();
                        idx++;
                    }
                    if (stack[top] == '+' || stack[top] == '-')
                    {

                        postfix[idx] = Pop();
                        idx++;
                        Push(infix[i]);
                    }
                    else
                    {

                        Push(infix[i]);
                    }
                }

                else if ((infix[i] == '(') && (stack[top] == '/' || stack[top] == '*' || stack[top] == '^' || stack[top] == '+' || stack[top] == '-' || stack[top]=='('))
                {
                    Push(infix[i]);
                }

                else if ((infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*' || infix[i] == '^') && (stack[top] == '('))
                {
                    Push(infix[i]);
                }

                else if ((infix[i] == ')') && (stack[top] == '/' || stack[top] == '*' || stack[top] == '^' || stack[top] == '+' || stack[top] == '-'))
                {
                    while (stack[top] != '(')
                    {
                        postfix[idx] = Pop();
                        idx++;
                    }
                    Pop();
                }
            }
        }

        i++;
    }
    while (top != -1)
    {
        postfix[idx] = Pop();
        idx++;
    }

    printf("Postfix expression is->\n");
    int j = 0;

    while (idx != j)
    {
        printf("%c", postfix[j]);
        j++;
    }
}