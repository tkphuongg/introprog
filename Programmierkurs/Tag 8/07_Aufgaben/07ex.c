/*
Willkommen zum siebten Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Pointer.
Dieses Blatt ist vergleichsweise lang. Die Erfahrung hat gezeigt, dass Studierende insgesamt
weniger Zeit in IntroProg investieren müssen, wenn Sie sich anfangs gründlich mit Pointern beschäftigt haben.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 07ex_test.c -o 07ex_test.o -lm && ./07ex_test.o
*/

#include "07ex_header.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
Aufgabe 1a:
`x` zeigt auf einen 32-bit Integer. Geben Sie diesen Integer zurück.
*/
int32_t retrieve_from_pointer(int32_t *x) {
    return *x;
}

/*
Aufgabe 1b:
`x` zeigt auf einen 32-bit Integer. Setzen Sie diesen Integer auf 42.
*/
void set_through_pointer1(int32_t *x) {
    *x = 42;
    return;
}

/*
Aufgabe 1c:
`x` zeigt auf einen 32-bit Integer. `y` _ist_ ein 32-bit Integer. Setzen Sie den Wert, auf den `x` zeigt, auf den
Wert von `y`.
*/
void set_through_pointer2(int32_t *x, int32_t y) {
    *x = y;
    return;
}

/*
Aufgabe 1d:
`x` und `y` zeigen beide auf 32-bit Integer. Setzem Sie den Wert auf den `x` zeigt auf den Wert auf den `y` zeigt.
Lassen Sie den Wert auf den `y` zeigt dabei unverändert.
*/
void set_through_pointer3(int32_t *x, int32_t *y) {
    *x = *y;
    return;
}

/*
Aufgabe 1e:
`x` und `y` zeigen beide auf 32-bit Integer. Vertauschen Sie den Wert auf den `x` zeigt und den Wert auf den `y` zeigt.
*/
void swap(int32_t *x, int32_t *y) {
    int32_t value_at_x = *x;
    *x = *y;
    *y = value_at_x;
    return;
}

/*
Aufgabe 1f:
`x` und `y` zeigen beide auf 32-bit Integer. Geben Sie zurück, ob `x` und `y` auf den _gleichen_ (Englisch: _equal_)
Wert zeigen (d.h. die Folgen von Einsen und Nullen an den beiden Speicherpositionen sind identisch).
*/
bool point_to_equal_values(int32_t *x, int32_t *y) {
    return *x == *y;
}

/*
Aufgabe 1g:
`x` und `y` zeigen beide auf 32-bit Integer. Geben Sie zurück, ob `x` und `y` auf den _selben_ (Englisch: _same_)
Wert zeigen (d.h. die Speicherpositionen sind identisch).
*/
bool point_to_same_values(int32_t *x, int32_t *y) {
    return x == y;
}

/*
Dieses Struct kennen Sie schon (vom fünften Aufgabenblatt).
*/
typedef struct RGB_ {
    float r; /* Rotkomponente */
    float g; /* Grünkomponente */
    float b; /* Blaukomponente */
} RGB;

/*
Aufgabe 2a:
`x` zeigt auf eine Farbe. Geben Sie diese Farbe zurück.
*/
RGB retrieve_from_pointer_struct(RGB *x) {
    RGB color = {.r = x->r, .g = x->g, .b = x->b};
    return color;
}

/*
Aufgabe 2b:
`x` zeigt auf eine Farbe. Setzen Sie diese Farbe auf `Flieder` (rot 0.86, grün 0.82, blau 1.0).
*/
void set_through_pointer_struct1(RGB *x) {
    x->r = 0.86;
    x->g = 0.82;
    x->b = 1.0;
    return;
}

/*
Aufgabe 2c:
`x` zeigt auf eine Farbe. `y` _ist_ eine Farbe. Setzen Sie den Wert auf den `x` zeigt auf den Wert von `y`.
*/
void set_through_pointer_struct2(RGB *x, RGB y) {
    *x = y;
    return;
}

/*
Aufgabe 2d:
`x` und `y` zeigen beide auf Farben. Setzen Sie den Wert auf den `x` zeigt auf den Wert auf den `y` zeigt.
Lassen Sie den Wert auf den `y` zeigt dabei unverändert.
*/
void set_through_pointer_struct3(RGB *x, RGB *y) {
    *x = *y;
    return;
}

/*
Aufgabe 2e:
`x` und `y` zeigen beide auf Farben. Vertauschen Sie den Wert auf den `x` zeigt und den Wert auf den `y` zeigt.
*/
void swap_struct(RGB *x, RGB *y) {
    RGB color_at_x = *x;
    *x = *y;
    *y = color_at_x;
    return;
}

/*
Aufgabe 2f:
`x` und `y` zeigen beide auf Farben. Geben Sie zurück, ob `x` und `y` auf den _gleichen_ (Englisch: _equal_)
Wert zeigen (d.h. die Folgen von Einsen und Nullen an den beiden Speicherpositionen sind identisch).
*/
bool point_to_equal_values_struct(RGB *x, RGB *y) {
    return x->r == y->r && x->g == y->g && x->b == x->b;
}

/*
Aufgabe 2g:
`x` und `y` zeigen beide auf Farben. Geben Sie zurück, ob `x` und `y` auf den _selben_ (Englisch: _same_)
Wert zeigen (d.h. die Speicherpositionen sind identisch).
*/
bool point_to_same_values_struct(RGB *x, RGB *y) {
    return x == y;
}

/*
Aufgabe 3a:
`x` zeigt auf eine Farbe. Geben Sie ihre Blaukomponente zurück.
*/
float retrieve_from_pointer_field(RGB *x) {
    return x->b;
}

/*
Aufgabe 3b:
`x` zeigt auf eine Farbe. Setzen Sie ihre Blaukomponente auf 0.
*/
void set_through_pointer_field1(RGB *x) {
    x->b = 0;
    return;
}

/*
Aufgabe 3c:
`x` zeigt auf eine Farbe. `y` _ist_ eine Farbe. Setzen Sie den Wert der Blaukomponente der Farbe auf die `x` zeigt auf
den Wert der Blaukomponente von `y`.
*/
void set_through_pointer_field2(RGB *x, RGB y) {
    x->b = y.b;
    return;
}

/*
Aufgabe 3d:
`x` und `y` zeigen beide auf Farben. Setzen Sie den Wert der Blaukomponente der Farbe auf die `x` zeigt auf den Wert der
Blaukomponente der Farbe auf die `y` zeigt.
Lassen Sie den Wert auf den `y` zeigt dabei unverändert.
*/
void set_through_pointer_field3(RGB *x, RGB *y) {
    x->b = y->b;
    return;
}

/*
Aufgabe 3e:
`x` und `y` zeigen beide auf Farben. Vertauschen Sie den Wert der Blaukomponente der Farbe, auf die `x` zeigt
und den Wert der Blaukomponente der Farbe, auf die `y` zeigt.
*/
void swap_field(RGB *x, RGB *y) {
    float blue_at_x = x->b;
    x->b = y->b;
    y->b = blue_at_x;
    return;
}

/*
Aufgabe 3f:
`x` und `y` zeigen beide auf Farben. Geben Sie zurück, ob `x` und `y` auf Farben mit _gleicher_ (Englisch: _equal_)
Blaukomponente zeigen (d.h. die Folgen von Einsen und Nullen an den beiden Speicherpositionen sind identisch).
*/
bool point_to_equal_values_field(RGB *x, RGB *y) {
    return x->b == y->b;
}

/*
Aufgabe 3g:
`x` und `y` zeigen beide auf Farben. Geben Sie zurück, ob `x` und `y` auf Farben mit der _selben_ (Englisch: _same_)
Blaukomponente zeigen (d.h. die Speicherpositionen sind identisch).
*/
bool point_to_same_values_field(RGB *x, RGB *y) {
    return x==y;
}


/*
Aufgabe 4:
Die `07ex_header.h` Datei enthält ein paar sehr komplexe Funktionen um _fizzledipps_, _flabbles_,
und _frumples_ zu berechnen.

Berechnen Sie den _flabble_ von `x` und dem _fizzledipp_ von `x`. Berechnen Sie den _frumple_ von dieser Zahl und 27,
und geben Sie diesen Wert zurück. Oder als Term ausgedrückt: frumple(flabble(x, fizzledipp(x)), 27).
Hinweis: flabble soll als _zweites_ Argument das Ergebnis von fizzledipp erhalten, und frumple ebenfalls als _zweites_
Argument die 27. `x` und der fizzledipp von `x` sind unterschiedliche Zahlen!
*/
int32_t frumpleflabblefizzledipp(int32_t x) {
    // Variable x_init to hold original x value
    int32_t x_init = x;

    // Result of fizzledipp(x) is saved into x, replacing original x
    fizzledipp(&x);

    // Variable twenty_seven holding 27 as value, giving pointer to func frumple
    int32_t twenty_seven = 27;
    
    // Variable return_val to hold result of frumple
    int32_t return_val;
    frumple(flabble(&x_init, &x), &twenty_seven, &return_val);

    return return_val;
}


/*
Pancakes? Pancakes!
Ein ordentlicher Pfannkuchenhaufen hat mehrere Schichten, und zwar aus Obst, Schlagsahne, oder tatsächlichem Teigfladen.
*/
typedef enum Layer_ { Fruit, Cream, ActualPancake } Layer;

/*
Ein Pfannkuchenhaufen besteht aus einer Schicht, auf der möglicherweise ein weiterer Pfannkuchenhaufen liegt:
*/
typedef struct PileOfPancakes_ PileOfPancakes;
struct PileOfPancakes_ {
    Layer layer; /* Die unterste Schicht. */ 
    PileOfPancakes *further_layers; /* Weitere Schichten, oder `null` falls keine mehr folgen. */
};

/*
Aufgabe 5a:
Geben sie zurück, ob die _erste_ Schicht des gegebenen Pfannkuchenhaufens eine Fruchtschicht ist.
*/
bool starts_with_fruit(PileOfPancakes p) {
    return p.layer == Fruit;
}

/*
Aufgabe 5b:
Geben sie zurück, ob die _letzte_ Schicht des gegebenen Pfannkuchenhaufens eine Fruchtschicht ist.
*/
bool ends_with_fruit(PileOfPancakes p) {
    if (p.further_layers == NULL)
    {
        return p.layer == Fruit;
    }
    else 
    {
        return ends_with_fruit(*(p.further_layers));
    }
}

/*
Aufgabe 5c:
Geben Sie zurück, _wie viele_ Fruchtschichten der gegebene Pfannkuchenhaufen enthält.
*/
int32_t count_fruit_layers(PileOfPancakes p) {
    if (p.further_layers == NULL && starts_with_fruit(p))
    {
        return 1;
    }
    else if (p.further_layers == NULL)
    {
        return 0;
    }
    else if (starts_with_fruit(p))
    {
        return 1 + count_fruit_layers(*(p.further_layers));
    }
    else 
    {
        return count_fruit_layers(*(p.further_layers));
    }
}
