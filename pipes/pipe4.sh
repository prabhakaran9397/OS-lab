echo "Enter a String"
read str
len=`echo $str|wc -c`
len=`expr $len - 1`
echo "length = $len"
