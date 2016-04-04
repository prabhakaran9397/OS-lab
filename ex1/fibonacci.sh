#!/bin/sh
printf "Enter the value of n: "
read n
a=-1
b=1
while [ $n -ge 0 ]
do
	c=`expr $a + $b`
	printf "%s\t" $c
	a=$b
	b=$c
	n=`expr $n - 1`
done
echo "\n"
