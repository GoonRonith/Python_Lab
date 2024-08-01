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
    root=createTree();
    levelOrderTraversal();

}