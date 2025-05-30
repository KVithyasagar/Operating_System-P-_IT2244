#include<stdio.h>
#include<unistd.h>


int is_prime(int numC) 
{
    if (numC < 2) return 0;
    for (int i = 2; i * i <= numC; i++) 
	{
        if (numC % i == 0)
		{
			return 0;
		}  
    }
    return 1;
}


int main()
{
int numA;
 int numB;
 int numC;
 printf("\n enter the number  ");
 scanf("%d",&numA);
 scanf("%d",&numB);
 scanf("%d",&numC);



int f=fork();
 
if(f==0)
{
 int fact=1;

for(int i=1; i<=numA; i++)
{
	fact=fact*i;
}	
	printf("factorial %d\n",fact);
	
}	
else
{
  int f1=fork();

if(f1==0)
{
	
	int a=0;
	int b=1;
	int c;
	printf("fibonnaci %d\n",c);
	for(int i=1;i<=numB;i++)
	{
		c=a+b;
		a=b;
		b=c;
		
		printf("%d\n",c);
	}
	
	
}
else{
	
	
    
   

    printf("Prime numbers up to %d:\n", numC);
    for (int i = 2; i <= numC; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;


	
	
	
	
}	
	
	
	
}
	
	
	
	
	
	
	
	
}