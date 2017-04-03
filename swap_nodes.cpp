#include<bits/stdc++.h>
using namespace std;


struct node {
    int val;
    struct node* next;
};





void swapNodes(struct node **head_ref, int x, int y)
{
   // Nothing to do if x and y are same
   if (x == y) return;
 
   // Search for x (keep track of prevX and CurrX
   struct node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->val != x)
   {
       prevX = currX;
       currX = currX->next;
   }
 
   // Search for y (keep track of prevY and CurrY
   struct node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->val != y)
   {
       prevY = currY;
       currY = currY->next;
   }
 
   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;
 
   // Swap next pointers
   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}




struct node* reverse(struct node* head){
    struct node* ptr,*par,*next;
    ptr=head;
    par=NULL;
    while(ptr){
        next = ptr->next;
        ptr->next = par;
        par = ptr;
        ptr = next;
    }
    return par;
}







void display(struct node* head){
    struct node* str = head;
    while(str){
        printf("%d ",str->val);
        str = str->next;
    }
    printf("\n");
}



struct node* addNode(struct node* head,int x){
    struct node* ptr,*ptr1;
    ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr1->val =x;
    ptr1->next = NULL;
    ptr = head;
    
    if(ptr==NULL){
        head = ptr1;
        return head;
    }
    
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }

    ptr->next=ptr1;

    return head;
}





int main(){

    struct node *head = NULL;
    head = addNode(head,0);
    head = addNode(head,1);
    head = addNode(head,2);
    head = addNode(head,3);
    head = addNode(head,4);
    head = addNode(head,5);
    
    display(head);
    head = reverse(head);
    display(head);
    head = reverse(head);
    display(head);
    swapNodes(&head,2,4);
    display(head);
    swapNodes(&head,1,5);
    display(head);
    swapNodes(&head,0,1);
    display(head);



    
    return 0; 
}