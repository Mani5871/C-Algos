#include"bst1.c"
int main()
{
        int ch,a,b;
        bst *temp1=NULL;
        while(1)
        {
                printf("\nmain menu\n");
                printf("\n1:insert\n2:preorder\n3:postorder\n");
                printf("4:inorder\n5:findmax\n6:findmin\n7:search");
                printf("\n8:delete\n9:exit\n");
                printf("enter ur choice\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:printf("\n insert a value\n");
                               scanf("%d",&a);
                               root=insert(root,a);
                               break;
                        case 2:preorder(root);
                               break;
                        case 3:postorder(root);
                               break;
                        case 4:inorder(root);
                               break;
                        case 5:temp1=findmax(root);
                               printf("\n %d is maximum value\n",temp1->data);
							                                  break;
                        case 6:temp1=findmin(root);
                               printf("\n %d is minimum value\n",temp1->data);
                               break;
                        case 7:printf("enter a element to search\n");
                               scanf("%d",&a);
                               if(search(root,a))
                                       printf("serach found\n");
                               else
                                       printf("search not found\n");
                               break;
                        case 8:printf("enter a value to delete\n");
                               scanf("%d",&a);
                               root=delete(root,a);
                               break;
                        case 9:exit(0);
                }
        }
}