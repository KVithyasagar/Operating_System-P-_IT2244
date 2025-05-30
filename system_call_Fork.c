#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\nHello world!");
	int f=fork();
	int p=getpid();
	printf("\nThe pid is %d ",p);
	printf("\nThe fork is %d ",f);
	printf("\n");
	
	return 0;
}



//child - I am child
//parent - I am parent
//both id

#include<stdio.h>
#include<unistd.h>
int main()
{
	int f=fork();
	if(f==0)
	{
		printf("\nI am child\n");
	}
	else
	{
		printf("\nI am parent");
	}
	
	return 0;
}


//Process A
// That creates - B,C
#include<stdio.h>
#include<unistd.h>
int main()
{
	int f=fork();
	
	if(f==0)
	{
		printf("I am child\n");
		printf("My parentId is: %d\n", getppid());
	}
	else
	{
		int f1=fork();
		if(f1==0)
		{
			printf("I am sibling\n");
			printf("My parent id: %d\n", getppid());
		}
		else
		{
			printf("I am parent\n");
			printf("My id: %d\n", getpid());
			printf("My parentId: %d\n",getppid());
		} 
		
	}
	
	return 0;
	
	
}




#include<stdio.h>
#include<unistd.h>
int main()
{
	int f=fork();
	
	if(f==0)
	{
		printf("I am child\n");
		printf("My parentId is: %d\n", getppid());
	}
	else
	{
		printf("I am parent\n");
		printf("My id: %d\n", getpid());
		printf("My parentId: %d\n",getppid());
		int f1=fork();
		if(f1==0)
		{
			printf("I am sibling\n");
			printf("My parent id: %d\n", getppid());
		}
		
	}
	
	return 0;
	
	
}