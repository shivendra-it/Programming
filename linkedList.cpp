#include<bits/stdc++.h>
using namespace std;



struct node{
    int data;
    struct node* next;
};



struct node* addNode(struct node* head,int val){
    struct node* ptr = head;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if(ptr==NULL){
        head = temp;
    }else{
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next = temp;
    }
return head;
}



void display(struct node* head){
    while(head){
        printf("%d ",head->data);
        head= head->next;
    }
    printf("\n");
}



struct node* reverse(struct node* head){
    struct node* ptr;
    struct node* prev,*temp;
    ptr = head;
    if(ptr == NULL || ptr->next == NULL){
        return ptr;
    }
    if(ptr->next->next==NULL){
        head = ptr->next;
        ptr->next = NULL;
        ptr->next->next = ptr;
        return head;
    }
    prev = NULL;
    while(ptr){
        temp=ptr->next;
        ptr->next=prev;
        prev = ptr;
        ptr = temp;
    }
    head=prev;
    return head;
}







int main(){
struct node* root=NULL;
root = addNode(root,1);
root = addNode(root,2);
root = addNode(root,3);
root = addNode(root,4);
root = addNode(root,5);
root = addNode(root,6);
display(root);
root = reverse(root);
display(root);
    return 0;
}