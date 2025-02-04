/*
Zur Abgabe einen branch `iprg-b10` erstellen und pushen, in dem als einzige Datei die `10ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 10ex_test.c -o 10ex_test.o -lm && ./10ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 10ex_test.c -o 10ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./10ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Implementieren Sie folgenden Algorithmus, um ein Array zu partitionieren:

- die `pivot_position` ist initial die erste Stelle im Array
- der Wert an der `pivot_position` ist das `pivot` Element
- solange es rechts der `pivot_position` Elemente gibt, die kleiner oder gleich `pivot` sind:
    - sei `i` die Position des rechtesten solchen Elements
    - rotiere die Werte an den Positionen `pivot_position`, `pivot_position + 1` und `i` nach rechts (siehe Testoutput)
    - inkrementiere die `pivot_position`

Nutzen Sie die `visualizer_append_array` Funktion (siehe `array_visualizer.h` bzw das Semesteraufgabenblatt 01) um den Algorithmus zu visualisieren. Und nutzen Sie die vom Testrunner erstellten Bilder zum Debuggen, und falls Ihnen das zu erwartende Verhalten unklar ist.

Imaginäre Bonuspunkte, wenn Ihre Implementierung in linearzeit läuft.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void visualize_partition(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    int pivot_position = 0;
    int i = len - 1;
    while(pivot_position < len - 1 && i > 0){
        if(arr[pivot_position] > arr[i]){
            uint8_t temp = arr[i];
            arr[i] = arr[pivot_position + 1];
            arr[pivot_position + 1] = arr[pivot_position];
            arr[pivot_position] = temp;
            pivot_position++;
            visualizer_append_array(v, arr);
        }
        else{
            i--;
        }
    }
    return;
}

/*
Aufgabe 2:
Implementieren Sie Quicksort rekursiv, und visualisieren Sie den Algorithmus wie von den Tests verlangt.

Wählen Sie als Pivotelement stets das erste Element eines Teilarrays, und partitionieren Sie mit dem in Aufgabe 1 beschriebenen Algorithmus.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Visualisieren Sie außerdem das Array immer nachdem Sie ein Teilarray der Größe mindestens zwei partitioniert haben.
Tipp 3: Diese Funktion selbst lässt sich nicht sinnvoll rekursiv aufrufen. Schreiben Sie eine geeignete Funktion, und rufen Sie diese in `sort_quickly` auf.
*/
int partition(uint8_t *arr, int left, int right){
    int pivot_position = left;
    int i = right;
    while(pivot_position < right - 1 && i >= left){
        if(arr[pivot_position] > arr[i]){
            uint8_t temp = arr[i];
            arr[i] = arr[pivot_position + 1];
            arr[pivot_position + 1] = arr[pivot_position];
            arr[pivot_position] = temp;
            pivot_position++;
        }
        else{
            i--;
        }
    }
    return pivot_position;
}

void visualize_sort(Visualizer *v, uint8_t *arr, int left, int right, int pivot){
    if (left == right){
        return;
    }
    else{
        pivot = partition(arr, left, right);
        // visualizer_append_array(v, arr);
        visualize_sort(v, arr, left, pivot - 1, 0);
        visualize_sort(v, arr, pivot + 1, right, 0);
    }
}

void sort_quickly(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    // int left = 0;
    // int right = len - 1;
    // int first_pivot = partition(arr, left, right);
    visualize_sort(v, arr, 0, len - 1, 0);
    visualizer_append_array(v, arr);
    return;
}
