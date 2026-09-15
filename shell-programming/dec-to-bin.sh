#!/bin/bash

echo "Enter a Decimal Number: "

read decimal

num=$decimal

bno=""

while [ $num -gt 0 ]

do
	rem=$((num % 2))

	num=$((num / 2))

	bno=$rem$bno
done

echo "The Binary Equivalent of $decimal is $bno"
