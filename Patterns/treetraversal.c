
#include<stdio.h>
typedef struct binarytree
{
        char data;
        struct binarytree *lchild;
        struct binarytree *rchild;
}node;
void create(node *root)
{
        node *new;
        char x;
        printf("Enter the data into the left child of %c(Enter n for NO)",root->data);
        scanf(" %c",&x);
        if(x!='n'&&x!='N')
        {
                new=(node *)malloc(sizeof(node));
                new->data=x;
                new->lchild=NULL;
                new->rchild=NULL;
                root->lchild=new;
                create(root->lchild);
        }
        printf("Enter the data into right child of %c(enter n for NO)",root->data);
        scanf(" %c",&x);
        if(x!='n'&&x!='N')
        {
                new=(node *)malloc(sizeof(node));
                new->data=x;
                new->lchild=NULL;
                new->rchild=NULL;
                root->rchild=new;
                create(root->rchild);
        }
}
void inorder(node *p)
{
        if(p!=NULL)
        {
                inorder(p->lchild);
                printf("%c  ",p->data);
                inorder(p->rchild);
        }
}
void preorder(node *p)
{
        if(p!=NULL)
        {
                printf("%c  ",p->data);
                preorder(p->lchild);
                preorder(p->rchild);
        }
}
void postorder(node *p)
{
        if(p!=NULL)
        {
                postorder(p->lchild);
                postorder(p->rchild);
                printf("%c  ",p->data);
        }
}
main()
{
        node *root;
        char x;int ch;
        printf("Enter the data into root\n");
        scanf(" %c",&x);
        root=(node *)malloc(sizeof(node));
        root->data=x;
        root->lchild=NULL;
        root->rchild=NULL;
        while(1)
        {
                printf("\n1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
                printf("Enter the choice\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("create the tree\n");
                                create(root);
                                break;
                        case 2: printf("The inorder traversal of the binarytree is\n");
                                inorder(root);
                                break;
                        case 3: printf("The preorder traversal of the binarytree is\n");
                                preorder(root);
                                break;
                        case 4: printf("The postorder traversal of the binarytree is\n");
                                postorder(root);
                                break;
                        case 5: exit(0);
                }
        }
}
