
#include<stdio.h>
void mergesort(int a[10],int low,int high);
void merge(int a[10],int low,int mid,int high);
main()
{
        int a[10],i,n;
        printf("Enter the number of elements:");
        scanf("%d",&n);
        printf("Enter the elements into the array\n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        mergesort(a,0,n-1);
        printf("The elements after sorting are\n");
        for(i=0;i<n;i++)
                printf("%d ",a[i]);
}
void mergesort(int a[10],int low,int high)
{
        int mid;
        if(low<high)
        {
                mid=(low+high)/2;
                mergesort(a,low,mid);
                mergesort(a,mid+1,high);
                merge(a,low,mid,high);
        }
}
void merge(int a[10],int low,int mid,int high)
{
        int b[10],i=low,h=low,j=mid+1,k;
        while(h<=mid&&j<=high)
        {
                if(a[h]<=a[j])
                {
                   b[i]=a[h];
                   h=h+1;
                }
                else
                {
                   b[i]=a[j];
                   j=j+1;
                }
                i=i+1;
        }
        if(j>high)
        for(k=h;k<=mid;k++)
        {
                b[i]=a[k];
                i=i+1;
        }
        if(h>mid)
        for(k=j;k<=high;k++)
        {
                b[i]=a[k];
                i=i+1;
        }
        for(k=low;k<=high;k++)
                a[k]=b[k];
}
