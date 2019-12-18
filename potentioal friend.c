#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, j, m, n, count;
    int people [10000];

    while (scanf ("% d", & n) == 1) {
        for (i = 0; i <n; i ++)
            scanf ("% d", & people [i]);

        for (i = 0; i <n; i ++) {
            for (j = count = 0; j <n; j ++)
                if ( j ! = i && people [j] == people [i])
                    count ++;

            if (count> 0)
                printf ("% d \ n", count);
            else
                printf ("So sad \ n");
        }
    }
    return 0;
}
