/*
Zur Abgabe einen branch `iprg-b03` erstellen und pushen, in dem als einzige Datei die `03ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 03ex_test.c -o 03ex_test.o -lm && ./03ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 03ex_test.c -o 03ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./03ex_test.o
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Eine Sequenz von Zahlen, die beliebig wachsen kann.
Die Elemente werden hintereinander in einem dynamisch allokierten Array auf dem Heap gespeichert.
Wenn ein Datum hinzugefügt werden soll, aber das Array zu klein ist, soll
ein neues Array doppelter Größe auf dem Heap angelegt werden.
Die alten Daten werden hinein kopiert, das neue Datum angehängt. Das alte Array gefreed.
*/
typedef struct Sequence_ {
    uint16_t *data; /* Alle aktuellen Elemente, hintereinander im Speicher. */
    size_t len; /* Wie viele Elemente enthält die Sequenz gerade? Die ersten `len` vielen Einträge in `data` haben Bedeutung, die restlichen dürfen Unfug sein. */
    size_t capacity; /* Die Größe des aktuellen `data` Arrays. */
} Sequence;

/*
Aufgabe 1: Random Access

Implementieren Sie eine Funktion, die das Element am gegebenen Index in der Sequenz zurückgibt.
Wenn der Index ungültig ist, geben Sie den Wert 0 zurück.
*/
uint16_t seq_get(Sequence seq, size_t index) {
    if (index > seq.len - 1 || seq.len == 0){
        return 0;
    }
    return seq.data[index];
}

/*
Aufgabe 2: Push

Implementieren Sie eine Funktion, die ein neues Element am Ende der Sequenz anhängt.
Wenn die Kapazität des Arrays nicht ausreicht, ersetzen Sie das Array mit einem neuen Array doppelter Größe.
Kopieren Sie die alten Daten in das neue Array, fügen Sie das neue Element ein, und geben Sie den Speicher vom alten Array frei.
Aktualisieren Sie die `len` und `capacity` Felder.

Achtung: unser Testcode wird bei Bedarf `free` für von Ihnen allokierte Arrays aufrufen. Falls Ihr Code fehlerhaft ist, kann das zu Abstürzen führen.
*/
void copy_array(uint16_t *arr_to_copy, uint16_t *new_arr, size_t len){
    for(int i = 0; i < len; i++){
        new_arr[i] = arr_to_copy[i];
    }
}
void seq_push(Sequence *seq, uint16_t element) {
    // If sequence already has maximum elements
    if(seq->capacity == seq->len){
        // Allocate array that's twice as large as old array
        uint16_t *bigger_arr = malloc(2 * seq->capacity * sizeof(uint16_t));

        // Save old array in temporary variable
        uint16_t *small_arr = seq->data;

        // Copy old array into bigger array
        copy_array(seq->data, bigger_arr, seq->capacity);

        // Change sequence to have new array and capacity
        seq->data = bigger_arr;
        seq->capacity *= 2;

        // Free old array
        free(small_arr);

        //Add new element and change len accordingly
        seq->data[seq->len] = element;
        seq->len++;
    }
    else{
        //Add new element and change len accordingly
        seq->data[seq->len] = element;
        seq->len++;
    }
}
