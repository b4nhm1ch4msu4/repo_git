#!/usr/bin/bash

echo -n "Enter a number: "
read num1
echo -n "Enter another number: "
read num2
let sum=num2+num1
let pro=num2*num1
echo -e "Sum:\t $num1 + $num2 = $sum"
echo -e "Pro:\t $num1 * $num2 = $pro"
