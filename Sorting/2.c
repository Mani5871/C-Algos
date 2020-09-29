master

#include<stdio.h>
main()
{
        int a[10],i,j,n,min,minpos,temp;
        printf("Enter the number of elements:");
        scanf("%d",&n);
        printf("Enter the elements into the array\n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
                min=a[i];
                minpos=i;
                for(j=i+1;j<n;j++)
                   if(a[j]<min)
                   {
                        min=a[j];
                        minpos=j;
                   }
                temp=a[i];
                a[i]=a[minpos];
                a[minpos]=temp;
        }
        printf("The elements after sorting are\n");
        for(i=0;i<n;i++)
                printf("%d ",a[i]);
}
master
