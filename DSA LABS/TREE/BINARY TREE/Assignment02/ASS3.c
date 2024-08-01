#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left,*right;
    int data;
};

struct node *root=NULL;
int idx=0;

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

struct node* createTree(int *arr){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    int x,choice;
    if(idx>2) return NULL;
    printf("\n%d is the next element->",arr[idx]);
    printf("\nEnter data:-> [-1 for no node and 1 for proceed]");
    scanf("%d",&choice);
    if (choice==-1 || idx>4){
        return NULL;
        }
    x=arr[idx++];
    newnode->data=x;
    printf("\nenter left child:->");
    newnode->left=createTree(arr);
    printf("\nenter right child:->");
    newnode->right=createTree(arr);
    return newnode;
}



int main(){
    int arr[]={10,20,30};
    root=createTree(arr);
    levelOrderTraversal();
    
}