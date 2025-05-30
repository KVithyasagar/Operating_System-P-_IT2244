/*print numbers from 1 to 10
1 to 5 should be printed by child process
6 to 10 should be printed in parent process
calculate summation of those numbers
*/


#include<stdio.h>
#include<unistd.h>
int main()
{
	int f1=fork();
	int sum1=0;
	int sum2=0;
	int sum=0
	for(int i=1; i<=10; i++)
	{
		
		if(f1==0)
		{
			printf("I am child process! %d: \n",getppid());
			sum1=sum1+i;
			if(i==6)
			{
				break;
			}
		}	
		else
		{
			if(i>5)
			{
				printf("I am parent process! %d: \n", i);
				sum2=sum2+i;
			}
			
		}
	}
	sum=sum1+sum2;
	printf("Sum is: %d", sum);
	return 0;
}