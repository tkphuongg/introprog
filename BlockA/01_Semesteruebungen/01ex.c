/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && ./01ex_test.o

Zum Testen mit valgrind (sehr zu empfehlen!):
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
void modify_array(uint8_t *arr, size_t len){
    uint8_t first_num = arr[0]; 
    for(int i = 0; i < len - 1; i++){
        arr[i] = arr[i+1];
    }
    arr[len-1] = first_num;
}

void warmup(Visualizer *v, uint8_t *arr, size_t len) {
    for(int i = 0; i < len; i++){
        visualizer_append_array(v, arr);
        modify_array(arr, len);
    }
}

/*
Aufgabe 2:
Bringen Sie die Tests zum durchlaufen.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    uint8_t key, j;
    visualizer_append_array(v, arr);

    for(int i  = len - 2; i >= 0; i--){
        key = arr[i];
        j = i + 1;
        while((j < len) && arr[j] > key){
            arr[j - 1] = arr[j];
            j++;
        }
        arr[j - 1] = key;
        visualizer_append_array(v, arr);
    }
}
