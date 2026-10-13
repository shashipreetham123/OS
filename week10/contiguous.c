#include <stdio.h>
#define MAX 50

int main()
{
    int disk[MAX] = {0};
    int start, length, i, isFree = 1;

    printf("CONTIGUOUS FILE ALLOCATION\n");
    printf("Enter starting block (0-49): ");
    scanf("%d", &start);

    printf("Enter file length: ");
    scanf("%d", &length);

    if (start < 0 || start >= MAX ||
        length <= 0 || start + length > MAX)
    {
        printf("Invalid block range or file length!\n");
        return 0;
    }

    /* Check whether consecutive blocks are free */
    for (i = start; i < start + length; i++)
    {
        if (disk[i] == 1)
        {
            isFree = 0;
            break;
        }
    }

    if (isFree)
    {
        /* Allocate the blocks */
        for (i = start; i < start + length; i++)
            disk[i] = 1;

        printf("\nFile allocated successfully.\n");
        printf("Allocated blocks: ");

        for (i = start; i < start + length; i++)
            printf("%d ", i);

        printf("\n");
    }
    else
    {
        printf("File allocation failed!\n");
    }

    return 0;
}
