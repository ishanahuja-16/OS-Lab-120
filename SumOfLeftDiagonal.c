#include <stdio.h>
int arr[10][10];
void main()
{
    int sum=0;
    int k,z;
    printf("Enter total rows\n");
    scanf("%d",&k);
    printf("Enter total columns\n");
    scanf("%d",&z);

    printf("Enter Elements\n");
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<z;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Your Array Looks Like\n");
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<z;j++)
        {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<z;j++)
        {
            if(i==j)
            {
                sum=sum+arr[i][j];
            }
        }
    }
    printf("The sum of left diagonal is %d",sum);
}
