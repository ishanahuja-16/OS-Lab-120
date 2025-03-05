
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX];

void main()
{
    int a;int n;int k=0;
    printf("Enter total Elements:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Element to Enter:\n");
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr[i]<arr[j])
                k=arr[i];
                arr[i]=arr[j];
                arr[j]=k;
            }
        }
    printf("The second smallest Element is %d",arr[n-1]);
}
