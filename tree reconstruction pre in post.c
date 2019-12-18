#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node * left;
    struct node * right;
} node_t;

void tree (char preorder [100], char inorder [100], int length) {
    if (length == 0)
        return;
    node_t * node = (node_t *) malloc (sizeof (node_t));
    node-> data = preorder [0];

    int rootIndex = 0;
    for (; rootIndex <length; rootIndex ++)
        if (inorder [rootIndex] == preorder [0])
            break;

    tree (preorder + 1, inorder, rootIndex);
    tree (preorder + rootIndex + 1, inorder + rootIndex + 1, length- (rootIndex + 1));
    printf ("% c", node-> data);
    return;
}

int main () {
    char str_pre [100], str_in [100];

    while (scanf ("% s", str_pre) == 1) {
        scanf ("% s", str_in);

        int length = strlen (str_pre);
        tree (str_pre, str_in, length);
        printf ("\ n");
    }
    return 0;
}
