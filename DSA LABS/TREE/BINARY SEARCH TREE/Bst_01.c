#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tree
{
    int data;
    struct tree *left,*right;
};

struct tree *root=NULL;

void createTree(int val){
    struct tree *newNode=(struct tree *)malloc(sizeof(struct tree));
    newNode->data=val;
    struct tree *temp=NULL;
    if(root==NULL){
        newNode->left=NULL;
        newNode->right=NULL;
        root=newNode;
    }
    else{
        temp=root;
        while (true)
        {
              if( val < temp->data && temp->left==NULL){
                temp->left=newNode;
                newNode->left=NULL;
                newNode->right=NULL;
                break;
              }
              else if (val < temp->data && temp->left!=NULL)
              {
                
                temp=temp->left;
              }
              else if( val > temp->data && temp->right==NULL){
                temp->right=newNode;
                newNode->left=NULL;
                newNode->right=NULL;
                
                break;
              }
              else if (val > temp->data && temp->right!=NULL)
              {
                
                temp=temp->right;
              }
              
        }
        
    }

}

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

void postOrderTraversal(struct tree *rt) {
    if (rt == NULL) return;
    postOrderTraversal(rt->left);
    postOrderTraversal(rt->right);
    printf("\t%d", rt->data);
}

struct tree* searchNode(struct tree * rt,int element){
  if(rt==NULL) return NULL;
  else if (rt->data==element)
  {
    return rt;
  }
  else if (rt->data < element)
  {
    return searchNode(rt->right,element);
  }
  else if (rt->data >element )
  {
    return searchNode(rt->right,element);
  }
  
  
  
}









// struct tree* searchNode(struct tree * rt,int element){
//   if(rt==NULL) {
//     return NULL;
//   }
//   else if (rt->data==element) return rt;
//   else{
// struct tree *left= searchNode(rt->left,element);
// if(left!=NULL) return left;

// return searchNode(rt->right,element);
//   }
 
// }









int main(){

    // int ch;
    // while (true)
    // {
    //     printf("Enter Node value [-1 for no node]");
    //     scanf("%d",&ch);
    //     if(ch!=-1) {
    //         createTree(ch);
    //         }
    //         else{ break; }
    // }

    // inorderTraversal(root);
  createTree(10);
  createTree(5);
  root=createBSTRecursive(root,50);
  createBSTRecursive(root,25);
  // createBSTRecursive(root,100);
  // createBSTRecursive(root,5);
  // createBSTRecursive(root,28);

  inorderTraversal(root);
  // postOrderTraversal(root);

  struct tree *nd=searchNode(root,50);
  if(nd==NULL){
    printf("\nNode not found...");
  }
  else{
    printf("\nnode is found that is\t%d",nd->data);
  }
  
    



    // createBSTRecursive(root,85);
    // printf("\n%d",root->data);
    // printf("\n%d",root->left->data);
    // printf("\n%d",root->right->data);
    // printf("\n%d",root->right->right->data);
    
}
