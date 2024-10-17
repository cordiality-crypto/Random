#! /usr/bin/bash

echo $1 $2 '> $x $y'
x=$1
y=$2
if [[ $x > $y ]]
then
	echo "$x is lexiographically larger"
elif [[ $x < $y ]] 
then 
	echo "$y is lexiographically larger"
else
	echo "$x == $y"
fi
