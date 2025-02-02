#ifndef TREE_H
#define TREE_H
#include <stdint.h>

/*
Ein Knoten in einem Baum von `uint16_t`s.

Wir repräsentieren Bäume durch pointer auf `TreeNode`s (der
leere Baum wird durch einen null-pointer repräsentiert).
*/
typedef struct TreeNode_ {
    uint16_t item; /* Der Wert, der in diesem Knoten gespeichert wird. */
    struct TreeNode_ *left; /* Der linke Teilbaum. */
    struct TreeNode_ *right; /* Der rechte Teilbaum. */
} TreeNode;

#endif