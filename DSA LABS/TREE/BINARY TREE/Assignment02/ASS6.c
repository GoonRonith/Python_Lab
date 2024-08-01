#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left,*right;
    int data;
};

struct StackNode{
    struct node *current;
    struct StackNode* next;
};

struct node *root=NULL;
struct StackNode *top=NULL;

struct StackNode* push(struct node *item){
    struct StackNode *newnode=(struct StackNode*)malloc(sizeof(struct StackNode));
     newnode->current=item;
    if(top==NULL){
        newnode->next=NULL;
    }
    else{
        newnode->next=top;
    }
    top=newnode;
}

struct node *pop(){
    if(top==NULL){
        return NULL;
    }
        struct node *popNode=top->current;
        top=top->next;

    return popNode;
}

struct node *peek(){
    return top->current;
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

int getTotalLeafNodes(struct node *root){
    struct node *temp=root;
    int leafNodes=0;
    while (temp!=NULL || top!=NULL)
    {
       while (temp!=NULL)
       {
        push(temp);
        temp=temp->left;
       }
       struct node *temp2=pop();
       temp=temp2->right;
       if (temp2->left==NULL && temp2->right==NULL)
       {
        leafNodes++;
       }
    }
    return leafNodes;
}

int getTotalInternalNodes(struct node *root){
    struct node *temp=root;
    int internalNodes=0;
    while (temp!=NULL || top!=NULL)
    {
       while (temp!=NULL)
       {
        push(temp);
        temp=temp->left;
       }
       struct node *temp2=pop();
       temp=temp2->right;
       if (temp2->left!=NULL && temp2->right!=NULL)
       {
        internalNodes++;
       }
       else if (temp2->left!=NULL || temp2->right!=NULL)
       {
        internalNodes++;
       }
    }
    return internalNodes;
}

int main(){
    root=createTree();
     printf("\n%d ->total leaf node",getTotalLeafNodes(root));
    printf("\n%d ->total intrenal node",getTotalInternalNodes(root));
}