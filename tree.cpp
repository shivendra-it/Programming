#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int val;
     Node *left;
     Node *right;
    
};

Node* newNode(int val){
    Node* this1 = (Node*)malloc(sizeof(Node));
    this1->val = val;
    this1->left = NULL;
    this1->right = NULL;
    return this1;
}

void display(Node *root){
    if(root == NULL)
        return;
    printf("%d ",root->val);
    display(root->left);
    display(root->right);
}


    struct node* inorder(struct node *root)
    {
    struct node *q;
    if(root->right)
    {
    q=root->right;
    while(q->left)
    q=q->left;
    return q;
    }
    q=root->parent;
    while(q && q->right==root)
    {
    root=q;
    q=root->parent;
    }
    return q;
    }


int main(){
Node *root;
root = newNode(0);
root->left = newNode(1);
root->right = newNode(2);
root->left->left = newNode(3);
root->left->right = newNode(4);
root->right->left = newNode(5);
root->right->right = newNode(6);

display(root);
    return 0;
}
