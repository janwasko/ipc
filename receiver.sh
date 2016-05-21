#!/bin/bash
key=$(./ipcmd ftok)
msgid=$(./ipcmd msgget -Q $key -e)
word=$(./ipcmd msgrcv -q $msgid -t 2)

result=$(echo $word | grep -E "^[a-zA-Z]{1}[A-Za-z0-9]+$")
if [ $? -ne 0 ]
then
	echo "Bledny wyraz"
	exit 1
fi

echo "Odebrano: $word"

if [ $(date +%u) -lt 5 ]
then
	echo "Program dziala tylko w piatek, sobote i niedziele"
	exit 1
fi

result=$(echo $word | aspell list)
if [ "$result" != "" ]
then
	echo "Bledny wyraz"
else
	echo "Poprawny wyraz"
fi

