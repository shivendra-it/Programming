#include<bits/stdc++.h>
using namespace std;

struct TreeN{
    int val;
    struct TreeN* left; 
    struct TreeN* right;
};

void insertTreeN(TreeN *root, int val){
   struct TreeN *temp;
    if(root->val >= val){
        if(!root->left){
        temp = (struct TreeN *)malloc(sizeof(TreeN));
        temp->left =  NULL;
        temp->right = NULL;
        temp->val = val;
        root->left = temp;
        }else{
            insertTreeN(root->left,val);
        }
    }else{
        if(!root->right){
        temp = (struct TreeN *)malloc(sizeof(TreeN));
        temp->left =  NULL;
        temp->right = NULL;
        temp->val = val;
        root->right = temp;
        }else{
            insertTreeN(root->right,val);
        }
    }
}


struct TreeN* createTree(int size){
   struct TreeN *root=NULL;
    int val;
    for(int i = 0; i< size;i++){
    scanf("%d",&val);
    if(root==NULL){        
        root = (struct TreeN *)malloc(sizeof(TreeN));
        root->left = root->right = NULL;
        root->val = val;
    }else{
        insertTreeN(root,val);
    }
    }
    return root;
}

void inorder(struct TreeN *root){
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

int main(){
    struct TreeN *root;
    int size;
    scanf("%d",&size);
    root = createTree(size);
    inorder(root);
    return 0;
}
