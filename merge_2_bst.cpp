#include<stdio.h>
#include<stdlib.h>


typedef struct listNode
{
      int key;
      struct listNode* left;
      struct listNode* right;
}node;

node* createBST(int size);
void insert(node* root, int key);
void inorder(node* root);
void merge(node* root1, node* root2);

int main()
{
      int size1, size2;
      node *root1, *root2, *mergedRoot;
      node *list, *it;
      scanf("%d", &size1);
      root1 = createBST(size1);

      scanf("%d", &size2);
      root2 = createBST(size2);

      printf("\nTree1 : ");
      inorder(root1);
      printf("\nTree 2 : ");
      inorder(root2);

      merge(root1, root2);

      printf("\nAfter Merge : ");
      inorder(root1);
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
                  temp->left = temp->right = NULL;
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
                  temp->left = temp->right = NULL;
                  temp->key = key;
                  root->right = temp;
            }
            else
                  insertKey(root->right, key);
      }
}

void inorder(node *root)
{
      if(root)
      {
            inorder(root->left);
            printf("%d ",root->key);
            inorder(root->right);
      }
}

void merge(node* root1, node* root2)
{
      node* temp;
      if(root1 && root2)
      {
            if(root1->key < root2->key)
            {
                  temp = root2->left;
                  root2->left = NULL;
                  merge(root1, temp);
                  if(root1->right)
                        merge(root1->right, root2);
                  else
                        root1->right = root2;
            }
            else
            {
                  temp = root2->right;
                  root2->right = NULL;
                  merge(root1, temp);
                  if(root1->left)
                        merge(root1->left, root2);
                  else
                        root1->left = root2;
            }
      }
}
