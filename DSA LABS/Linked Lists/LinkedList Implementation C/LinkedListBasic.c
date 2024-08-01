#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
};

int main(){
    struct node *head;
    struct node *secondNode;
    struct node *ThirdNode;
    struct node *temp;
    

    head=(struct node *)malloc(sizeof(struct node));
    secondNode=(struct node *)malloc(sizeof(struct node));
    ThirdNode=(struct node *)malloc(sizeof(struct node));
    temp=head;

    //filling all the data part of all the nodes
    head->data=10;
    secondNode->data=20;
    ThirdNode->data=30;

    //connect the nodes with each other using next part
    head->next=secondNode;
    secondNode->next=ThirdNode;
    ThirdNode->next=NULL;


  //traverse
  while (temp!=NULL)
  {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  
    

}