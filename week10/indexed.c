
#include <stdio.h>
#define MAX 50

int main()
{
    int disk[MAX] = {0};
    int indexBlock, blocks[MAX];
    int n, i, j;

    printf("INDEXED FILE ALLOCATION\n");
    printf("Enter index block number (0-49): ");
    scanf("%d", &indexBlock);

    if (indexBlock < 0 || indexBlock >= MAX)
    {
        printf("Invalid index block!\n");
        return 0;
    }

    printf("Enter number of data blocks required: ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX)
    {
        printf("Invalid number of data blocks!\n");
        return 0;
    }

    printf("Enter data block numbers:\n");

    for (i = 0; i < n; i++)
    {
        printf("Data block %d: ", i + 1);
        scanf("%d", &blocks[i]);

        if (blocks[i] < 0 || blocks[i] >= MAX)
        {
            printf("Invalid block number!\n");
            return 0;
        }

        if (blocks[i] == indexBlock)
        {
            printf("Index block cannot be a data block!\n");
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
            printf("Data block already allocated!\n");
            return 0;
        }
    }

    disk[indexBlock] = 1;

    for (i = 0; i < n; i++)
        disk[blocks[i]] = 1;

    printf("\nFile allocated successfully.\n");
    printf("Index block: %d\n", indexBlock);

    printf("Index block contains addresses:\n");
    for (i = 0; i < n; i++)
        printf("%d ", blocks[i]);

    printf("\nData blocks: ");
    for (i = 0; i < n; i++)
        printf("%d ", blocks[i]);

    printf("\n");

    return 0;
}
