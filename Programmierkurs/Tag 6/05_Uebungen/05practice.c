/*
Willkommen zum fünften Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des `cd` Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 05practice_test.c -o 05practice_test.o -lm && ./05practice_test.o

Auf diesem Blatt geht es um Rekursion.
*/

#include <stdio.h>
#include "05_canvas.h"
#include "../05_Aufgaben/05ex.c"
/*
Zeichne eine vertikale Linie der Höhe `height` mit unterstem Pixel an Position `(x, y)`.

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
Canvas recursive_line(Canvas c, int x, int y, int width);
int check_pixel(Canvas c, int x, int y, int width, int height);
Canvas check_and_set_black(Canvas c, int x, int y, int width, int height);

Canvas vertical_line(Canvas c, int x, int y, int height) {
    // Canvas height and width
    int c_height = canvas_height(c);
    int c_width = canvas_width(c);

    if(height == 0)
    {
        return c;
    }
    else
    {       
        c = check_and_set_black(c, x, y, c_width, c_height);
        y++;
        height--;
        return vertical_line(c, x, y, height);
    }
    return c;
}

/*
Wie viele Dezimalstellen hat `n` (`n` ist nicht negativ)?

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
int count_digits(int n) {
    if (n < 10)
    {
        return 1;
    }
    else
    {
        n /= 10;
        return 1 + count_digits(n);
    }
}

/*
Zeichne eine Pyramide: die unterste Zeile ist komplett schwarz, die zweitunterste Zeile lässt den ersten und letzten Pixel weiß, die drittunterste Zeile lässt die ersten zwei und die letzten zwei Pixel weiß, usw..

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
int row = 0;
int col = 0;

Canvas pyramid(Canvas c) {
    // Max width
    int max_width = canvas_width(c) - 1;

    if(row == max_width / 2){
        c = recursive_line(c, row, row, max_width - 2 * row + 1);
        row = 0;
        col = 0;
        return c;
    }
    else{
        c = recursive_line(c, row, row, max_width - 2 * row + 1);
        row++;
        return pyramid(c);
    }


}

/*
Zeichne ein Rechteck der Breite `width` und der Höhe `height` mit einem Schachbrettmuster. Der Pixel der linken unteren Ecke liegt bei `(x, y)` und ist schwarz.

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
Canvas chessboard_rectangle(Canvas c, int x, int y, int width, int height) {
    return c;
}

/*
Der Binomialkoeffizient von `n` und `k` ("n über k"), mit `0 <= k <= n` ist wie folgt definiert:

- bin(n, 0) = 1, sonst
- bin(n, n) = 1, sonst
- bin(n, k) = bin(n - 1, k - 1) + bin(n - 1, k)

Berechne `bin(n, k)`.
*/
int binomial_coefficient(int n, int k) {
    if (k == 0 || n == k)
    {
        return 1;
    }
    else
    {
        return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
    }
}

/*
Aufgabe 2:
Der *Sierpinski Carpet der Ordnung 0* ist ein einzelnes schwarzes Pixel.
Der *Sierpinski Carpet der Ordnung n+1* besteht aus acht Sierpinski Carpets der Ordnung n, angeordnet als drei-mal-drei
Quadrat dessen Mittelstück fehlt.

Beispiele (`X` stellt schwarze Pixel dar)
=========================================

Ordnung 0:

X

Ordnung 1:

XXX
X X
XXX

Ordnung 2:

XXXXXXXXX
X XX XX X
XXXXXXXXX
XXX   XXX
X X   X X
XXX   XXX
XXXXXXXXX
X XX XX X
XXXXXXXXX

Siehe auch die Datei `05sierpinski.jpg`

Um in der nächsten Aufgabe den Sierpinski-Carpet auf die Canvas zeichnen zu können müssen Potenzen berechnet werden.
Implementieren Sie die Berechnung der Potenz einer nicht-negativen, ganzzahligen Basis `b` mit einem
nicht-negativen, ganzzahligen Exponenten `exp`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
int power(int b, int exp){
   if(exp == 0)
   {
    return 1;
   }
   else
   {
    exp--;
    return b * power(b, exp);
   }
}

/*
Diese Funktion soll den Sierpinski Carpet der Ordnung `n` auf die Canvas zeichnen, mit unterer linker Ecke an Koordinate `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
// Canvas repeat_shape_9_times(Canvas c, int x, int y, int shape_length){
//     sierpinski_carpet(c, )
// }

Canvas sierpinski_carpet(Canvas c, int n, int x, int y){
    // Canvas height and width
    int c_height = canvas_height(c);
    int c_width = canvas_width(c);
    
    if (n == 0){
        check_and_set_black(c, x, y, c_width, c_height);
        return c;
    }
    else{
        n--;
        int side = power(3, n);
        sierpinski_carpet(c, n, x, y); //ul
        sierpinski_carpet(c, n, x + side, y); //um
        sierpinski_carpet(c, n, x + 2 * side, y); //ur
        sierpinski_carpet(c, n, x + 2 * side, y + side); //mr
        sierpinski_carpet(c, n, x + 2 * side, y + 2 * side); //or
        sierpinski_carpet(c, n, x + side, y + 2 * side); //om
        sierpinski_carpet(c, n, x, y + 2 * side); //ol
        sierpinski_carpet(c, n, x, y + side); //ml
        return c;
    }

}

/*
Hinweis: Diese Aufgabe ist deutlich schwieriger als die vorangegangen, und ist als besondere Herausforderung gedacht :)
Eine *knifflige* Zahl ist eine Zahl deren einzige Dezimalziffern die Vier und die Sieben sind, und in der nie zwei
Siebenen aufeinander folgen.
Berechne die Anzahl der kniffligen Zahlen mit genau `n` Dezimalziffern.

Beispiel: die kniffligen Zahlen mit drei Dezimalziffern sind 444, 447, 474, 744, 747.
*/
// Return 1 if the digits only contain 4 or 7 and 0 otherwise
int check_digit(int n){
    if (n == 7 || n == 4 || n == 0) 
    {
        return 1;
    }
    else if ((n % 10 != 7 && n % 10 != 4)){
        return 0;
    }
    else{
        n /= 10;
        return check_digit(n);
    }
}


// Return 1 if there are no consecutive 7s and 0 otherwise
int check_consecutive_seven(int n){
    if ((n % 100) / 11 == 7 && (n % 100) % 11 == 0){
        return 0;
    }
    else if (n < 10)
    {
        return 1;
    }
    
    else{
        n /= 10;
        return check_consecutive_seven(n);
    }
}

int tricky_numbers(int n) {
    static int iterate = -1;
    iterate++;
    if (iterate == 0 && n == 0){
        return 1;
    }
    else if (iterate < pow(10, n - 1)){
        return tricky_numbers(n);
    }
    else if (iterate < pow(10, n)){
        if (check_digit(iterate) && check_consecutive_seven(iterate)){
            return 1 + tricky_numbers(n);
        }
        else {
            return tricky_numbers(n);
        }
    }
    else {
        return 0;
    }
}
