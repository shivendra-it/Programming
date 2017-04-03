#include<bits/stdc++.h>
using namespace std;
typedef  struct node Node;
struct Node
{
    int val;
     Node *left;
     Node *right;
    
};

Node* newNode(int val){
    Node* this1;
    this1->val = val;
    this1->left = NULL;
    this1->right = NULL;
    return this1;
}

void display(Node *root){
    printf("%d ",root->val);
    display(root->left);
    display(root->right);
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