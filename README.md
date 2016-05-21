# ipc
Program przygotowany na zajęcia projektowe z Systemów Operacyjnych.

## Instalacja
Aby zbudować projekt wykonaj komendę `make`. Skompiluje ona programy `receiver`
i `sender`, a także zewnętrzny program `ipcmd`.

## Przykład

    $ git clone https://github.com/sciss0r/ipc
    $ cd ipc
    $ make

    # Użycie własnych programów
    $ echo "word" | ./sender
    $ ./receiver_wrapper.sh

    # Użycie skryptów wykorzystujących `ipcmd`
    $ echo "word" | ./sender.sh
    $ ./receiver.sh
