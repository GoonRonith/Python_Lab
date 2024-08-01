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
int c1=0,c2=0,sub=0;
int degree=0;


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

void InorderTraversalRecursive(struct node *root){
    if(root==NULL) return;
    InorderTraversalRecursive(root->left);
    printf("\t%d",root->data);
    InorderTraversalRecursive(root->right);
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

void getHeight(struct node *root){
    struct node *temp=root;
    while (temp != NULL || top!= NULL){

        while (temp != NULL){
            push(temp);
            temp=temp->left;
            c1++;
        }
        if(c1>c2) c2=c1;

        struct node *temp2=pop();
        temp=temp2->right;
        if(temp2==root){
            c1=1;
            sub=0;
        }
        
        if(temp==NULL){
            sub++;
        }
        else if (temp!=NULL && temp2->left!=NULL)
        {
            c1=c1-sub;
        }
        
    }

}

void getDegree(struct node *curNode){
    if (curNode->left!=NULL)
    {
        degree++;
    }
     if (curNode->right!=NULL)
    {
        degree++;
    } 
}

int main(){
    root=createTree();
    getHeight(root);
    printf("%d->height of the binary tree ",c2-1);
    getDegree(root);
     printf("\n%d->degree of the given node ",degree);
}