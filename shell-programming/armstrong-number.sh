#!/bin/bash

echo -n "Enter a Number: "

read num

temp=$num

dgit_sum=0

while [ $temp -gt 0 ]

do
	
	rem=$((temp % 10))

	cube=$((rem * rem* rem))

	dgit_sum=$(($dgit_sum + cube))

	temp=$((temp / 10))

done

if [ $dgit_sum -eq $num ]
then
	echo "$num is an Armstrong Number"
else
	echo "$num is not an Armstring Number"
fi
