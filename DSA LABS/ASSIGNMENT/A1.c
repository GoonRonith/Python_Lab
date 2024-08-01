#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
    //clrscr();
    top=-1;
    
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
    	printf("stack is overflow:");
	}
	else
	{
		printf("enter a item:");
		scanf("%d",&x);
	top=top+1;
	stack[top]=x;	
	}
}
	void pop()
	{
	if(top==-1)
	{
		printf("stack is underflow:");
		}
		else
		{
			printf("%d is the deleted item",stack[top]);
			top=top-1;
		}
	}
	void display()
	{
		if(top==-1)
		{
			printf("no items to display:");
		}
		else
		{
			for(i=top;i>=0;i--)
			{
				printf("%5d",stack[i]);
			}
		}
	}
