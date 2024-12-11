/*
Zur Abgabe einen branch `iprg-b05` erstellen und pushen, in dem als einzige Datei die `05ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 05ex_test.c -o 05ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./05ex_test.o
*/

#include "search_tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Die Definition von Bäumen bzw. Knoten finden Sie in `./search_tree.h`
*/

/*
Aufgabe 1:

Ändern Sie alle im Baum `t` gespeicherten Werte auf `x`.
*/
void search_tree_boringify(TreeNode *t, uint16_t x) {
    if(t != NULL){
        t->item = x;
        if(t->left != NULL){
            search_tree_boringify(t->left, x);
        }
        if(t->right != NULL){
            search_tree_boringify(t->right, x);
        }
    }
}

/*
Aufgabe 2:
Geben Sie die größte Zahl im Suchbaum `t` zurück, welche echt kleiner als `x` ist.
Falls keine solche Zahl existiert, geben Sie stattdessen `x` zurück. Die Laufzeit Ihrer Lösung soll
proportional zur Höhe des Baumes sein, aber unabhängig von der Gesamtzahl an Knoten. 
*/
void check_tree(TreeNode *tree_to_check, uint16_t x, int *max_lt_x_ptr){
    // Check if tree/branch exists
    if(tree_to_check == NULL){
        return;
    }
    // The following block moves the ptr around the tree
    else if(tree_to_check->item >= x){
        // Ptr goes left if item is \leq x
        if(tree_to_check->left){
            tree_to_check = tree_to_check->left;
            return check_tree(tree_to_check, x, max_lt_x_ptr);
        }
    }
    else{
        // Ptr goes right if item is < x and item is saved to max
        *max_lt_x_ptr = tree_to_check->item;
        if(tree_to_check->right){
            tree_to_check = tree_to_check->right;
            check_tree(tree_to_check, x, max_lt_x_ptr);
        }
    }
}

uint16_t search_tree_get_less_than(TreeNode *t, uint16_t x) {
    // Check if t exists
    if(t == NULL){
        return x;
    }

    // Creates ptr for return value to be called in recursive func and set default return value to x
    int *max_lt_x_ptr = malloc(sizeof(int));
    *max_lt_x_ptr = x;
    
    check_tree(t, x, max_lt_x_ptr);
    
    // Get value from ptr and free ptr
    int return_val = *max_lt_x_ptr;
    free(max_lt_x_ptr);

    return return_val;
}