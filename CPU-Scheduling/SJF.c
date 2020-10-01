#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char name[5];
    int bt,wt,tat;
}pr;
pr a[20];
pr temp;
int n,twt,ttat,avg,c;
void create()
{
    int i,j;
    printf("enter the no.of processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter process name and burst time\n");
        scanf("%s%d",a[i].name,&a[i].bt);
        a[i].wt=a[i].tat=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].bt>a[j].bt)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    a[0].tat=a[0].wt+a[0].bt;
    for(i=1;i<n;i++)
    {
        a[i].wt=a[i-1].tat;
        a[i].tat=a[i].bt+a[i].wt;
    }
    printf("p\tbt\twt\tat\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\n",a[i].name,a[i].bt,a[i].wt,a[i].tat);
    }
}

int main()
{
    create();
}
