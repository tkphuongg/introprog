/*
Zur Abgabe einen branch `iprg-b01` erstellen und pushen, in dem als einzige Datei die `01ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && ./01ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./01ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Machen Sie sich in dieser Aufgabe mit dem `Visualizer` (siehe array_visualizer.h) vertraut.
Nutzen Sie die `visualizer_append_array` Funktion, um die Tests zum durchlaufen zu bringen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Jede weitere Zeile wird aus der Zeile davor durch eine einfache Modifikation gewonnen. Die Modifikation ist immer die gleiche.
*/
void modify_arr(uint8_t *arr, size_t len){
    // Move the array to the left 1 cell
    for(int i = len - 1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    // Set the first cell the same color as the second cell
    arr[0] = arr[1];
}

void warmup(Visualizer *v, uint8_t *arr, size_t len) {
    for (int i = 0; i < len; i++){
        visualizer_append_array(v, arr);
        modify_arr(arr, len);
    }

}

/*
Aufgabe 2:
Bringen Sie die Tests zum durchlaufen.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    uint8_t key; 
    int j;
    for (int i = 1; i < len; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        visualizer_append_array(v, arr);
    }
}
