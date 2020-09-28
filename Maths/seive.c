#include <stdio.h>
    int main()
    {
        int n;
        printf("Enter the number to generate the primes below that\n");
        scanf("%d",&n);
        int i,j,k,seive[n];
        
        for(i = 2;i <= n; i++)
            seive[i] = 1;
            
        seive[0] = seive[1] = 0;
            
        for(i = 2; i <= n; i++)
        {
            if(seive[i] == 0)
                continue;
            
            for(j = i*i; j <= n; j += i)
                seive[j] = 0;
        }
        
        printf("Prime numbers below %d are:\n",n);
        for(i = 2; i <= n; i++)
        {
            if (seive[i] == 1)
                printf("%d ",i);
        }
    }
