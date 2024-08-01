//q1 to q4(searching and deleting nodes)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node *createNode(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node *insert(struct node *root,int data){
    struct node *newNode=createNode(data);
    struct node *temp=root;
    if(root==NULL){
        return newNode;
    }
    else{
        while (temp!=NULL)
        {
            if(temp->data < data && temp->right==NULL){
                temp->right=newNode;
                break;
            }
            else if (temp->data < data && temp->right!=NULL)
            {
                temp=temp->right;
            }
             else if (temp->data > data && temp->left==NULL)
            {
                temp->left=newNode;
                break;
            }
             else if (temp->data > data && temp->left==NULL)
            {
                temp=temp->left;
            }
            
        }
        
    }
    return root;
}

void inOrderTraversal(struct node *root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    printf("\t%d",root->data);
    inOrderTraversal(root->right);
}

bool searchNodeRecursively(struct node *root,int targetValue){
    if(root==NULL) return false;
    else if (root->data==targetValue) return true;

    else if (root->data < targetValue)
    {
        searchNodeRecursively(root->right,targetValue);
    }
    else if (root->data > targetValue)
    {
        searchNodeRecursively(root->left,targetValue);
    }
    
    
}



struct node *getInOrderPredecessor(struct node *root){
    struct node *temp=root->left;
    while (temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
    
}

struct node *delete(struct node *root,int data){
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL && root->data==data){
        free(root);
        return NULL;
    }
    else if (root->left==NULL && root->right!=NULL && root->data==data)
    {
       return root->right;
    }
    
   if(root->data < data){
    root->right=delete(root->right,data);
   }
   else if (root->data > data)
   {
    root->left=delete(root->left,data);
   }
   else{
    struct node *inOrderPredecessor=getInOrderPredecessor(root);
    root->data=inOrderPredecessor->data;
    root->left=delete(root->left,inOrderPredecessor->data);
   }
   return root;  
}

int main(){
    struct node *root=NULL;
    root=insert(root,10);    
    root=insert(root,5);    
    root=insert(root,20);
    root=insert(root,30);

    inOrderTraversal(root);

    if(searchNodeRecursively(root,80)){
        printf("\nNode is found...");
    }
     else{
        printf("\nNode is not found...");
    }

    printf("\nafter deletion");
    root=delete(root,5);
    inOrderTraversal(root);
      printf("\nafter deletion");
    root=delete(root,20);
    inOrderTraversal(root);
      printf("\nafter deletion");
    root=delete(root,10);
    inOrderTraversal(root);
    return 0;
}