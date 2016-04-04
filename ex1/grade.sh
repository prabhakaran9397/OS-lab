#! /bin/sh
printf "Enter the mark: "
read a
if [ $a -ge 90 -a $a -le 100 ]
then
                printf " S grade "
elif [ $a -ge 80 -a $a -lt 90 ]
then 
                printf " A grade "

elif [ $a -ge 70 -a $a -lt 80 ]
then
                printf " B grade "

elif [ $a -ge 60 -a $a -lt 70 ]
then
                printf " C grade "
elif [ $a -ge 50 -a $a -lt 60 ]
then
                printf " D grade "
elif [ $a -ge 40 -a $a -lt 50 ]
then
                printf " E grade "
elif [ $a -ge 0 -a $a -lt 40 ]
then
                printf " U grade "
else
		printf "Enter valid Input"
fi
printf "\n"
