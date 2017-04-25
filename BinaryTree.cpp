#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node *left,*right;
};

struct node *newNode(int data){

    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;

return temp;

}

void display(struct node *root){
    if(root == NULL)
        return;
    printf("%d ",root->val);
    display(root->left);
    display(root->right);   
}

int main(){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    display(root);
    return 0;
}