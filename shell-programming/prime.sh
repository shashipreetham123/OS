#!/bin/bash

echo -n "Enter a Number: "

read num

for ((i=2;i<=$num/2;i++))
do
	rem=$((num%i))

	if [ $rem -eq 0 ]
	
	then
		echo "$num is Not a Prime Number."
		exit 0
	fi
done

echo "$num is a Prime Number"
