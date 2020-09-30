#include<stdio.h>

int main() {
    printf("Enter the size of array\n");
    int i,j,k,n;
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements\n");
    
    for(i = 0;i < n; i++)
        scanf("%d",&a[i]);
        
    int key;
    printf("Enter the element to search\n");
    scanf("%d",&key);
    
    for(i = 0; i < n; i++)
        if(a[i] == key)
            break;
    if(i < n)  
        printf("Element found\n");
    else
        printf("Element not found\n");
}