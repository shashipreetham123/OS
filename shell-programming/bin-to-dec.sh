#!/bin/bash

echo "Enter Binary Number: "

read binary_no

dec_no=0

pow=1

bin_no=$binary_no

while [ $bin_no -gt 0 ]
do
	bit=$((bin_no%10))

	bin_no=$((bin_no/10))

	dec_no=$((dec_no + pow * bit))

	pow=$((pow * 2))

done

echo "Decimal Equvalent of $binary_no is $dec_no"
