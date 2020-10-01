
#include<stdio.h>
struct cll
{
        int data;
        struct cll *next;
};
typedef struct cll node;
node *create(node *first);
void display(node *first);
int countnodes(node *first);
void search(node *first,int x);
node *insert_at_begin(node *first,int x);
node *insert_at_end(node *first,int x);
node *insert_at_middle(node *first,int x,int pos);
node *delete(node *first,int x);
main()
{
    node *head=NULL;
    int ch,i,n,pos,count,x;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.counting nodes\n4.Search\n");
        printf("5.Insert at beginning\n6.Insert at end\n");
        printf("7.Insert at middle\n8.Delete\n9.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
               case 1: head=create(head);
                       break;
               case 2: display(head);
                       break;
               case 3: count=countnodes(head);
                       printf("Number of nodes=%d\n",count);
                       break;
               case 4: printf("Enter an element to search\n");
                       scanf("%d",&x);
                       search(head,x);
                       break;
               case 5: printf("Enter the element to insert\n");
                       scanf("%d",&x);
                       head=insert_at_begin(head,x);
                       printf("The list after inserting the node %d is\n",x);
                       display(head);
                       break;
               case 6: printf("Enter the element to insert\n");
                       scanf("%d",&x);
                       head=insert_at_end(head,x);
                        printf("The list after inserting the node %d is\n",x);
                        display(head);
                       break;
               case 7: printf("Enter the element to insert\n");
                       scanf("%d",&x);
                       printf("Enter the position to insert the element\n");
                       scanf("%d",&pos);
                       head=insert_at_middle(head,x,pos);
                        printf("The list after inserting the node %d is\n",x);
                        display(head);
                        break;
                case 8: printf("Enter the element to delete\n");
                        scanf("%d",&x);
                        head=delete(head,x);
                        printf("The list after deleting the node %d is\n",x);
                        display(head);
                        break;
                case 9:exit(0);
        }
    }
}
node *create(node *first)
{
        node *new,*prev;
        int x;
        printf("Enter the data(Enter -1 to stop):");
        scanf("%d",&x);
        while(x!=-1)
        {
                new=(node *)malloc(sizeof(node));
                new->data=x;
                new->next=NULL;
                if(first==NULL)
                {
                        first=new;
                        prev=new;
                }
                else
                {
                        prev->next=new;
                        prev=new;
                }
                printf("Enter the data(Enter -1 to stop):");
                scanf("%d",&x);
        }
        new->next=first;
        return first;
}
void display(node *first)
{
        node *temp;
        if(first==NULL)
        printf("No list to display\n");
        else
        {
                temp=first;
                while(temp->next!=first)
                {
                        printf("|%d|->",temp->data);
                        temp=temp->next;
                }
                printf("|%d|->",temp->data);
                printf("|%d|",first->data);
        }
}
int countnodes(node *first)
{
        int count=0;
        node *temp;
        if(first==NULL)
           return 0;
        else
        {
           temp=first;
           do
           {
                count++;
                temp=temp->next;
           }while(temp!=first);
           return count;
        }
}
void search(node *first,int x)
{
        node *temp;int flag=0;
        if(first==NULL)
             printf("No list to search\n");
        else
        {
             temp=first;
             do
             {
                if(temp->data==x)
                {
                   flag=1;
                   break;
                }
                temp=temp->next;
             }while(temp!=first);
             if(flag==1)
                printf("%d is found\n",x);
             else
                printf("%d is not found\n",x);
        }
}
node *insert_at_begin(node *first,int x)
{
        node *new,*temp;
        new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL)
        {
                first=new;
                new->next=first;
        }
        else
        {
                temp=first;
                do
                {
                temp=temp->next;
                }while(temp->next!=first);
                temp->next=new;
                new->next=first;
                first=new;
        }
        return first;
}
node *insert_at_end(node *first,int x)
{
        node  *new,*temp;
        new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL)
        {
                first=new;
                new->next=first;
        }
        else
        {
                temp=first;
                do
                {
                     temp=temp->next;
                }while(temp->next!=first);
                temp->next=new;
                new->next=first;
        }
        return first;
}
node *insert_at_middle(node *first,int x,int pos)
{
        node  *new,*temp;
        int i,n;
        new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        temp=first;
        n=countnodes(first);
        if(pos>1&&pos<n)
        {
                for(i=1;i<pos-1;i++)
                {
                 temp=temp->next;
                }
                new->next=temp->next;
                temp->next=new;
        }
        return first;
}
node *delete(node *first,int x)
{
        node *temp,*temp1;
        int flag=0;
        if(first==NULL)
        printf("No list to delete the element\n");
        else if(first->data==x)
        {
                temp=first;
                temp1=first;
                do
                {
                   temp=temp->next;
                }while(temp->next!=first);
                temp->next=first->next;
                first=first->next;
                free(temp1);
        }
        else
        {
             temp=first;
             temp1=first->next;
             while(temp1!=first)
             {
                if(temp1->data==x)
                {
                 flag=1;
                 break;
                }
                else
                {
                 temp=temp1;
                 temp1=temp1->next;
                }
             }
             if(flag==1)
             {
                temp->next=temp1->next;
                free(temp1);
             }
             else
             {
                printf("Element %d is not found\n",x);
             }
        }
        return first;
}
