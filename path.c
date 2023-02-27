#include <stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *left, *right;
}node;

node* bst(int key,node *root){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        bst(key,root);
        return root;
    }
    if (root-> data == 0){
        root->data = key;
        return root;
    }
    else if(key < root->data){
        root->left = bst(key,root->left);
        return root;
    }
    else{
        root->right = bst(key,root->right);
        return root;
    }
}

node* constructBst(int arr[],int n)
{
    if (n == 0)
        return NULL;
    node* root = NULL;
 
    for (int i = 0; i < n; i++)
        root = bst(arr[i],root);
 
    return root;
}


#define max 10
int arr[max];
int top = -1;

void push(int data){
    arr[++top] = data;
    return;
}
void pop(){
    int i=0;
    for(i=0;i<top;i++){
        printf("%d -->",arr[i]);
    }
}

void path(node* root){
    if(root == NULL){
        return;
    }
    push(root->data);
    if(root->left == NULL && root->right == NULL){
        pop();
        printf("%d  \n",root->data);
        return;
    }
    path(root->left);
    arr[top--];
    path(root->right);
    arr[top--];
}

void inorder(node* root)
{
    if (root == NULL)
        return;
 
    inorder(root->left);
    printf(" %d",root->data);
    inorder(root->right);
}

int main() {
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        printf("Enter the element:");
        scanf("%d",&arr[i]);
    }
    
    node* root = constructBst(arr,n);
    path(root);
    
}
