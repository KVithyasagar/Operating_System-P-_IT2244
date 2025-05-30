Q1)::Print multiplication table using for loop
::1*2=2
::2*2=4

echo "Enter the number to display the multiplication table"
read num
for i in {1..12}
do
echo "$num $i = $((num*i))"
done

........................
Q2)
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
	
rows=5
for((i=1; i<=rows; i++))
do
	for((j=i; j<rows; j++))
	do
		echo -n " "
	done
	for((k=1; k<=((2*i-1)); k++))
	do
		echo -n "*"
	done
	echo
done

for ((i=rows-1; i>=1; i--))
do
	for((j=rows; j>i; j--))
	do 
		echo -n " "
	done
	for((k=1; k<=((2*i-1)); k++))
	do
		echo -n "*"
	done
	echo
done

* * * * *
*       *
*       *
*       *
* * * * *


for ((i=0; i<5; i++))
do
	echo -n "* "
done
echo " "
for((i=0; i<3; i++))
do
	echo -n "*"
		
	for((j=0; j<6; j++))
	do
		echo -n " "
	done
	echo "*"
done
for((i=0; i<5; i++))
do
	echo -n "* "
done






::check if a file exists
::output:
:: filename="/home/user/nonexistent.txt"
:: File '/home/user/nonexistent.txt' does not exists


::Using a while loop to read a file line-by-line
::output:
::Number of .txt files: 3

if[ -z "$1"]; then
echo "Usage : $0<C:\Users\2021ict88\Desktop\2.2\IT2244_OS>"
exit 1
fi


Q3)
Fibonacci series
0 1 1 2 3 5 8 13 21 34
sum of the first 10 fibonacci numbers is:88

a=0
b=1
sum=0

echo "Fibonacci series:"


for (( i=0; i<10; i++ ))
do
    echo -n "$a "
    sum=$((sum + a))
    fn=$((a + b))
    a=$b
    b=$fn
done

echo
echo "Sum of the first 10 Fibonacci numbers is: $sum"


Q4)
sum of prime numbers between 1 and 100 is: 1060


is_prime() {
    n=$1
    if (( n <= 1 )); then
        return 1
    fi
    for (( i=2; i*i<=n; i++ ))
    do
        if (( n % i == 0 )); then
            return 1
        fi
    done
    return 0
}

sum=0
for (( num=1; num<=100; num++ ))
do
    if is_prime $num; then
        sum=$((sum + num))
    fi
done

echo "Sum of prime numbers between 1 and 100 is: $sum"