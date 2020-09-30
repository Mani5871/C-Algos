#include <stdio.h>
#include<math.h>
int main()
{
    int a,b,c,r1,r2,d;
    printf("enter coefficients\n");
    scanf("%d%d%d",&a,&b,&c);
    d=b*b-4*a*c;
    if(d==0)
    {
        r2=r1=-b/(2*a);
        printf("%d%d",r1,r2);
    }
    else if(d<0)
     printf("complex\n");
    else
    {
        r1=(-b+sqrt(d))/(2*a);
        r2=(-b-sqrt(d))/(2*a);
        printf("%d %d",r1,r2);
    }

    return 0;
}

