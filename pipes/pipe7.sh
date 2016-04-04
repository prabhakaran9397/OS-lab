echo "Enter String"
read string
i=3
k=`echo $string|cut -c $i`
echo "the 3rd letter is $k"
