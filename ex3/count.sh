#! /bin/sh
for i in "$@"
do
	printf "%s is present in\n"  $i
	grep -c $i ./*
done
