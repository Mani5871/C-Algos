#include <stdio.h>

int main()
{
    float p;
    int un,n;
    printf("enter 1 for domestic\n2 for street\n");
    scanf("%d",&n);
    printf("enter number of units\n");
    scanf("%d",&un);
    if(n==1)
    {
        if(un<=200)
         p=un*0.50;
        else if(un<=400)
         p=100+((un-200)*0.65);
        else if(un<=600)
         p=230+((un-400)*0.80);
        else
        p=390+((un-600)*1.00);
    }
    else
    {
        if(un<=100)
         p=un*0.50;
        else if(un<=200)
         p=50+((un-100)*0.60);
        else if(un<=300)
         p=100+((un-200)*0.70);
        else
        p=200+((un-300)*1.00);
    }
    printf("%.1f",p);

    return 0;
}

