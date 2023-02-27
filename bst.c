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


void inorder(node* root)
{
    if (root == NULL)
        return;
 
    inorder(root->left);
    printf(" %d",root->data);
    inorder(root->right);
}

void preorder(node* p)
{
  if(p)
  {
  printf("%d ",p->data);
  preorder(p->left);
  preorder(p->right);  
  }
}
void postorder(node* p)
{
  if(p)
  {
  postorder(p->left);
  postorder(p->right);  
  printf("%d ",p->data);
  }
}

int main() {
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    int i=0;
    for(i=0;i<n;i++){
        printf("Eneter the element:");
        scanf("%d",&arr[i]);
    }
    
    node* root = constructBst(arr,n);
    printf("Inorder:");
    inorder(root);
    printf("\n");
    
}
