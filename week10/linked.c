#include <stdio.h>
#define MAX 50

int main()
{
    int disk[MAX] = {0};
    int blocks[MAX];
    int n, i, j;

    printf("LINKED FILE ALLOCATION\n");
    printf("Enter number of blocks required: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of blocks!\n");
        return 0;
    }

    printf("Enter the block numbers:\n");

    for (i = 0; i < n; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);

        if (blocks[i] < 0 || blocks[i] >= MAX)
        {
            printf("Invalid block number!\n");
            return 0;
        }

        for (j = 0; j < i; j++)
        {
            if (blocks[i] == blocks[j])
            {
                printf("Duplicate block number!\n");
                return 0;
            }
        }

        if (disk[blocks[i]] == 1)
        {
            printf("Block already allocated!\n");
            return 0;
        }

        disk[blocks[i]] = 1;
    }

    printf("\nFile allocated successfully.\n");
    printf("Linked block chain:\n");

    for (i = 0; i < n; i++)
    {
        if (i < n - 1)
            printf("%d -> ", blocks[i]);
        else
            printf("%d -> NULL\n", blocks[i]);
    }

    return 0;
}
