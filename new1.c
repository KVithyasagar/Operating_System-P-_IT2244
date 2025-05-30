/*parent p should get 3 user input numbers A B C
then find factorial of child A
then find the fibonacci of child B and find prime of Child C
A one child B and C one child*/

#include<stdio.h>
#include<unistd.h>
int A;
int B;
int C;

int factorial(int A)
{
	int fact = 1;
	for(int i=2; i<=A; i++)
	{
		fact = fact*i;
	}
	return fact;
}
void fibonacci(int B) 
{
    int a = 0, b = 1, next;
    printf("Fibonacci sequence up to %d terms:\n", B);
    for (int i = 0; i < B; i++) 
	{
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void check_prime(int C) {
    if (C < 2) 
	{
        printf("Not a prime number.\n");
        return ;
    }
    for (int i = 2; i*i <= C; i++) 
	{
        if (C % i == 0) 
		{
            printf("%d is not a prime number.\n", C);
            return;
        }
    }
    printf("%d is a prime number.\n", C);
}
int main()
{
	printf("Enter A: ");
	scanf("%d", &A);
	printf("Enter B: ");
	scanf("%d", &B);
	printf("Enter C: ");
	scanf("%d", &C);
	
	int f1=fork();
	
	if(f1==0)
	{
		printf("Factorial: %d",factorial(A);
		printf("Child  A parent_ID: %d", getppid());
	}
	else
	{
		int f2=fork();
		if(f2==0)
		{
			printf("Fibonacci: %d",fibonacci(B);
			printf("Child B parent_ID: %d", getppid());
			printf("Prime or Not: %d", check_prime(C);
			printf("Child C parent_ID: %d", getppid());
			
		}
	}
	return 0;
}