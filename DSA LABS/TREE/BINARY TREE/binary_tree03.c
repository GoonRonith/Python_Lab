
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    struct node *left,*right;
    int data;
};

struct StackNode{
    struct node *current;
    struct StackNode* next;
};

struct node *r1=NULL;
struct StackNode *top1=NULL;
struct StackNode *top2=NULL;
bool flag=false;

struct StackNode* push(struct node *item,struct StackNode **top){
    struct StackNode *newnode=(struct StackNode*)malloc(sizeof(struct StackNode));
     newnode->current=item;
    if(*top==NULL){
        newnode->next=NULL;
    }
    else{
        newnode->next=*top;
    }
    *top=newnode;
    return *top;
}

struct node *pop(struct StackNode **top){
    if(*top==NULL){
        return NULL;
    }
        struct node *popNode=(*top)->current;
        *top=(*top)->next;

    return popNode;
}

struct node *peek(struct StackNode **top){
    return (*top)->current;
}


struct node* create(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL; 
    return newnode;
}

struct node* insertAtLeft(struct node *root,int val){
    root->left=create(val);
    return root->left;
}

struct node* insertAtRight(struct node *root,int val){
    root->right=create(val);
    return root->right;
}

struct node* createTree(){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("\nEnter data:-> [-1 for no node]");
    scanf("%d",&x);
    if (x==-1) return 0;
    newnode->data=x;
    printf("\nenter left child:->");
    newnode->left=createTree();
        printf("\nenter right child:->");
    newnode->right=createTree();
    return newnode;
}


void transform(){
     struct node *temp=r1;
    while (temp != NULL || top1!= NULL){

        while (temp != NULL){
            push(temp,&top1);
            temp=temp->left;
        }

        temp=pop
        
        (&top1);
       
        
        
        
    }
}






int main(){
    r1=createTree();
    
}



