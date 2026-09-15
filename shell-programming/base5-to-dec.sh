#!/bin/bash

echo -n "Enter Base 5 Number: "

read base5_no

b5_no=$base5_no

dec_no=0

pow=1

while [ $b5_no -gt 0 ]
do
	
	rem=$((b5_no % 10))

	dec_no=$((dec_no + pow * rem))

	pow=$((pow * 5))

	b5_no=$((b5_no / 10))

done

echo "The Decimal Equivalent of $base5_no is $dec_no"

