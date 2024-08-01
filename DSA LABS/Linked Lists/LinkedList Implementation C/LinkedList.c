#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *next;
};
struct node *head=NULL;
struct node *RevHead=NULL;

void insertAtEnd(int val){
    struct node *ptr=head;
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node)) ;
    newNode->data=val;
    if(head==NULL){
        head=newNode;
    }
    else{
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    
    }
    newNode->next=NULL;
}


struct node* insertAtHead(int val){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node)) ;
    newNode->data=val;
    if(head==NULL){
        head=newNode;
        head->next=NULL;
    }
    else{
        newNode->next=head;
        head=newNode;
    }

    
}

void insertAfter(int val,int nodeVal){
    struct node *ptr=head;
    struct node *newNode=(struct node *)malloc(sizeof(struct node)) ;
    newNode->data=val;
    while (ptr->data!=nodeVal)
    {
        ptr=ptr->next;
    }
       newNode->next=ptr->next;
        ptr->next=newNode;
    
}

void insertBefore(int val,int nodeVal){
    struct node *ptr=head;
    struct node *newNode=(struct node *)malloc(sizeof(struct node)) ;
    newNode->data=val;
    while (ptr->next->data != nodeVal)
    {
        ptr=ptr->next;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
    
}

void deleteAthead(){
    head=head->next;
}

void deleteLast(){
        struct node *ptr=head;
        while (ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=NULL;
        
        
}
void reverseList(){
    struct node *prev=NULL;
    struct node *current=head;
    struct node *nextNode=head;
    while (current!=NULL)
    {
       nextNode=current->next;
       current->next=prev;
       prev=current;
       current=nextNode;
    }
    RevHead=prev;
    
}






void display(){
    printf("\n");
    struct node *ptr=head;
  while (ptr!=NULL)
  {
    printf("%d->",ptr->data);
    ptr=ptr->next;
  }
   

}


int main(){
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtHead(10);
    insertAtEnd(50);
    display(); 
    printf("\n");
    test(head);
    // reverseList();
    // printf("%d",RevHead->next->data);

    // deleteLast();
    // display();
    
    // insertAfter(100,20);
    // insertBefore(200,50);
    // display(); 
    // deleteAthead();
    // display();
    
    // printf("hello") ;
    return 0;
}

