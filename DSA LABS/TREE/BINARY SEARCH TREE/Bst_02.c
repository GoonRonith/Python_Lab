#include<stdio.h>
#include<stdlib.h>

struct tree
{
    char data;
    struct tree *left, *right;
};

// struct tree
// {
//     int data;
//     struct tree *left, *right;
// };

struct tree *root = NULL;

struct tree* createBstRecursive(struct tree *rt, char val) {
    if (rt == NULL) {
        struct tree *newNode = (struct tree *)malloc(sizeof(struct tree));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (rt->data > val) {
        rt->left = createBstRecursive(rt->left, val);
    } else if (rt->data < val) {
        rt->right = createBstRecursive(rt->right, val);
    }

    return rt;
}

void inOrderTraversal(struct tree *rt) {
    if (rt == NULL) return;
    inOrderTraversal(rt->left);
    printf("\t%c", rt->data);
    inOrderTraversal(rt->right);
    
}

// void inOrder(struct tree *rt) {
//     if (rt == NULL) return;
//     inOrder(rt->left);
//     printf("\t%d", rt->data);
//     inOrder(rt->right);
    
// }

int main() {
    char name[] = "ronith";
    int i;

    for (i = 0; i < 6; i++) {
        root = createBstRecursive(root, name[i]);
    }

    //  int  arr[] = {5,8,9,1,2,7};
    // int i;

    // for (i = 0; i < 6; i++) {
    //     root = createBstRecursive(root, arr[i]);
    // }

inOrderTraversal(root);
    // inOrder(root);

    return 0;
}
