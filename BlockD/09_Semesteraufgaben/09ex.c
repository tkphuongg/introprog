/*
Zur Abgabe einen branch `iprg-b09` erstellen und pushen, in dem als einzige Datei die `09ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 09ex_test.c -o 09ex_test.o -lm && ./09ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 09ex_test.c -o 09ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./09ex_test.o
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tree.h"
#include "array.h"

/*
Aufgabe 1:

Gegeben ein linksvollständiger Binärbaum `t`, geben Sie zurück, ob `t` die min-heap Eigenschaft erfüllt.
*/
bool is_min_heap(TreeNode *t) 
{
    if(t == NULL)
    {
        return true;
    }
    else
    {
        if(t->left == NULL && t->right == NULL)
        {
            return true;
        }
        else if(t->left != NULL)
        {
            if(t->item > t->left->item){
                return false;
            }
            else
            {
                return is_min_heap(t->left);
            }
        }
        else
        {
            if (t->item > t->right->item)
            {
                return false;
            }
            else
            {
                return is_min_heap(t->right);
            }
        }
    }
}

/*
Aufgabe 2:

Gegeben ein Array `arr`, geben Sie den zugehörigen linksvollständigen Binärbaum zurück.
*/
void make_node_and_child(Array arr, int arr_len, int i, TreeNode *t){
    if(i >= arr_len){
        return;
    }
    else{
        t->item = arr.arr[i];

        if(2*i + 1 >= arr_len){
            t->left =  NULL;
        }
        else{
            t->left = malloc(sizeof(TreeNode));
            make_node_and_child(arr, arr_len, (2*i + 1), t->left);
        }
        if(2*i + 2 >= arr_len){
            t->right =  NULL;
        }
        else{
            t->right = malloc(sizeof(TreeNode));
            make_node_and_child(arr, arr_len, (2*i + 2), t->right);
        }
    }
}

TreeNode *array_to_tree(Array arr) {
    TreeNode *t = malloc(sizeof(TreeNode));
    int arr_len = arr.len;
    if(arr_len <= 0){
        free(t);
        return NULL;
    }
    make_node_and_child(arr, arr_len, 0, t);
    return t;
}
