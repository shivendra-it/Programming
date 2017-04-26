#include<bits/stdc++.h>
#include<queue>
#define PB push
#define MP make_pair
#define F first
#define S second
using namespace std;


struct Node{
    int val;
    Node* left,*right;
}; 

Node* newNode(int val){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bool isIdenticalRec(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else{
        return (root1&&root2)&&(root1->val == root2->val)&&(isIdenticalRec(root1->left,root2->left))&&(isIdenticalRec(root1->right,root2->right));
    }
}

bool isIdenticalItr(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->val != root2->val){
        return false;
    }

    stack< pair<Node*,Node*> > S;
    S.PB(MP(root1,root2));
    while(!S.empty()){
        root1 = S.top().F;
        root2 = S.top().S;
        S.pop();
        if(root1->val != root2->val){
            return false;
        }

        if(root1->left && root2->left){
            S.PB(MP(root1->left,root2->left));
        }else if(root1->left || root2->left){
            return false;
        }
        
        if(root1->right && root2->right){
            S.PB(MP(root1->right,root2->right));
        }else if(root1->right || root2->right){
            return false;
        }
    }

return true;
}

void printLevel(Node* root,int level){
    if(root==NULL)
        return;
    if(level == 1){
        printf("%d ",root->val);
    }
    printLevel(root->left,level-1);
    printLevel(root->right,level-1);
}
void printLevelSpiral2(Node* root,int level){
    if(root==NULL)
        return;
    if(level == 1){
        printf("%d ",root->val);
    }
    printLevel(root->right,level-1);
    printLevel(root->left,level-1);
}
void printLevelSpiral1(Node* root,int level){
    if(root==NULL)
        return;
    if(level == 1){
        printf("%d ",root->val);
    }
    printLevel(root->left,level-1);
    printLevel(root->right,level-1);
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

void levelOrder(Node* root){
    int h = height(root);
    for(int i =1;i<=h;i++){
        printLevel(root,i);
    }
}

void levelOrder1(Node* root){
    if(root == NULL)
        return;

    queue< Node* > Q;

    Q.push(root);
    while(!Q.empty()){
        Node* temp = Q.front();
        printf("%d ",temp->val);
        
        Q.pop();
        if(temp->left)
        Q.push(temp->left);
        if(temp->right)
        Q.push(temp->right);
    }
    return;

}

void  printSpiral1(Node* root){
    if(root == NULL)
        return;

    list< Node* > Q;
    Node* temp;
    bool flag = true;
    Q.push_back(root);
    while(!Q.empty()){
        int s = Q.size();
        if(flag){

 while(s--){
            temp = Q.front();
            printf("%d ",temp->val);

             Q.pop_front();

            if(temp->right)
            Q.push_front(temp->right);
            flag = !flag;
            if(temp->left)
            Q.push_front(temp->left);
            
        }
        flag = !flag;


        }else{

while(s--){
            temp = Q.front();
            printf("%d ",temp->val);

            Q.pop_back();
            if(temp->left)
            Q.push_back(temp->left);
            if(temp->right)
            Q.push_back(temp->right);
            
}
flag = !flag;

        }
           }
    return;
}

void printSpiral(Node* root){
    int h = height(root);
    for(int i =1;i<=h;i++){
        printLevelSpiral1(root,i);
        i++;
        printLevelSpiral2(root,i);
    }
}

int main(){
    Node* root1;
    root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);


    Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->right->right = newNode(5);

    if(isIdenticalRec(root1,root2)){
        cout<<"Identical"<<endl;
    }else{
         cout<<"Non Identical"<<endl;
    }

    levelOrder(root1);
    cout<<"\n";
    levelOrder1(root1);
    cout<<"\n";
    printSpiral(root1);
    cout<<"\n";
    printSpiral1(root1);
    cout<<"\n";
    if(isIdenticalItr(root1,root2)){
        cout<<"Identical"<<endl;
    }else{
         cout<<"Non Identical"<<endl;
    }
    return 0;
}