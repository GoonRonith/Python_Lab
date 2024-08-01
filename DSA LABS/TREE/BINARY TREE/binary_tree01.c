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

void InorderTraversal(struct node *root){
    struct node *temp=root;
    while (temp != NULL || top!= NULL){

        while (temp != NULL){
            push(temp);
            temp=temp->left;
        }

        struct node *temp2=pop();
        printf("\t%d",temp2->data);
        temp=temp2->right;
    }
     
}

void PreOrderTraversal(struct node *root){
    struct node *temp=root;
        while (temp != NULL || top!= NULL){

        while (temp != NULL){
            printf("\t%d",temp->data);
            push(temp);
            temp=temp->left;
        }

        struct node *temp2=pop();
        temp=temp2->right;
    }
    
}

void postOrderTraversal(struct node *root){
    struct node *temp=root;
    struct node* temp2=NULL;
  while (temp != NULL || top!= NULL){

        while (temp != NULL){
            push(temp);
            temp=temp->left;
        }
        temp=peek();
        if(temp->right==NULL){
            printf("\t%d",temp->data);
            temp2=pop();
            if(temp2==peek()->right){

                temp=NULL;
            }
            else{
                 temp=peek()->right;
            }
        }
        else{
            if(temp2==temp->right){
                printf("\t%d",temp->data);
                temp2=pop();
                temp=NULL;
            }
            else{
                temp=temp->right;
            }

        }
        
      
        
    }
 
}

void InorderTraversalRecursive(struct node *root){
    if(root==NULL) return;
    InorderTraversalRecursive(root->left);
    printf("\t%d",root->data);
    InorderTraversalRecursive(root->right);
}

void PreOrderTraversalRecursive(struct node *root){
    if(root==NULL) return;
    printf("\t%d",root->data);
    PreOrderTraversalRecursive(root->left);
    PreOrderTraversalRecursive(root->right);
}

void PostOrderTraversalRecursive(struct node *root){
    if(root==NULL) return;
    PostOrderTraversalRecursive(root->left);
    PostOrderTraversalRecursive(root->right);
    printf("\t%d",root->data);
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



int main(){
    // root=create(10);
    // struct node *root2=insertAtLeft(root,20);
    // struct node *root3=insertAtRight(root,30);
    // insertAtLeft(root2,60);
    // insertAtRight(root2,70);
    // insertAtLeft(root3,40);
    // insertAtRight(root3,50);
    root=createTree();
    // printf("\n%d",root->data);


    // InorderTraversalRecursive(root);
    // PreOrderTraversalRecursive(root);
    // PostOrderTraversalRecursive(root);
    // printf("\n%d",root->data);
    // printf("\n%d",root->left->data);
    // printf("\n%d",root->right->data);
    // InorderTraversal(root);
    // PreOrderTraversal(root);
    postOrderTraversal(root);
    return 0;
}