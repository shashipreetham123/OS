#!/bin/bash

echo -n "Enter a Decimal Number: "

read decimal_no

base5_no=""

dec_no=$decimal_no

while [ $dec_no -gt 0 ]
do

	rem=$((dec_no % 5))

	base5_no=$rem$base5_no

	dec_no=$((dec_no / 5))

done

echo "The Base5 Equivalent of $decimal_no is $base5_no"
