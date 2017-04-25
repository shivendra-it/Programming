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

struct node *insertBST(struct node *root1,int val){
    if(root1==NULL){
        return newNode(val);
    }
    if(root1->val < val){
        root1->right = insertBST(root1->right,val);
    }else if(root1->val > val){
        root1->left = insertBST(root1->left,val);
    }else{
        cout<<"Duplicate \n";
        return root1;
    }
}


void display(struct node *root){
    if(root == NULL)
        return;
    printf("%d ",root->val);
    display(root->left);
    display(root->right);   
}

int main(){
    struct node *root=NULL;
    root = insertBST(root,1);
    root = insertBST(root,2);
    root = insertBST(root,3);
    root = insertBST(root,4);
    root = insertBST(root,5);
    root = insertBST(root,6);
    root = insertBST(root,7);

    display(root);
    return 0;
}