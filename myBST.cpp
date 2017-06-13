#include<bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node *left,*right;
};



void addNode(Node *ptr,int val){
    if(ptr == NULL){
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->val =val;
    temp->left = temp->right = NULL;
        ptr = temp;
    }else{
        if(ptr->val >= val)
            addNode(ptr->left,val);
        else
            addNode(ptr->right,val);
    }
}


void createTree(Node *root,int val){

    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->val =val;
    temp->left = temp->right = NULL;

    if(root == NULL){
        root = temp;
    }else{
        if(root->val >= val)
            addNode(root->left,val);
        else
            addNode(root->right,val);
    }

}


void display(Node *root){
    display(root->left);
    cout<<root->val<<" ";
    display(root->right);
}
int main(){
    Node *root = NULL;
    createTree(root,1);
    createTree(root,2);
    createTree(root,5);
    createTree(root,4);
    createTree(root,3);
    createTree(root,7);
    display(root);
    return 0;
}