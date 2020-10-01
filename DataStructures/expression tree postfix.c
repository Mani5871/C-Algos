typedef struct node
{
        char data;
        struct node *left,*right;
}exp;
exp *stk[5],*ptr;
int top=-1;
void push(exp*);
exp* pop();
void preorder(exp*);
void inorder(exp*);
void postorder(exp*);
~



#include<stdio.h>
#include<stdlib.h>
#include"postexptree.h"
void push(exp *ptr)
{
        stk[++top]=ptr;
}
exp *pop()
{
        return stk[top--];
}
void inorder(exp *ptr)
{
        if(ptr)
        {
                inorder(ptr->left);
                printf("%c  ",ptr->data);
                inorder(ptr->right);
        }
}
~
~


#include"postexptree.c"
#include<ctype.h>
int main()
{
        int i;
        char a[50];
        exp *p,*q,*r;
        printf("enter postfix exp\n");
        scanf("%s",a);
        for(i=0;a[i]!='\0';i++)
        {
                p=(exp*)malloc(sizeof(exp));
                p->data=a[i];
                p->left=p->right=NULL;
                if(isalnum(a[i]))
                        push(p);
                else
                {
                        q=pop();
                        r=pop();
                        p->left=r;
                        p->right=q;
                        push(p);
                }
        }
        inorder(stk[top]);

}
