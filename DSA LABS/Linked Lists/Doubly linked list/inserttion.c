#include<stdio.h>
#include<stdlib.h>
struct node *head=NULL;
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void insertAtEnd(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    if(head==NULL){
        newnode->prev=NULL;
        newnode->data=val;
        newnode->next=NULL;
        head=newnode;
    }
    else{
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        newnode->prev=ptr;
        ptr->next=newnode;
        newnode->data=val;
        newnode->next=NULL;
        
    }

}

void insertAthead(int val){
     struct node *newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=val;
     newnode->prev=NULL;
     newnode->next=head;
     head->prev=newnode;
     head=newnode;

}

void deleteHeadNode(){
    head=head->next;
    head->prev=NULL;
}

void deleteLastNode(){
    struct node *ptr=head;
    if(head==NULL){
        printf("Underflow");
    }
    else{
        while (ptr->next!=NULL)
        {
          ptr=ptr->next;
        }
        //   ptr->prev=NULL;
          ptr->prev->next=NULL;
        
    }
}



void display(){
     struct node *ptr=head;
     printf("\n");
     while(ptr != NULL){
        printf("\t%d",ptr->data);
        ptr=ptr->next;
     }
}

int main(){
   
    insertAtEnd(10);
    insertAtEnd(12);
    insertAtEnd(15);
    insertAtEnd(18);
    display();
    insertAthead(30);
    display();

    deleteHeadNode();
    display();
    deleteLastNode();
    display();

}