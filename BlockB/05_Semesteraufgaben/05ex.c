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
int check_tree(TreeNode *tree_to_check, uint16_t x, uint16_t *max_lt_x){
    if(tree_to_check == NULL){
        return 0;
    }
    else if(tree_to_check->item >= x){
        if(tree_to_check->left){
            tree_to_check = tree_to_check->left;
            return 1;
        }
        return 0;
    }
    else{
        if(tree_to_check->right){
            tree_to_check = tree_to_check->right;
            return 1;
        }
        return 0;
    }
}

void save_item_if_lt_x(TreeNode *current_node, uint16_t x, uint16_t* max_lt_x){
    if(current_node->item < x && current_node != NULL){
        *max_lt_x = current_node->item;
    }
}

uint16_t search_tree_get_less_than(TreeNode *t, uint16_t x) {
    uint16_t *max_lt_x = NULL;
    *max_lt_x = x;
    if(t == NULL){
        return x;
    }
    TreeNode *current_node = t;
    while(check_tree(current_node, x, max_lt_x)){
        save_item_if_lt_x(current_node, x, max_lt_x);
    }
    return *max_lt_x;
}
