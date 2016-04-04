#!/bin/sh
sum_arg=`expr $1 + $2`
echo SUM is $sum_arg
printf "Enter number 1: "
read a
printf "Enter number 2: "
read b
sum_terminal=`expr $a + $b`
echo SUM is $sum_terminal
