#!/bin/sh
printf "Enter three numbers: "
read p
read q
read m
if [ $p -gt $q  -a  $p -gt $m ]
then
	printf " %s is the greatest " $p
elif [ $q -gt $m ]
then 
	printf " %s is the greatest " $q
else
	printf " %s is the greatest " $m
fi
printf "\n"
