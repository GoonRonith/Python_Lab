//Check two binary trees are identical or not...
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
struct node *r2=NULL;
struct StackNode *top1=NULL;
struct StackNode *top2=NULL;

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

//iterative approach
bool isIdentical(struct node *root1,struct node *root2){
    struct node *temp1=root1;
    struct node *temp2=root2;
    while (temp1!=NULL || temp2 != NULL || top1!=NULL || top2!=NULL){
        
        while (temp1!=NULL || temp2!=NULL){
             if (temp1!=NULL && temp2==NULL) {
                printf("\n1st");
                return false;
             }
             else if (temp1==NULL && temp2!=NULL) {
                 printf("\n2nd");
                return false;
                }

            else if(temp1->data != temp2->data) {
                printf("\n3rd");
                return false;
            }
            push(temp1,&top1);
            push(temp2,&top2);
            temp1=temp1->left;
            temp2=temp2->left;
        }
        temp1=pop(&top1)->right;
        temp2=pop(&top2)->right;
        printf("\n4th");
    }

    return true;
}

//iterative approach
bool isIdenticalRecursive(struct node *root1,struct node *root2){
   if (root1 == NULL && root2 == NULL) {
        return true;  // Both trees are empty, consider them identical
    }
    
    if (root1 == NULL || root2 == NULL) {
        return false; // One tree is empty while the other is not, consider them not identical
    }

    if (root1->data != root2->data) {
        return false;
    }
 
     return isIdenticalRecursive(root1->left, root2->left) && isIdenticalRecursive(root1->right, root2->right);
}



int main(){
    r1=createTree();
    r2=createTree();
    if (isIdenticalRecursive(r1,r2))
    {
        printf("\nidentical");
    }
    else{
        printf("\nnot identical");
    }
    
}