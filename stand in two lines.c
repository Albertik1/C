#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node * next;
} customer;

typedef struct queue {
    customer * front;
    customer * rear;
} window;

void enqueue (window * q, int n) {
    customer * new_node = (customer *) malloc (sizeof (customer));
    new_node-> num = n;
    new_node-> next = NULL;

    if (q-> front == NULL) {
        q-> front = new_node;
        q-> rear = new_node;
    }
    else {
        q-> rear-> next = new_node;
        q-> rear = new_node;
    }
}

void print_dequeue (window * q) {
    int i;
    printf ("% d", q-> front-> num);
    q-> front = q-> front-> next;
}

int isEmpty (window * q) {
    if (q-> front == NULL)
        return 1;
    return 0;
}

// By BD

int main () {
    int n; int i; window * A; window * B; int id; int count;
    A = (customer *) malloc (sizeof (customer));
    B = (customer *) malloc (sizeof (customer ));
    while (scanf ("% d", & n) == 1) {
        A-> front = NULL; B-> front = NULL;
        A-> rear = NULL; B-> rear = NULL;
        for (i = 0; i <n; i ++) {
            scanf ("% d", & id);
            if (id% 2! = 0)
                enqueue (A, id);
            else
                enqueue (B, id);
        }
        count = 0;

        while (count! = n) {
            if (isEmpty (A)! = 1) {
                print_dequeue (A);
                count ++;
                if (count! = n)
                    printf ("");
            }
            if (isEmpty (A)! = 1) {
                print_dequeue (A);
                count ++;
                if (count! = n)
                    printf ("");
            }
            if (isEmpty (B)! = 1) {
                print_dequeue (B);
                count ++;
                if (count! = n)
                    printf (" ");
            }
        }
        printf (" \ n ");
    }
    return 0;
}
