#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
    int shmid;
    pid_t pid;
    char *shared_memory;

    char message[] = "Hello from Parent Process!";

    /* Create shared memory segment */
    shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);

    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory created successfully.\n");

    /* Create child process */
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0)
    {
        /* Parent Process */

        shared_memory = (char *)shmat(shmid, NULL, 0);

        if (shared_memory == (char *)-1)
        {
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        printf("Parent Process: Writing message to shared memory...\n");

        strcpy(shared_memory, message);

        printf("Parent Process: Message written successfully.\n");

        /* Detach shared memory */
        shmdt(shared_memory);

        /* Wait for child process */
        wait(NULL);

        /* Remove shared memory */
        if (shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }

        printf("Parent Process: Shared memory removed.\n");
    }
    else
    {
        /* Child Process */

        /* Wait for parent to write */
        sleep(1);

        shared_memory = (char *)shmat(shmid, NULL, 0);

        if (shared_memory == (char *)-1)
        {
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        printf("Child Process: Reading message from shared memory...\n");

        printf("Child Process: Message received: %s\n",
               shared_memory);

        /* Detach shared memory */
        shmdt(shared_memory);

        exit(EXIT_SUCCESS);
    }

    return 0;
}