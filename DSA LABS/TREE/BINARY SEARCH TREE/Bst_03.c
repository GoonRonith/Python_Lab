#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tree
{
    int data;
    struct tree *left,*right;
};

struct tree *root=NULL;
int totalNodes=0;
int maxNode;



struct tree* createBSTRecursive(struct tree* rt, int val){
    struct tree *newNode=(struct tree *)malloc(sizeof(struct tree));
        newNode->left=NULL;
        newNode->right=NULL;
      newNode->data=val;
    
    if(rt==NULL){
        rt=newNode;
        return rt;
    }
    else{
              if( val < rt->data && rt->left==NULL){
                rt->left=newNode;
              }
              else if (val < rt->data && rt->left!=NULL)
              {
                createBSTRecursive(rt->left,val);
              }
              else if( val > rt->data && rt->right==NULL){
                rt->right=newNode;             
              }
              else if (val > rt->data && rt->right!=NULL)
              {
                createBSTRecursive(rt->right,val);
              }
              
        
        
    }
}

void inorderTraversal(struct tree *rt){
  if(rt==NULL) return;
  inorderTraversal(rt->left);
  printf("\t%d",rt->data);
  inorderTraversal(rt->right);
}

void getTotalNodes(struct tree *rt) {
    if (rt == NULL) return;
    getTotalNodes(rt->left);
     totalNodes++;
    getTotalNodes(rt->right);
}

void getHighestNode(struct tree *rt) {
    if (rt == NULL) {
        return;
    }
    if(rt->left==NULL && rt->right==NULL) {
        maxNode=rt->data;
        return;
    }
    else if (rt->left!=NULL && rt->right==NULL)
    {
       maxNode=rt->data;
        return;
    }
    
    getHighestNode(rt->right);
   
}

int main(){

// root=


   root=createBSTRecursive(root,10);
   createBSTRecursive(root,20);
   createBSTRecursive(root,40);
   createBSTRecursive(root,30);

    getTotalNodes(root);
    printf("\n%d",totalNodes);

    getHighestNode(root);
    printf("\n%d",maxNode);
   
    return 0;
}
