#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    int array [100] [100];
    while (scanf ("% d", & n) == 1) {
        int i, j, k = 0;


        for (i = 0; i <n; i ++)
            for (j = 0; j <n; j ++)
                scanf ("% d", & array [i] [j]);

        if (n == 1)
            printf (" Yes! \ N ");
        else {
            for (i = 1; i <n; i ++) {
                if (array [i] [0]! = Array [0] [i]) {
                    k = 1;
                    break;
                }
            }
            if (k == 0)
                printf ("Yes! \ n");
            else
                printf ("No! \ n");
        }

    }
    return 0;
}
