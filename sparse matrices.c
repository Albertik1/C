#include <stdio.h>
#include <stdlib.h>
typedef struct SparseMartix {
    int i;
    int j;
    int e;
} triple;
// make a struct to save the sparse matrix

typedef struct TSMatrix_with_tripple {
    triple data [12500];
    int mu; // row
    int nu; // column
    int tu; // non-zero elements
} TSMatrix;
// set a tripple table to save the amount of row, column, and the non-zero elements of the matrix

void TransposeSMatrix (TSMatrix M, TSMatrix * T) {
    int p, q = 0, col;
    T-> mu = M.nu;
    T-> nu = M.mu;
    T-> tu = M.tu;

        for (col = 0; col <M.tu; ++ col)
            for (p = 0; p <M.tu; ++ p)
                if (M.data [p] .j == col) {
                    T-> data [q] .i = M.data [p] .j;
                    T-> data [q] .j = M.data [p] .i;
                    T-> data [q] .e = M.data [p ] .e;
                    ++ q;
                }
}

// By BD

int main () {
    int r, c, n;
    TSMatrix SM, T;

    while (scanf ("% d", & r) == 1) {
        scanf ("% d", & c);

        SM.mu = r;
        SM.nu = c;

        int count = 0, i, j;
        for (i = 0; i <r; i ++) {
            for (j = 0; j <c; j ++) {
                scanf ("% d", & n);
                if (n! = 0) {
                    SM.data [count] .i = i;
                    SM.data [count]
                    .j = j; SM.data [count] .e = n;
                    count ++;
                }

            }
        }

        SM.tu = count;
        TransposeSMatrix (SM, & T);

        int curr = 0;

        for (i = 0; i <T.mu; i ++) {
            for (j = 0; j <T.nu; j ++) {
                if (i == T.data [curr] .i && j == T.data [curr] .j) {
                    printf ("% d", T.data [curr] .e);
                    curr ++;
                }
                else
                    printf ("0");

            }
            printf ("\ n");
        }
    }
    return 0;
}
