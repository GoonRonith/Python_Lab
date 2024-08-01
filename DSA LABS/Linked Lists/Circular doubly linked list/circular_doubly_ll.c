#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *prev;
int data;
struct node *next;
};

struct node *head=NULL;

void insertAtLast(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        struct node *lastNode=head->prev;
        lastNode->next=newnode;
        newnode->prev=lastNode;
        newnode->next=head;
        head->prev=newnode;
    }
}

void insertAtBeg(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
        if(head==NULL){
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        struct node* lastnode=head->prev;
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=lastnode;
        lastnode->next=newnode;
        head=newnode;
    }

}

void display(){
        struct node* temp = head;
        if(head==NULL){
            printf("\nNo otems to display...");
        }
        else{
    printf("\nTraversal in forward direction \n");
    while (temp->next != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
        }
 
}

void deleteAtBeg(){
    struct node *temp=head;
    struct node *lastNode=head->prev;
    if(head==lastNode){
        head->next=NULL;
        head->prev=NULL;
        head=NULL;
    }
    else{
        head=head->next;
        head->prev=lastNode;
        lastNode->next=head;
        if(head->next==temp){
            head->next=head;
        }

    }
}

void deleteAtLast(){
    struct node *secondLastNode=head->prev->prev;
    if(head==secondLastNode){
        head->next=NULL;
        head->prev=NULL;
        head=NULL;
    }
    else{
        secondLastNode->next=head;
        head->prev=secondLastNode;
    }
    
}

void deleteAfterNode(int val){
    struct node *temp=head;
    struct node *lastNode=head->prev;
    struct node *secondlastNode=head->prev->prev;

    if(lastNode->data==val){
        deleteAtBeg();
    }
    else if(secondlastNode->data == val ){
        deleteAtLast();
    }
    else{
        while(temp->data != val){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->next->prev=temp;
    }
}

void deleteFullList(){
        head->next=NULL;
        head->prev=NULL;
        head=NULL;
}


int main(){
    // insertAtBeg(99);
    // insertAtBeg(97);
    // display();
    // insertAtBeg(88);
    // insertAtLast(10);
    // insertAtLast(20);
    // display();
    // insertAtBeg(50);
    // display();
    // deleteAtBeg();
    // display();
    // deleteAtLast();
    // display();
    insertAtLast(1);
    insertAtLast(2);
    insertAtLast(3);
    insertAtLast(4);
    insertAtLast(5);
    display();
    deleteAfterNode(4);
    display();
    deleteFullList();
    display();
}




