#include<stdio.h>
#include<stdlib.h>
#include"bst1.h"
bst *insert(bst *node,int val)
{
        if(!node)
        {
                temp=(bst*)malloc(sizeof(bst));
                temp->data=val;
                temp->left=temp->right=NULL;
                return temp;
        }
        if(val>node->data)
        {
                node->right=insert(node->right,val);
        }
        else if(val<node->data)
        {
                node->left=insert(node->left,val);
        }
        return node;
}
void preorder(bst*n)
{
        if(n)
        {
                printf("%d\t",n->data);
				preorder(n->left);
                preorder(n->right);
        }
}
void inorder(bst *n)
{
        if(n)
        {
                inorder(n->left);
                printf("%d\t",n->data);
                inorder(n->right);
        }
}
void postorder(bst *n)
{
        if(n)
        {
                postorder(n->left);
                postorder(n->right);
                printf("%d\t",n->data);
        }
}
bst *findmin(bst*n)
{
        if(n->left)
                return findmin(n->left);
        return n;
}
bst *findmax(bst*n)
{
        if(n->right)
                return findmax(n->right);
        return n;
}
int search(bst*n,int val)
{
        if(n)
        {
                if(val>n->data)
                        return search(n->right,val);
                else if(val<n->data)
                        return search(n->left,val);
                else
                        return 1;
        }
        return 0;
}
bst *delete(bst *n,int a)
{
        if(!n)
                return n;
        if(a<n->data)
                n->left=delete(n->left,a);
        else if(a>n->data)
                n->right=delete(n->right,a);
        else
        {
                if(!n->left)
                {
                        temp=n->right;
                        free(n);
                        return temp;
                }
                else if(!n->right)
                {
                        temp=n->left;
                        free(n);
                        return temp;
                }
                temp=findmin(n->right);
                n->data=temp->data;
                n->right=delete(n->right,temp->data);
        }
        return n;
}
