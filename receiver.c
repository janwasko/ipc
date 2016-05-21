#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <stddef.h>
#include <string.h>

typedef struct msg_struct {  
    long type;  
    char data[100];
} msg;

int main()
{
	// Polacz sie z kolejka
	key_t key;
	int msgid;

	key = ftok("/tmp/sth", 'k');
	msgid = msgget(key, 0666 | IPC_CREAT);
	if (msgid < 0) {
		printf("Blad msgget\n");
		exit(1);
	}

	// Odbierz wiadomosc
	msg m;
	if (msgrcv(msgid, &m, sizeof(struct msg_struct), 1, 0) < 0) {
		printf("Blad msgrcv\n");
		exit(1);
	}

	// Sanity
	int i = 0;
	while (m.data[i] != '\0') {
		if (i == 0 && (m.data[i] < 'a' || m.data[i] > 'z')) {
			printf("Bledny wyraz\n");
			exit(1);
		} else {
			if (m.data[i] > 127) {
				printf("Wykracza poza ASCII\n");
				exit(1);
			}
		}
		
		i++;
	}

	printf("%s\n", m.data);
}

