#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    struct node *left,*right;
    int data;
};

struct node* createNode(int val){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
}

struct node *insert(struct node *root,int val){
    struct node* newNode=createNode(val);
    if(root==NULL){
        root=newNode;
        return root;
    }
    else{
        struct node *temp=root;
        while (true)
        {
            if(temp->data > val && temp->left==NULL){
                temp->left=newNode;
                break;
            }
            else if (temp->data > val && temp->left !=NULL)
            {
                temp=temp->left;
            }

            else if(temp->data < val && temp->right==NULL){
                temp->right=newNode;
                break;
            }
            else if (temp->data < val && temp->right!=NULL)
            {
                temp=temp->right;
            }
            
        }
        return root;
    }

}

struct node *insertBstRecursive(struct node *root,int val){
    if(root==NULL) {
        struct node* newNode=createNode(val);
        return newNode;
    }
    if(root->data < val){
        root->right=insertBstRecursive(root->right,val);
    }
    else if (root->data > val)
    {
        root->left=insertBstRecursive(root->left,val);
    }
    
}

void inOrderTraversal(struct node *root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    printf("\t%d",root->data);
    inOrderTraversal(root->right);
}

struct node *getInOrderPredecessor(struct node *root){
    struct node *temp=root->left;
    while (temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
    
}

struct node *delete(struct node *root,int targetValue){
    if(root==NULL) return NULL;
    else if (root->left==NULL && root->right==NULL && root->data==targetValue)
    {
        return NULL;
    }
    else if (root->left==NULL & root->right!=NULL && root->data==targetValue)
    {
        return root->right;
    }

    if(root->data < targetValue){
        root->right=delete(root->right,targetValue);
    }
    else if (root->data > targetValue)
    {
        root->left=delete(root->left,targetValue);
    }
    else{
        struct node *inOrderPredecessor=getInOrderPredecessor(root);
        root->data=inOrderPredecessor->data;
        root->left=delete(root->left,inOrderPredecessor->data);
    }
    return root;
    

}

struct node *findNode(struct node *root,int targetVal){
    if(root==NULL) return NULL;
    else if (root->data==targetVal)
    {
        return root;
    }
    else if (root->data > targetVal)
    {
        return findNode(root->left,targetVal);
    }
    else if (root->data < targetVal)
    {
        return findNode(root->right,targetVal);
    }
    
}

int main(){
    struct node *root=NULL;
    // root=insert(root,10);
    // root=insert(root,5);
    // root=insert(root,3);
    // root=insert(root,4);
    // root=insert(root,20);
    // root=insert(root,29);
    // root=insert(root,22);
    root=insertBstRecursive(root,10);
    root=insertBstRecursive(root,5);
    root=insertBstRecursive(root,3);
    root=insertBstRecursive(root,4);
    root=insertBstRecursive(root,20);
    root=insertBstRecursive(root,29);
    root=insertBstRecursive(root,22);

    root=delete(root,29);
    root=delete(root,10);

    if(findNode(root,5)){
        printf("\nNode is found...");
    }
     else{
        printf("\nNode is not found...");
    }

    inOrderTraversal(root);




    return 0;
}