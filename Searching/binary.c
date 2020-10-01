
#include<stdio.h>
int binarysearch(int a[10],int n,int x);
main()
{
        int a[10],i,j,n,temp,f,x;
        printf("Enter the number of elements:");
        scanf("%d",&n);
        printf("Enter the %d elements\n",n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])
        {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
        }
        printf("Enter the element to search:");
        scanf("%d",&x);
        f=binarysearch(a,n,x);
        if(f==-1)
          printf("The element is not found\n");
        else
          printf("The element is  found at location-%d\n",f+1);
}
int binarysearch(int a[10],int n,int x)
{
     int low=0,high=n-1,mid;
     while(low<=high)
     {
        mid=(low+high)/2;
        if(a[mid]==x)
          return mid;
        else if(a[mid]<x)
          low=mid+1;
        else
          high=mid-1;
     }
     return -1;
}
