/*
Willkommen zum sechsten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 06practice_test.c -o 06practice_test.o -lm && ./06practice_test.o

Auf diesem Blatt geht es um Typen.
*/

#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288)
#endif

#include "06_canvas.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>


typedef struct RGB_ {
    float r;
    float g;
    float b;
} RGB;

/*
Färben Sie alle Pixel, deren x-Koordinate kleiner gleich ihrer y-Koordinate sind mit der Farbe 'color1', und alle anderen
Koordinaten mit der Farbe 'color2'.
*/
Canvas right_triangle(Canvas c, RGB color1, RGB color2) {
    // Canvas height and width
    int c_height = canvas_height(c);
    int c_width = canvas_width(c);

    for (int x = 0; x < c_width; x++){
        for (int y = 0; y < c_height; y++){
            if (x <= y)
            {
                canvas_set_r(c, x, y, color1.r);
                canvas_set_g(c, x, y, color1.g);
                canvas_set_b(c, x, y, color1.b);
            }
            else
            {
                canvas_set_r(c, x, y, color2.r);
                canvas_set_g(c, x, y, color2.g);
                canvas_set_b(c, x, y, color2.b);
            }
        }
    }
    return c;
}

/*
Mischen Sie 'color1' und 'color2', indem Sie jeden Farbkanal auf den Mittelpunkt zwischen den Werten der entsprechenden
Farbkanäle von 'color1' und 'color2' setzen.
*/
RGB mix_colors(RGB color1, RGB color2) {
    color1.r = (color1.r + color2.r)/2;
    color1.g = (color1.g + color2.g)/2;
    color1.b = (color1.b + color2.b)/2;

    return color1;
}

/*
Färben Sie alle Pixel wie in der 'right_triangle'-Übung, aber benutzen Sie die Mischung zwischen 'color1' und 'color2' für
die Pixel der direkt aneinander grenzenden Kanten der entstehenden Dreiecke.
*/
Canvas antialiased_right_triangle(Canvas c, RGB color1, RGB color2) {
        // Canvas height and width
    int c_height = canvas_height(c);
    int c_width = canvas_width(c);

    RGB mixed_color = mix_colors(color1, color2);

    for (int x = 0; x < c_width; x++){
        for (int y = 0; y < c_height; y++){
            if (x - y == 0 || x - y == 1)
            {
                canvas_set_r(c, x, y, mixed_color.r);
                canvas_set_g(c, x, y, mixed_color.g);
                canvas_set_b(c, x, y, mixed_color.b);
            }
            else if (x > y)
            {
                canvas_set_r(c, x, y, color2.r);
                canvas_set_g(c, x, y, color2.g);
                canvas_set_b(c, x, y, color2.b);
            }
            else
            {
                canvas_set_r(c, x, y, color1.r);
                canvas_set_g(c, x, y, color1.g);
                canvas_set_b(c, x, y, color1.b);
            }
        }
    }

    return c;
}

/*
Berechnen Sie das 627-fache von 'n', aber geben Sie '-1' zurück, falls 'n' negativ ist, oder falls die Lösung nicht
in einem 'int16_t' dargestellt werden kann.
*/
int16_t times627(int16_t n) {
    int n_times_627 = 627 * n;
    if (n_times_627 > 32767 || n_times_627 < 0){
        return -1;
    }
    return n_times_627;
}

/*
Berechnen Sie den Winkel (in Grad) zwischen der Linie von Punkt (0, 0) nach Punkt (x, y) und der Linie von Punkt
(0, 0) nach Punkt (1, 0), also der X-Achse.

Hinweis: Wir haben weder beigebracht wie die Mathematik dafür funktioniert, noch wie die benötigten Funktionen
im <math.h> Header lauten. Beides lässt sich im Web suchen oder mit KomillitonInnen besprechen.
Das ist explizit gewünscht, nur abzuschreiben ohne selber nachzudenken wäre schade.
*/
float compute_angle(float x, float y) {
    float angle_in_rad;
    if (x == 0 && y > 0){
        return 90.0;
    }
    else if (x == 0 && y < 0){
        return -90.0;
    }
    else {
        angle_in_rad = atan(y / x);
        if (x < 0 && y >= 0){
            angle_in_rad += M_PI;
        }
        else if (x < 0 && y < 0){
            angle_in_rad *= -1.0;
        }
    }
    return angle_in_rad * 180 / M_PI;
}