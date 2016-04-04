#! /bin/shi
i=0
while [ $i -lt 10 ]
do
	if [ $i -eq 5 -o $i -eq 7 ]
	then
		echo $i
	fi
	i=`expr $i + 1`
done
