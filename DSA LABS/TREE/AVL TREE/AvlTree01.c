#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    int height;
    struct node *left,*right;
 };

int max(int a,int b){
    return a>b?a:b;
}

struct node* createNode(int val){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    return newNode;
}

int getHeight(struct node *n){
    if(n==NULL) return 0;
    int ldepth=getHeight(n->left);
    int rdepth=getHeight(n->right);
    return max(ldepth,rdepth)+1;
}

int getBalanceFactor(struct node *n){
    if(n==NULL) return 0;
    return getHeight(n->left)-getHeight(n->right);
}

struct node* rightRotate(struct node* y){
    struct node *x=y->left;
    struct node *T2=x->right;
    x->right=y;
    y->left=T2;
    
    x->height=getHeight(x);
    y->height=getHeight(y);
    return x;


}

struct node* leftRotate(struct node* x){
    struct node *y=x->right;
    struct node *T2=y->left;
    x->right=T2;
    y->left=x;
    
    x->height=getHeight(x);
    y->height=getHeight(y);
    return y;


}



struct node* insert(struct node * root,int val){
    if(root==NULL){
        return createNode(val);
    }
    else if (val<root->data)
    {
        root->left=insert(root->left,val);
       
    }
     else if (val>root->data)
    {
       
        root->right=insert(root->right,val);
    }
    root->height=getHeight(root);
    int bf=getBalanceFactor(root);
    if(bf>1 && val < root->left->data){
        root=rightRotate(root);
    }
    else if(bf<-1 && val > root->right->data){
        root=leftRotate(root);
    }
    else if(bf>1 && val > root->left->data){
        root=leftRotate(root);
        root=rightRotate(root);
    }
     else if(bf<-1 && val < root->right->data){
        root=rightRotate(root);
        root=leftRotate(root);
    }

    return root;
}

void preOrder(struct node *root){
    if (root==NULL)
    {
        return;
    }
    printf("\t%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
    

}



int main(){
    struct node *root=NULL;
    root=insert(root,20);
    root=insert(root,15);
    root=insert(root,12);
    root=insert(root,10);






    
    root=insert(root,30);
    preOrder(root);
}

