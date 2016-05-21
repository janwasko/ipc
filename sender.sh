#!/bin/bash
read word
key=$(./ipcmd ftok)
msgid=$(./ipcmd msgget -Q $key -e)
./ipcmd msgsnd -q $msgid -t 2 -n $word
