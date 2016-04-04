#!/bin/sh 
printf "Enter the year: "
read y
if [ ` expr $y % 400 ` -eq 0 ]
then
	echo "Leap year"
elif [ ` expr $y % 100 ` -eq 0 ]
then
	echo "Not a leap year"
elif [ ` expr $y % 4 ` -eq 0 ]
then
	echo "Leap year"
else
	echo "Not a leap year"
fi
 
