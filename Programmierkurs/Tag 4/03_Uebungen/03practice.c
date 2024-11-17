/*
Willkommen zum dritten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 03practice_test.c -o 03practice_test.o -lm && ./03practice_test.o

Auf diesem Blatt geht es unter anderem um:

- Funktionsaufrufe
- Die Canvas
*/

#include <stdio.h>
#include "03_canvas.h"

/*
Geben Sie '1' zurück falls 'x' gerade ist, und '0' falls 'x' ungerade ist.
*/
int is_even(int x) {
    if (x % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

/*
Geben Sie '1' zurück falls 'x' ungerade ist, und '0' falls 'x' gerade ist.
Die Ziffer '2' soll nicht direkt in Ihrer Lösung vorkommen. Nutzen Sie stattdessen 'is_even'.
*/
int is_odd(int x) {
    if (is_even(x)){
        return 0;
    }
    else {
        return 1;
    }
}

/*
Erstellen Sie folgende Zeichnung auf der Canvas:
(Jedes X symbolisiert einen schwarzen Pixel an den jeweiligen (x,y)-Koordinaten)

5---------
4-X-----X-
3---------
2-X-----X-
1--XXXXX--
0---------
/012345678

Nutzen Sie am besten eine Schleife für die Mundlinie.
*/
Canvas draw_smiley(Canvas c) {
    // Save h and w as height and width of canvas
    int h = canvas_height(c);
    int w = canvas_width(c);

    for (int row = 0; row < h; row++){
        // Draw row 0; 3; 5 (---------)
        if (row == 0 || row == 3 || row == 5){
            for (int col = 0; col < w; col++){
                canvas_set_white(c, col, row);
            }
        }
        // Draw row 1 (--XXXXX--)
        if(row == 1){
            for (int col = 0; col < w; col++){
                if (col == 0 || col == 1 || col == 7 || col == 8){
                    canvas_set_white(c, col, row);
                }
                else {
                    canvas_set_black(c, col, row);
                }
            }
        }
        // Draw row 2; 4 (-X-----X-)
        if (row == 2 || row == 4){
            for (int col = 0; col < w; col++){
                if (col == 1 || col == 7){
                    canvas_set_black(c, col, row);
                }
                else {
                    canvas_set_white(c, col, row);
                }
            }
        }
    }

    return c; 
}

/*
Zeichnen Sie ein klassisches Schachbrettmuster, startend bei (0,0) mit Schwarz
*/
Canvas draw_chessboard(Canvas c) {
    // Save h and w as height and width of canvas
    int h = canvas_height(c);
    int w = canvas_width(c);

    // If (0,0) starts with black, then all black tiles have a an even sum of row and col
    for (int row = 0; row < h; row++){
        for(int col = 0; col < w; col++){
            if(is_even(row + col)){
                canvas_set_black(c, col, row);
            }
            else{
                canvas_set_white(c, col, row);
            }
        }
    }
    return c;
}

/*
Diese Funktion soll gefüllte Stufen zeichnen, welche von unten links anfangend nach rechts aufsteigen.
Jede Stufe soll eine Breite von `step_width` haben und eine Höhe von `step_height` (beide sind immer größer als null).
Für mehr Details schauen Sie einfach in das Test-Feedback für den ersten Testfall.
*/
void draw_step(Canvas c, int step_height, int start_x, int start_y){
    // Save h and w as height and width of canvas
    int h = canvas_height(c);
    int w = canvas_width(c);

    // Set limit step
    int end_x = w;
    int end_y = start_y + step_height;

    // If end_y is out of bound, set end_y as canvas top
    if(end_y > h){
        end_y = h;
    }
    
    // Draw step from (start_x, start_y) to (end_x, end_y)
    for (int x = start_x; x < end_x; x++){
        for (int y = start_y; y < end_y; y++){
            canvas_set_black(c, x, y);
        }
    }
}

Canvas i_told_you_about_stairs(Canvas c, int step_width, int step_height) {
    // Save w as height and width of canvas
    int w = canvas_width(c);

    int steps = w / step_width + 1;

    for (int i = 0; i < steps; i++){
        draw_step(c, step_height, i * step_width, i * step_height);
    }

    return c;
}
