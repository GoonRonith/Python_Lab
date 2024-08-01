#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *next;
};
struct node *head=NULL;

void insertAtEnd(int val){
    struct node *ptr=head;
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node)) ;
    newNode->data=val;
    if(head==NULL){
        head=newNode;
    }
    else{
    while (ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    
    }
    newNode->next=head;
}


struct node* insertAtHead(int val){
    struct node *newNode,*lastNode;
    lastNode=head;
    newNode=(struct node *)malloc(sizeof(struct node)) ;
    newNode->data=val;
    if(head==NULL){
        head=newNode;
        head->next=head;
    }
    else{
        while(lastNode->next!=head){
            lastNode=lastNode->next;
        }
        newNode->next=head;
        head=newNode;
        lastNode->next=newNode;

    }

    
}



void deleteAthead(){
    struct node *lastNode;
    lastNode=head;
    while(lastNode->next!=head){
        lastNode=lastNode->next;
    }
    head=head->next;
    lastNode->next=head;
}

void deleteLast(){
        struct node *ptr=head;
    while(ptr->next->next!=head){
        ptr=ptr->next;
    }
        ptr->next=head;
              
}

void display(){
    printf("\n");
    struct node *ptr=head;
  while (ptr->next!=head)
  {
    printf("%d->",ptr->data);
    ptr=ptr->next;
  }
  printf("%d->",ptr->data);

}


int main(){
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtHead(10);
    insertAtEnd(50);
    display(); 
    deleteAthead();
    display();
    deleteLast();
    deleteLast();
    display();
    // deleteLast();
    // display();
    // insertAfter(100,20);
    // insertBefore(200,50);
    // display(); 
    // deleteAthead();
    // display();
    return 0;
}

