
#include<stdio.h>
struct SLL
{
        int data;
        struct SLL *next;
};
typedef struct SLL node;
node *create(node *first);
void display(node *first);
int countnodes(node *first);
void search(node *first,int x);
node *insert_at_begin(node *first,int x);
node *insert_at_end(node *first,int x);
node *insert_at_middle(node *first,int x,int pos);
node *delete(node *first,int x);
void sort(node *first);
node *reverse(node *first);
node *concatenation(node *L1,node *L2);
main()
{
    node *head=NULL,*L1=NULL,*L2=NULL,*L3;
    int ch,i,n,pos,count,x;
    while(1)
    {
        printf("1.Create\n2.Display\n3.counting nodes\n4.Search\n");
        printf("5.Insert at beginning\n6.Insert at end\n");
        printf("7.Insert at middle\n8.Delete\n9.Sort\n10.Reverse\n11.Concatenation\n");
        printf("12.Exit\n");
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
                        break;
                case 6: printf("Enter the element to insert\n");
                        scanf("%d",&x);
                        head=insert_at_end(head,x);
                        break;
                case 7: printf("Enter the element to insert\n");
                        scanf("%d",&x);
                        printf("Enter the position to insert the element\n");
                        scanf("%d",&pos);
                        head=insert_at_middle(head,x,pos);
                        break;
                case 8: printf("Enter the element to delete\n");
                        scanf("%d",&x);
                        head=delete(head,x);
                        break;
                case 9: sort(head);
                        break;
                case 10:head=reverse(head);
                        break;
                case 11:printf("Create the list1\n");
                        L1=create(L1);
                        printf("Create the list2\n");
                        L2=create(L2);
                        L3=concatenation(L1,L2);
                        printf("The list after concatenation is:\n");
                        display(L3);
                        break;
                case 12:exit(0);
        }
    }
}
node *create(node *first)
{
        node *new,*prev;
        int x;
        printf("Enter the data(Enter -1 to stop)\n");
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
                printf("Enter the data(Enter -1 to stop)\n");
                scanf("%d",&x);
        }
        return first;
}
void display(node *first)
{
        if(first==NULL)
        printf("No list to display\n");
        else
        {
                while(first!=NULL)
                {
                        printf("|%d|->",first->data);
                        first=first->next;
                }
                printf("NULL\n");
        }
}
int countnodes(node *first)
{
        int count=0;
        while(first!=NULL)
        {
                count++;
                first=first->next;
        }
        return count;

}
void search(node *first,int x)
{
        int flag=0;
        while(first!=NULL)
        {
                if(first->data==x)
                {
                   flag=1;
                   break;
                }
                else
                {
                   first=first->next;
                }
        }
        if(flag==1)
        printf("The element %d is found\n",x);
        else
        printf("The element %d is not found\n",x);
}
node *insert_at_begin(node *first,int x)
{
        node *new;
        new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL)
                first=new;
        else
        {
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
                first=new;
        else
        {
                temp=first;
                while(temp->next!=NULL)
                {
                 temp=temp->next;
                }
                temp->next=new;
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
                first=first->next;
                free(temp);
        }
        else
        {
             temp=first;
             temp1=first->next;
             while(temp1!=NULL)
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
                printf("The element %d is not found\n",x);
             }
        }
        return first;
}
void sort(node *first)
{
        node *temp1,*temp2;int x;
        for(temp1=first;temp1->next!=NULL;temp1=temp1->next)
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        if(temp1->data>temp2->data)
        {
                x=temp1->data;
                temp1->data=temp2->data;
                temp2->data=x;
        }
}
node *reverse(node *first)
{
        node *present,*previous,*save;
        present=first;
        previous=NULL;
        while(present!=NULL)
        {
                save=present->next;
                present->next=previous;
                previous=present;
                present=save;
        }
        return previous;
}
node *concatenation(node *L1,node *L2)
{
        node *temp;
        if(L1==NULL)
        return L2;
        else if(L2==NULL)
        return L1;
        else
        {
                temp=L1;
                while(temp->next!=NULL)
                temp=temp->next;
                temp->next=L2;
                return L1;
        }
}
