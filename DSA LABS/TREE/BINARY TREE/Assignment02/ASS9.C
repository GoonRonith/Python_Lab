#include <stdio.h>
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
int binaryTree[50];
int idx1=0,idx2=0;

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


int countNodes(int tree[], int index, int size) {
    if (index < size && tree[index] != -1) {
        
        return 1 + countNodes(tree, 2 * index + 1, size) + countNodes(tree, 2 * index + 2, size);
    } else {
        
        return 0;
    }
}

bool isPresent(int val){
    for (int i = 0; i < 50; i++)
    {
        if(binaryTree[i]==val) return true;
    }
    return false;
    
}

int getIndex(int val){
 for (int i = 0; i < 50; i++)
    {
        if(binaryTree[i]==val) return i;
    }
    return -1;
}

void binaryTreeToArray(struct node *root){
    struct node *temp=root;
      while (temp!=NULL || top!=NULL)
    {
       while (temp!=NULL)
       {
        push(temp);
        
        if(isPresent(temp->data)){
            idx1=getIndex(temp->data);
            idx2=idx1;
        }
        else{
            binaryTree[idx1]=temp->data;
        }
            idx1=(2*idx1)+1;
            if (temp->left!=NULL)
            {
            binaryTree[idx1]=temp->left->data;
            }
            else{
                binaryTree[idx1]=-1;
            }
            idx1=idx2;
            idx1=(2*idx1)+2;
            if (temp->right!=NULL)
            {
            binaryTree[idx1]=temp->right->data;
            }
            else{
                binaryTree[idx1]=-1;
            }
            temp=temp->left;
       }
       struct node *temp2=pop();
       temp=temp2->right;
    }
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

int main() {
   
    
    root=createTree();
    binaryTreeToArray(root);
    
    int numberOfNodes = countNodes(binaryTree, 0, sizeof(binaryTree) / sizeof(binaryTree[0]));
    printf("Number of nodes in the binary tree: %d\n", numberOfNodes);

    return 0;
}
