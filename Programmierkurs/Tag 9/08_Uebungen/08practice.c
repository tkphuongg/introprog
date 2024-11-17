/*
Willkommen zum achten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des `cd` Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 08practice_test.c -o 08practice_test.o -lm && ./08practice_test.o

Auf diesem Blatt geht es um Arrays.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/*
Geben Sie die kleinste Zahl im Eingabearray zurück.
*/
uint16_t get_minimum(uint16_t numbers[], size_t numbers_len) {
    uint16_t min = numbers[0];
    for(int i = 0; i < numbers_len; i++){
        if(min > numbers[i]){
            min = numbers[i];
        }
    }
    return min;
}

/*
Geben Sie einen Pointer auf das erste Vorkommen der Zahl `7` im Eingabearray zurück, oder `NULL` falls die `7`
nicht vorkommt.
*/
uint16_t *find_seven(uint16_t numbers[], size_t numbers_len) {
    for(int i = 0; i < numbers_len; i++){
        if(numbers[i] == 7){
            return &numbers[i];
        }
    }
    return NULL;
}

/*
Schreiben Sie einen Countdown in das gegebene Array `numbers`.
Bespiel: ist `numbers_len` drei, sollte das Array am Ende die Werte 2, 1, und 0 enthalten (in dieser Reihenfolge).
*/
void countdown(uint16_t numbers[], size_t numbers_len) {
    for(int i = numbers_len - 1; i >= 0; i--){
        numbers[numbers_len - i - 1] = i;
    }
    return;
}

/*
Wir können zweidimensionale Arrays bequem als eindimensionale Arrays darstellen, indem wir
die Zellen durchnummerieren.
Beispiel:

+-+-+-+
|3|4|5|            +-+-+-+-+-+-+
+-+-+-+ entspricht |0|1|2|3|4|5|
|0|1|2|            +-+-+-+-+-+-+
+-+-+-+

Wie können zweidimensionale Koordinaten in eindimensionale Koordinaten umgerechnet werden?
z.B. addressiert die 2d-Koordinate (0, 0) die Zelle 0, (1, 0) addressiert Zelle 1, (2, 0) Zelle 2, (0, 1) Zelle 3,
(1, 1) Zelle 4, und (2, 1) Zelle 5.

Diese Funktion erhält ein eindimensionales Array `arr`, welches ein 2d Array der Breite `width` und Höhe `height`
repräsentiert.
Geben Sie den Wert an der Koordinate (x, y) zurück.
*/
uint16_t get_value(uint16_t arr[], size_t width, size_t height, size_t x, size_t y) {
    int index = y * width + x;
    return arr[index];
}

/*
Ein _lateinisches Quadrat_ ist ein Quadrat, in dem jeder Wert innerhalb seiner Zeile und seiner Spalte nur ein mal vorkommt.
Ist das gegebene Array `arr` ein lateinisches Quadrat der Seitenlängen `length`?
Hinweis: die Transformation ins Zweidimensionale ist wie in der Voraufgabe.
*/
bool check_row(uint16_t arr[], size_t y, size_t length){
        for(int i = 0; i < length - 1; i++)
        {
            for(int j = i + 1; j < length; j++)
            {
                // Check if there are any pairs of num in row
                if (get_value(arr, length, length, i, y) == get_value(arr, length, length, j, y))
                {
                    return false;
                }
            }
        }

    return true;
}

bool check_col(uint16_t arr[], size_t x, size_t length){
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            //Check if there are any pairs of num in col
            if (get_value(arr, length, length, x, i) == get_value(arr, length, length, x, j))
            {
            return false;
            }
        }
    }
    return true;
}

bool is_latin_square(uint16_t arr[], size_t length) {
    for(size_t x = 0; x < length; x++){
        if (check_col(arr, x, length) == false){
            return false;
        }
    }

    for(size_t y = 0; y < length; y++){
        if (check_row(arr, y, length) == false){
            return false;
        }
    }

    return true;
}

/*
Ein _magisches Quadrat_ ist ein Quadrat, in dem die Summe der Werte in jeder Zeile, Spalte, und der beiden großen
Diagonalen, identisch ist.
Ist das gegebene Array `arr` ein magisches Quadrat der Seitenlängen `length`?
Hinweis: die Transformation ins Zweidimensionale ist wie in der Voraufgabe.
*/
bool check_sum_row(uint16_t arr[], size_t length, uint16_t sum, size_t y){
    // Check individual row
    int total = 0;
    
    // Calculate total of num in row
    for (int x = 0; x < length; x++){
        total += get_value(arr, length, length, x, y);
    }

    return total == sum;
}

bool check_sum_col(uint16_t arr[], size_t length, uint16_t sum, size_t x){
    // Check individual col
    int total = 0;

    // Calculate total of num in col
    for (int y = 0; y < length; y++){
        total += get_value(arr, length, length, x, y);
    }
    return total == sum;
}

bool check_sum_diagonal(uint16_t arr[], size_t length, uint16_t sum){
    // Check both diagonals
    uint16_t total1 = 0, total2 = 0;
    
    // Calculate each diagonal total
    for (int i = 0; i < length; i++){
        total1 += get_value(arr, length, length, i, i);
    }

    for (int j = 0; j < length; j++){
        total2 += get_value(arr, length, length, j, length - j - 1);
    }

    return (total1 == sum && total2 == sum);
}

bool is_magic_square(uint16_t arr[], size_t length) {
    // Have 1st row be sample sum
    uint16_t sum = 0; 
    for (int i = 0; i < length; i++){
        sum += arr[i];
    }

    // Check each col
    for(size_t x = 0; x < length; x++){
        if (check_sum_col(arr, length, sum, x) == false){
            return false;
        }
    }

    // Check each row
    for(size_t y = 0; y < length; y++){
        if (check_sum_row(arr, length, sum, y) == false){
            return false;
        }
    }
    
    // Check diagonal
    return check_sum_diagonal(arr, length, sum);
}