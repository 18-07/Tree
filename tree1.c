#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   int data;
   struct node *left,*right;
}node;

  node *create(node *root)
  {
     int i,n,num;
     node *temp,*parent,*new;
     printf("enter limit:");
     scanf("%d",&n);
     for(i=0;i<n;i++)
   {
      new=(node*)malloc(sizeof(node));
      printf("enter value:");
      scanf("%d",&num);
      new->data=num;
      new->left=new->right=NULL;
      if(root==NULL)
      {
        root=new;
        continue;
      }
      temp=root;
      while(temp!=NULL)
      {
         parent=temp;
         if(num<temp->data)
            temp=temp->left;
         else
            temp=temp->right;
      }
         if(num<parent->data)
            parent->left=new;
         else
            parent->right=new;
     }return root;
   }
      void inorder(node *root)
      {
        node *temp=root;
        if(temp!=NULL)
        { 
          inorder(temp->left);
          printf("\t%d",temp->data);
          inorder(temp->right);
        }
       } 
        
      void preorder(node *root)
      {
        node *temp=root;
        if(temp!=NULL)
        { 
          
          printf("\t%d",temp->data);
          preorder(temp->left);
          preorder(temp->right);
        }
       } 
   
        void postorder(node *root)
      {
        node *temp=root;
        if(temp!=NULL)
        { 
          preorder(temp->left);
          preorder(temp->right);
          printf("\t%d",temp->data);
        }
       } 
   
   void main()
   {
     node *root=NULL;
     root=create(root);
     printf("\n inorder display:");
     inorder(root);
     printf("\n preorder display:");
     preorder(root);
     printf("\n postorder display:");
     postorder(root);
   }  
