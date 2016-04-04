#! /bin/sh
val=`ls | wc -l`
echo Total number of files: $val
ls -R $1
