read file
cat $file | awk 'BEGIN{count=0;} {for(i=1;i<6;i++) if($i=="cse") {count++;break;}} END{print count}'


