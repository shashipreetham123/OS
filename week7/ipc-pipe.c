#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main() {
	int pipefd[2];
	pid_t pid;

	char write_message[] = "Hello from Parent Process";
	char read_message[100];

	if(pipe(pipefd) == -1) {
		perror("Pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if(pid == -1) {
		printf("Failed to Create Child Process\n");
		return 0;
	}

	if(pid > 0) {
		printf("Parent Process Created Successfully\n");
		
		close(pipefd[0]);
		write(pipefd[1], write_message, strlen(write_message) + 1);

		printf("Parent Process: Written Data to Pipe\n");
		wait(NULL);
		printf("Parent Process: Child Process Ended\n");
		printf("Parent Process: Parent Process Ended\n");

	}else{
		printf("Child Process Created Successfully\n");
		close(pipefd[1]);
		read(pipefd[0], read_message, sizeof(read_message));
		printf("Child Process: Read From Pipe: %s\n", read_message);
		printf("Child Process: Child Process Ended\n");
	}
	return 0;
}
