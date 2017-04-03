#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;
};

struct node* addNode(struct node* head,int val){
    struct node* ptr = head;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    if(ptr==NULL){
        ptr->data = val;
        head = ptr;
    }else{
        while(ptr->next){
            ptr=ptr->next;
        }
        temp->data = val;
        temp->next = NULL;
        ptr->next = temp;
    }
return head;
}

void display(struct node* head){
    while(head){
        printf("%d ",head->data);
        head= head->next;
    }
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
    return 0;
}