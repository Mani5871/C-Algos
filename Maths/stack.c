
#include<stdio.h>
#define MAX 10
int a[MAX],top=-1;
void display();
void push(int x)
{
        if(top==MAX-1)
                printf("Stack overflown\n");
        else
        {
                ++top;
                a[top]=x;
        }
}
int pop()
{
        int x;
        if(top==-1)
        return -1;
        else
        {
                x=a[top];
                top--;
        }
        return x;
}
main()
{
        int ch,x;
        while(1)
        {
             printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
             printf("Enter the choice\n");
             scanf("%d",&ch);
             switch(ch)
             {
                case 1:printf("Enter the element to insert\n");
                        scanf("%d",&x);
                        push(x);
                        break;
                case 2:x=pop();
                        if(x==-1)
                           printf("Stack underflown\n");
                        else
                           printf("The element popped=%d\n",x);
                        break;
                case 3:printf("The elements in the stack are\n");
                        display();
                        break;
                case 4:exit(0);
                default:printf("Check the choice\n");
             }
        }
}
void display()
{
        int i;
        if(top==-1)
            printf("No element in stack\n");
        else
        {
             for(i=top;i>=0;i--)
                printf("%d\n",a[i]);
        }
}
