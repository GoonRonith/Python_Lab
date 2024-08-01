#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left,*right;
    int data;
};

struct stackNode{
    struct stackNode *next;
    struct node* current;
};
int s=0,d=0;
struct stackNode *top=NULL;
void push(struct node* data){
    struct stackNode *newNode=(struct stackNode*)malloc(sizeof(struct stackNode));
    newNode->current=data;
    if(top==NULL){
        newNode->next=NULL;
    }
    else{
        newNode->next=top;
    }
    top=newNode;
}

struct node *pop(){
    if(top==NULL) return NULL;
    else{
        struct node *popItem=top->current;
        top=top->next;
        return popItem;
    }
    
}

struct node *peek(){
    return top->current;
}
struct queueNode{
    struct queueNode *next;
    struct node *current;
};

struct queueNode *rear=NULL;
struct queueNode *front=NULL;


void EnQ(struct node *currentNode){
struct queueNode *newNode=(struct queueNode *)malloc(sizeof(struct queueNode));
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

struct node* DeQ(){
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

void levelOrderTraversal(struct node *root) {
    struct node *temp = root;
    struct node *popNode;
    EnQ(temp);
    while (front != NULL) {
        popNode = DeQ();
        printf("\t%d", popNode->data);

        if (popNode->left != NULL) {
            EnQ(popNode->left);
        }
        if (popNode->right != NULL) {
            EnQ(popNode->right);
        }
    }
}

int max(int v1,int v2){
    if(v1>=v2){
        return v1;
    }
    return v2;
}

int getHeight(struct node* root){
 
    if(root==NULL) return 0;
    int lh=getHeight(root->left);
    int rh=getHeight(root->right);
    return 1+max(lh,rh);
}

// void getDiameter(struct node* root){
//     if(root==NULL) return;
//     getDiameter(root->left);
//     int lh=getHeight(root->left);
//     int rh=getHeight(root->right);
//     s=lh+rh;
//     d=max(s,d);
//     getDiameter(root->right);
// }

int getDiameter(struct node* root){
    if(root==NULL) return 0;
    int lh=getDiameter(root->left);
    int rh=getDiameter(root->right);
    d=max(d,lh+rh);
    return 1+max(lh,rh);
}




struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    return newNode;
}

struct node* insert(){
    int val;
    printf("\nEnter data:-> [-1 for no node]");
    scanf("%d",&val);
    if(val==-1) return NULL;
    struct node* newNode=createNode(val);
    printf("\nEnter left child of %d",newNode->data);
    newNode->left=insert();
    printf("\nEnter right child of %d",newNode->data);
    newNode->right=insert();
    return newNode;
}

void inOrder(struct node* root){
    struct node* temp=root;
    while (temp!=NULL || top!=NULL)
    {
        while (temp!=NULL)
        {
            push(temp);
            temp=temp->left;
        }
        struct node* temp2=pop();
        printf("\t%d",temp2->data);
        temp=temp2->right;
    }
}

void preOrder(struct node* root){
    struct node* temp=root;
    while (temp!=NULL || top!=NULL)
    {
        while (temp!=NULL)
        {
            printf("\t%d",temp->data);
            push(temp);
            temp=temp->left;
        }
        struct node* temp2=pop();
        
        temp=temp2->right;
        
    }
    
}

void inorderTraversal(struct node* root){
if(root==NULL) return;
inorderTraversal(root->left);
printf("\t%d",root->data);
inorderTraversal(root->right);
}


void preOrderTraversal(struct node* root){
if(root==NULL) return;
printf("\t%d",root->data);
preOrderTraversal(root->left);
preOrderTraversal(root->right);

}

void postOrderTraversal(struct node* root){
if(root==NULL) return;
postOrderTraversal(root->left);
postOrderTraversal(root->right);
printf("\t%d",root->data);
}

int main(){
    struct node* root=NULL;
    root=insert();
    // inorderTraversal(root);
    // preOrderTraversal(root);
    // postOrderTraversal(root);
    // inOrder(root);
    // preOrder(root);
    // levelOrderTraversal(root);
    // printf("%d",getHeight(root));
    getDiameter(root);
    printf("%d",d);
    
    
    return 0;
}

