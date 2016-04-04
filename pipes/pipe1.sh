x=`date | awk '{print $4}'|awk -F : '{print $1}'`
case $x in
14)
echo "good afternoon"
;;

151515151515151515151515151515)
echo "good evening"
;;

*)
echo "good morning"
;;
esac

