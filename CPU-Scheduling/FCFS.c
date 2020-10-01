#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int p,wt,bt,tat;
    struct node *next;
}pr;
pr *head;
pr *ptr,*prev;
pr* create(pr *head,int a, int bur)
{
    ptr=(pr*)malloc(sizeof(pr));
    ptr->p=a;
    ptr->bt=bur;
    ptr->next=NULL;
    if(head==NULL)
    {
        ptr->wt=0;
        ptr->tat=ptr->bt;
        prev=ptr;
        head=ptr;
    }
    else
    {
        prev->next=ptr;
        ptr->wt=prev->tat;
        ptr->tat=(ptr->bt)+(ptr->wt);
        prev=prev->next;
    }
    return ptr;
}
int main()
{
    head=NULL;
    int n,i,bt,a;
    printf("enter the no.of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter process name and burst time\n");
        scanf("%d%d",&a,&bt);
        head=create(head,a,bt);
    }
    printf("\np\tbt\twt\ttat\n");
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d\t%d\t%d\t%d\n",ptr->p,ptr->bt,ptr->wt,ptr->tat);
    }
}
