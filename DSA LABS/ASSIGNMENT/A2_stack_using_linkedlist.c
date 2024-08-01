#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
int choice,n,val;
void push(){
    printf("enter a item:");
	scanf("%d",&val);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;

    if(top==NULL){
        top=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

void peek(){
    printf("\n%d is current top element",top->data);
}

void pop(){
    if(top==NULL){
        printf("\nstack is empty...");
    }
    else{
        printf("\npopped item is->%d",top->data);
        top=top->next;
    }
}


void display(){
    struct node *temp=top;
       if(top==NULL){
        printf("\nstack is empty...");
    }
    else{
        printf("\n List is->");
 while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }
    }
}


int main(){
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

   
}