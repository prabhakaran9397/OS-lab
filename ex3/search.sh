#! /bin/sh
for i in "$@"
do
	echo "$i is present in"
	grep -n $i ./*
done
