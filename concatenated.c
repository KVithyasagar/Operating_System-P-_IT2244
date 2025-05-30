/*7.write a C program that:
	Accepts two strings as input from the user
	Concatenates the two strings Displays the concatenated result
*/

#include<stdio.h>
#include<string.h>

int main()
{
	char str1, str2, str;
	
	printf("Enter the first string: ");
	scanf("%s", str1);
	
	printf("Enter the second string: ");
	scanf("%s", str2);
	
	strcat(str1,str2);
	
	printf("The concatenated string is: %s\n", str1);
	return 0;
}