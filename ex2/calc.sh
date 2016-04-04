#!/bin/sh
flag=1
while [ $flag = 1 ]
do
	printf "Enter the first number: "
	read a
	printf "\nAvailable operations are as follows\n"
	printf "[+]\tAddition\n"
	printf "[-]\tSubtraction\n"
	printf "[x]\tMultiplication\n"
	printf "[/]\tDivision\n"
	printf "[neg]\tNegation\n"
	printf "[log]\tLog\n"
	printf "[exp]\tExponent\n"
	printf "[sqrt]\tSquare root\n"
	printf "[exp]\tExponent\n"
	printf "[sin]\tSin\n"
	printf "[cos]\tCos\n"
	printf "[tan]\tTan\n"
	printf "\nEnter the operation: "
	read op
	if [ $op = '+' -o  $op = '-' -o  $op = 'x' -o  $op = '/' -o  $op = '%' -o $op = '^' ]
	then
		printf "\nEnter the Second number: "
		read b
	fi
	if [ $op = '+' ]
	then
		echo "scale=2; $a + $b" | bc
	elif [ $op = '-' ]
	then
		echo "scale=2; $a - $b" | bc
	elif [ $op = 'x' ]
	then
		echo "scale=2; $a * $b" | bc
	elif [ $op = '/' ]
	then
		echo "scale=2; $a / $b" | bc
	elif [ $op = '%' ]
	then
		echo "$a % $b" | bc
	elif [ $op = '^' ]
	then
		echo "scale=2; $a ^ $b" | bc
	elif [ $op = 'sqrt' ]
	then
		echo "scale=2; sqrt($a)" | bc -l
	elif [ $op = 'log' ]
	then
		echo "scale=2; l($a)" | bc -l
	elif [ $op = 'exp' ]
	then
		echo "scale=2; e($a)" | bc -l
	elif [ $op = 'neg' ]
	then
		echo "scale=2; $a * -1" | bc
	elif [ $op = 'sin' ]
	then
		echo "scale=2; s($a)" | bc -l
	elif [ $op = 'cos' ]
	then
		echo "scale=2; c($a)" | bc -l
	elif [ $op = 'tan' ]
	then
		echo "scale=2; s($a) / c($a)" | bc -l
	else
		echo "Please enter a valid operation!"
	fi
	printf "\nPress 0 to exit or 1 to stay "
	read flag
	clear
done
