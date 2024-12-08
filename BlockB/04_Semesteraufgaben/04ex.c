/*
Zur Abgabe einen branch `iprg-b04` erstellen und pushen, in dem als einzige Datei die `04ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 04ex_test.c -o 04ex_test.o -lm && ./04ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 04ex_test.c -o 04ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./04ex_test.o
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
In dieser Aufgabe arbeiten wir an doppelt verketteten Listen.

Das folgende Struct ist ein Node in einer doppelt verketteten Liste.
Dieses Struct dient als Implementierungsdetail.
Wer von außen mit einer DoublyLinkedList arbeitet,
bekommt Nodes nie direkt zu sehen.
*/
typedef struct Node {
    /* Der Datenwert, der in der Node gespeichert ist. */
    int data;
    /* Pointer auf die vorige Node, oder NULL, falls es keine vorige Node gibt. */
    struct Node *prev;
    /* Pointer auf die nächste Node, oder NULL, falls es keine vorige Node gibt. */
    struct Node *next;
} Node;

/* Eine doppelt verkettete Liste. */
typedef struct {
    /* Pointer auf die erste Node der Liste. */
    Node *head;
    /* Pointer auf die letzte Node der Liste. */
    Node *tail;
    /* Anzahl der Nodes in der Liste. */
    size_t size;
} DoublyLinkedList;

/*
Aufgabe 1: Suche

Implementieren Sie die Funktion `find_node`, die den ersten Knoten in der Liste findet,
wo `data` gleich x ist. Falls kein solcher Knoten existiert, geben Sie NULL zurück.
*/
Node *find_node(DoublyLinkedList *list, int x) {
    Node *node_ptr = list->head;
    size_t size_list = list->size;
    for(int i = 0; i < size_list; i++)
    {
        if(node_ptr->data == x)
        {
            return node_ptr;
        }
        node_ptr = node_ptr->next;
    }
    return NULL;
}

/*
Aufgabe 2: Löschen

Implementieren Sie die Funktion `remove_node`, die den ersten Knoten in der Liste löscht,
wo `data` gleich x ist. Achten Sie darauf, die Verbindungen zwischen den Knoten korrekt anzupassen
und den Speicher des entfernten Knotens freizugeben. Aktualisieren Sie auch die Größe der Liste.
Geben Sie zurück, ob ein Knoten erfolgreich entfernt wurde.
*/
bool remove_node(DoublyLinkedList *list, int x) {
    Node *node_ptr = find_node(list, x);
    if(node_ptr == NULL)
    {
        return false;
    }
    else
    {
        if(list->size == 1)
        {
            list->head = NULL;
            list->tail = NULL;
        }
        else if(node_ptr->prev == NULL)
        {
            list->head = node_ptr->next;
            node_ptr->next->prev = NULL;
        }
        else if(node_ptr->next == NULL)
        {
            list->tail = node_ptr->prev;
            node_ptr->prev->next = NULL;
        }
        else
        {
            node_ptr->prev->next = node_ptr->next;
            node_ptr->next->prev = node_ptr->prev;
        }
        free(node_ptr);
        list->size--;
        return true;
    }
}

/*
Aufgabe 3: Löschen aller Vorkommen

Implementieren Sie die Funktion `remove_all`, die alle Vorkommen eines bestimmten Elements x
aus der Liste entfernt. Geben Sie zurück, wie viele Knoten entfernt wurden.

Hinweis: Verwenden Sie dabei die Funktionen `find_node` und `remove_node`.
*/
int remove_all(DoublyLinkedList *list, int x) {
    int count = 0;
    while(find_node(list, x))
    {
        remove_node(list, x);
        count++;
    }
    return count;
}
