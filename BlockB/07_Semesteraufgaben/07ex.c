/*
Zur Abgabe einen branch `iprg-b07` erstellen und pushen, in dem als einzige Datei die `07ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 07ex_test.c -o 07ex_test.o -lm && ./07ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 07ex_test.c -o 07ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./07ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1
Bringen Sie die Tests zum durchlaufen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
uint8_t min(uint8_t a, uint8_t b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}

void merge(uint8_t *arr, int start_first_arr, int end_first_arr, int end_second_arr){
    uint8_t new_arr[end_second_arr + 1];
    int index_first_arr = start_first_arr;
    int index_second_arr = end_first_arr + 1;
    int index_new_arr = 0;
    int i = 0;
    while (index_first_arr <= end_first_arr && index_second_arr <= end_second_arr){
        if(arr[index_first_arr] <= arr[index_second_arr]){
            new_arr[index_new_arr] = arr[index_first_arr];
            index_first_arr++;
        }
        else{
            new_arr[index_new_arr] = arr[index_second_arr];
            index_second_arr++;
        }
        index_new_arr++;
    }
    while (index_first_arr <= end_second_arr){
        new_arr[index_new_arr] = arr[index_second_arr];
        index_second_arr++;
        index_new_arr++;
    }
    while (index_second_arr <= end_first_arr){
        new_arr[index_new_arr] = arr[index_first_arr];
        index_first_arr++;
        index_new_arr++;
    }
    for(int j = start_first_arr; j <= end_second_arr; j++)
    {
        arr[j] = new_arr[i];
        i++;
    }
}

void sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    int step = 1;
    int left, middle, right;
    int max_index = len--;
    while (step < max_index){
        left = 0; // index of first leftmost element
        while(left <= len - step){
            middle = left + step - 1; // Index of element at end of first teilarr
            middle = min(middle, max_index);
            right = left + 2 * step - 1; // Index of rightmost element of second teilarr
            right = min(right, max_index);
            merge(arr, left, middle, right);
            visualizer_append_array(v, arr);
            left += 2 * step;
        }
        step *= 2;
    }
}
