#include<stdio.h>
#include<unistd.h>
int main()
{
	fork();
	printf("Hello world!\n");
	return 0;
} //2 times hello world

#include<stdio.h>
#include<unistd.h>
int main()
{
	fork();
	fork();
	printf("Hello world!\n");
	return 0;
} //4 times hello world


#include<stdio.h>
#include<unistd.h>
int main()
{
	int f1=fork();
	if(f1==0)
	{
		printf("I am child\n");
		printf("My parent ID is: %d", getppid());
	}
	else
	{
		printf("I am the parent\n");
		printf("My ID is: %d", getpid());
	}
}