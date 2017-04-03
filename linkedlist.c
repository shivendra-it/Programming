#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *head = NULL;

struct node* addnode(struct node* head,int val){
    struct node* ptr = head;
    struct node* tmp;
    if (ptr == NULL){
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->val = val;
        ptr->next = NULL;
        return ptr;
    } else if(ptr->next == NULL){
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->val = val;
        tmp->next = NULL;
        ptr->next = tmp;
        return ptr;
    } else{
        while(ptr->next)
        ptr=ptr->next;
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp -> val = val;
        tmp -> next = NULL;
        ptr->next = tmp;
        return head;
    }
}

int main(){
struct node *ptr = head;
head = addnode(head,1);
head = addnode(head,2);
head = addnode(head,3);
head = addnode(head,4);
head = addnode(head,5);
head = addnode(head,6);
head = addnode(head,7);
head = addnode(head,8);
ptr = head;
while(ptr){
printf("%d ",ptr->val);
ptr = ptr->next;
}

    return 0;
}