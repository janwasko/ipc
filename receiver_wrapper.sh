#!/bin/bash
if [ $(date +%u) -lt 5 ]
then
	echo "Program dziala tylko w piatek, sobote i niedziele"
	exit 1
fi

word=$(./receiver)
result=$(echo $word | aspell list)
if [ "$result" != "" ]
then
	echo "Bledny wyraz"
else
	echo "Poprawny wyraz"
fi
