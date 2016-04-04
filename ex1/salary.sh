#!/bin/sh
printf "Enter the basic pay of the employee: "
read basic
hra=500
da=`expr $basic \* 98`
if [ $basic -lt 1500 ]
then
	hra=`expr $basic \* 10`
	da=`expr $basic \* 90`
fi
gross=$(echo "scale=2; $basic + $hra / 100 + $da / 100" | bc)
echo $gross
