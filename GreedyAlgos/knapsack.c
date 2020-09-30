#include<stdio.h>

int main() {
    int i,j,k,n,max;
   
    printf("Enter max weight\n");
    scanf("%d",&max);
   
    printf("Enter the size of array\n");
    scanf("%d",&n);
   
    float wt[n],val[n];
   
    printf("Enter weights\n");
    for(i=0;i<n;i++)
        scanf("%f",wt[i]);
       
    printf("Enter values\n");
    for(i=0;i<n;i++)
    {
        cin>>val[i];
    }
   
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(val[j]/wt[j]<val[j+1]/wt[j+1])
            {
                float t=wt[j];
                wt[j]=wt[j+1];
                wt[j+1]=t;
               
                t=val[j];
                val[j]=val[j+1];
                val[j+1]=t;
            }
        }
    }
       
    float ind[n],cnt=0,pro=0;
   
    for(i=0;i<n;i++)
        ind[i]=0;
    for(i=0;i<n;i++)
    {
        if(cnt+wt[i]>max)
            break;
        ind[i]=1.0;
        cnt+=wt[i];
    }
    if(i<n)
        ind[i]=(max-cnt)/wt[i];
       
    for(i=0;i<n;i++)
    {
        pro+=ind[i]*val[i];
    }
    printf("Total profit is %f",pro);
       
   