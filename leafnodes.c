#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node* left, *right;
}node;
int count =0;

node* bst(int key,node *root){
    if(root == NULL){
        root = (node*)malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->data = key;
        return root;
    }
    if(key < root->data){
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


int leafNodes(node* node)
{
  if(node == NULL)      
    return 0;
  if(node->left == NULL && node->right==NULL)
    return 1;           
  else
    return leafNodes(node->left)+ leafNodes(node->right);     
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int i= 0 , arr[n];
    for(i=0;i<n;i++){
        printf("Enter the element:");
        scanf("%d",&arr[i]);
    }
    node* root = constructBst(arr,n);
    printf("The leafnodes are: %d\n",leafNodes(root));
    return 0;
}




