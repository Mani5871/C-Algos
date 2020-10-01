
#include<stdio.h>
main()
{
        int i,j,a[20],temp,n,increment;
        printf("Enter the number of elements:");
        scanf("%d",&n);
        printf("Enter the elements into array\n");
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
        for(increment=n/2;increment>0;increment=increment/2)
        {
           for(i=increment;i<n;i++)
           {
                temp=a[i];
                j=i;
                while(j>=increment&&temp<a[j-increment])
                {
                        a[j]=a[j-increment];
                        j=j-increment;
                }
                a[j]=temp;
           }
        }
        printf("The elements after sorting are\n");
        for(i=0;i<n;i++)
           printf("%d ",a[i]);
}
