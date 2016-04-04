#! /bin/sh
printf "Enter the base: "
read a
printf "Enter the power: "
read b
echo "$a ^ $b" | bc
