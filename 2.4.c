#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	char str[100];
	printf("Enter your name\n");
	scanf("%[^\n]%*c", str);

	for(int i = 1; i < 13; i++){
	   pid_t pid = fork();

	   if(pid == 0){
	   	printf("Name = %s", str);
		printf("\n");
		exit(0);}
	   else{
		printf("Waiting for child processes to finish...\n");
	   	wait(NULL);
	   	}

	}

	printf("Job is done.\n");

	return EXIT_SUCCESS;
}
