all: sender receiver ipcmd

sender:
	gcc -D _XOPEN_SOURCE=500 -std=c11 -o sender sender.c

receiver:
	gcc -D _XOPEN_SOURCE=500 -std=c11 -o receiver receiver.c

ipcmd:
	./build_ipcmd.sh

clean:
	rm -f sender receiver ipcmd

.PHONY: sender receiver clean
