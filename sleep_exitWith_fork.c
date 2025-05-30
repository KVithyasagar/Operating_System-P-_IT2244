#include<stdio.h>
#include<unistd.h> //for fork(), sleep()
#include<stdlib.h> //for exit()
#include<sys/wait.h> //for wait()

int main()
{
	pid_t pid;
	printf("Parent process started. PID: %d\n", getpid());
	
	pid = fork();
	if(pid<0)
	{
		perror("fork failed\n");
		exit(1);
	}
	
	else if(pid==0)
	{
		//child process
		printf("Child process. PID: %d, Parent_id:%d, sleeping for 2 seconds...\n", getpid(),getppid());
		sleep(2);
		printf("Child process exiting.\n");
		exit(0); //child process exit with status 0
	}
	else
	{
		//parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("Child exited with status: %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	
	return 0;
}




//kums
#include <stdio.h>  
#include <stdlib.h>  // for exit
#include <unistd.h>  //for fork(), sleep()
#include <sys/wait.h>  //for wait

int main(){
	pid_t pid;
	printf("Parent process started. PID: %d\n");
	
	pid = fork();  // create a new child process
	if(pid<0){
		perror("fork failed");
		exit(1);
	}
	
	if (pid == 0){
		//child process
		printf("Child process.PID: %d, sleeping for 2 seconds... \n" , getpid());
		sleep(2);
		printf("Child process exiting. \n");
		exit(0); // child exit with status 0
	}
	else{
		int status;
		printf("parent waiting for child to finish.. \n");
		wait(&status);   // wait for child to finish
		if(WIFEXITED(status)){ //(WIFEXITED(status)) returns
		// if rue child terminated normally
			printf("Child exited with status : %d\n", WEXITSTATUS(status));
		}else{
			printf("Child did not exit normally. \n");
		}
		printf("Parent process ending.\n");
	}
	return 0;
}