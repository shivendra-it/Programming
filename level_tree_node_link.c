#include<stdio.h>
#include<stdlib.h>


typedef struct listNode
{
      int key;
      struct listNode* left;
      struct listNode* right;
      struct listNode* sibling;
}node;

node* createBST(int size);
void insert(node* root, int key);
void setSiblings(node* root);
void inorder(node *root);

int main()
{
      int size;
      node *root;
      node *list, *it;
      scanf("%d", &size);
      root = createBST(size);
      setSiblings(root);

      inorder(root);
      return 0;
}

node *createBST(int size)
{
      int count, key;
      node *root = NULL;

      for(count = 0; count < size; count ++)
      {
            scanf("%d",&key);
            if(root == NULL)
            {
                  root = (node*)malloc(sizeof(node));
                  root->left = root->right = NULL;
                  root->key = key;
            }
            else
                  insertKey(root, key);
      }
      return root;
}

insertKey(node* root, int key)
{
      node* temp;

      if(key <= root->key)
      {
            if(root->left == NULL)
            {
                  temp = (node*)malloc(sizeof(node));
                  temp->left = temp->right = temp -> sibling = NULL;
                  temp->key = key;
                  root->left = temp;
            }
            else
                  insertKey(root->left, key);

      }
      else
      {
            if(root->right == NULL)
            {
                  temp = (node*)malloc(sizeof(node));
                  temp->left = temp->right = temp-> sibling = NULL;
                  temp->key = key;
                  root->right = temp;
            }
            else
                  insertKey(root->right, key);
      }
}

void setSiblings(node* root)
{
      node *start, *ptr, *it1, *it2;
      start = root;

      it1 = it2 = NULL;

      while(start)
      {
            ptr = start;
            start = NULL;
            it1 = it2 = NULL;

            do
            {
                  if(ptr -> left)
                  {
                        if(!it1)
                        {
                              it1 = ptr -> left;
                              if(!start) start = it1;
                        }
                        else
                        {
                              it2 = ptr -> left;
                              if(!start) start = it2;
                        }
                  }

                  if(it2)
                  {
                        it1 -> sibling = it2;
                        it1 = it2;
                        it2 = NULL;
                  }

                  if(ptr -> right)
                  {
                        if(!it1)
                        {
                              it1 = ptr -> right;
                              if(!start) start = it1;
                        }
                        else
                        {
                              it2 = ptr -> right;
                              if(!start) start = it2;
                        }
                  }

                  if(it2)
                  {
                        it1 -> sibling = it2;
                        it1 = it2;
                        it2 = NULL;
                  }

                  ptr = ptr -> sibling;

            }while(ptr);
      }
}


void inorder(node *root)
{
      if(root)
      {
            inorder(root->left);
            printf(" %d",root->key);
            if(root->sibling)
                  printf("(%d)", root->sibling->key);
            inorder(root->right);
      }
}

/*
9
8 5 12 65 23 43 82 60 24
Input
*/