#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} node_t;

node_t * create_root (int num) {
    node_t * temp;
    temp = (node_t *) malloc (sizeof (node_t));
    temp-> data = num;
    temp-> left = temp-> right = NULL;
    return temp;
}

void insert (node_t * root, int num) {
    node_t * temp; node_t * curr = root; node_t * parent;
    temp = (node_t *) malloc (sizeof (node_t));
    temp-> data = num;
    temp-> left = temp-> right = NULL;

    while (curr! = NULL) {// find the parent of temp
        parent = curr;
        if (curr-> data> num)
            curr = curr-> left;
        else
            curr = curr-> right;
    }

    if (num <parent-> data)
        parent-> left = temp;
    else
        parent-> right = temp;
}

void inorder (node_t * ptr) {
    if (ptr! = NULL) {
        inorder (ptr-> left);
        printf ("% d", ptr-> data);
        inorder (ptr-> right);
    }
}

void postorder (node_t * ptr) {
    if (ptr! = NULL) {
        postorder (ptr-> left);
        postorder (ptr-> right);
        printf ("% d", ptr-> data);
    }
}

// By BD

int main () {
    node_t * root;
    int n;
    scanf ("% d", & n);

    int i, num;
    for (i = 0; i <n; i ++) {
        scanf ("% d", & num);
        if (i == 0)
            root = create_root (num);
        else
            insert (root, num);
    }

    inorder (root);
    printf ("\ n");
    postorder (root);

    return 0;
}
