#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left,*right;
    int data;
};

struct node *root=NULL;

struct QueueNode
{
    struct node* current;
    struct QueueNode* next;
};

struct QueueNode *rear=NULL;
struct QueueNode *front=NULL;


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



void insert(struct node *currentNode){
    struct QueueNode *newNode=(struct QueueNode *)malloc(sizeof(struct QueueNode));
    if(rear==NULL && front==NULL){
        newNode->current=currentNode;
        rear=newNode;
        front=newNode;
        newNode->next=NULL;
        
    }
    else{
        newNode->current=currentNode;
        rear->next=newNode;
        rear=newNode;
        
    }

}

struct node *delete ()
{
    struct node *popNode;
    if (front == NULL)
    {
        
        popNode = NULL;
    }
    else if (front == rear)
    {
      
        popNode = front->current;
       
        front = rear = NULL;
    }
    else
    {
        popNode = front->current;
        front = front->next;
    }
    return popNode;
}


void levelOrderTraversal() {
    struct node *temp = root;
    struct node *popNode;
    insert(temp);

    while (front != NULL) {
        popNode = delete();
        printf("\t%d", popNode->data);

        if (popNode->left != NULL) {
            insert(popNode->left);
        }
        if (popNode->right != NULL) {
            insert(popNode->right);
        }
    }
}

int main(){
    root=create(10);
    struct node *root2=insertAtLeft(root,20);
    insertAtRight(root,30);
    insertAtLeft(root2,50);
    insertAtRight(root2,60);
    levelOrderTraversal();

}