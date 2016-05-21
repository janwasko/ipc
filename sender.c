#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <stddef.h>

typedef struct {  
    long type;  
    char data[100];
} msg;

int main()
{
	msg m;
	int text_size = 0;

	char ch;
	while (read(STDIN_FILENO, &ch, 1) > 0) {
		// Wpisz do bufora nowy znak
		m.data[text_size++] = ch;
		
		if (text_size >= 100) {
			printf("Blad - za dlugie slowo\n");
			exit(1);
		}
	}

	m.data[text_size] = '\0';
	m.type = 1;

	// Polacz sie z kolejka
	key_t key;
	int msgid;

	key = ftok("/tmp/sth", 'k');
	msgid = msgget(key, 0666 | IPC_CREAT);
	if (msgid < 0) {
		printf("Blad msgget\n");
		exit(1);
	}

	// Wyslij wiadomosc
	if (msgsnd(msgid, &m, sizeof(m), 0) < 0) {
		printf("Blad msgsnd\n");
		exit(1);
	}
}
