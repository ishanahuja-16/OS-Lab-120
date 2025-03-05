#include <stdio.h>

int arr[100];

void main()
{
    int n, count = 0;
    printf("Enter Total Elements In Array\n");
    scanf("%d", &n);

for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                arr[j] = -1;
                break;
            }
        }
    }
    printf("Total Duplicates In the Array are %d\n", count);
}
