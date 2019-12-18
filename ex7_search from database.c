#include <stdio.h>
#include <string.h>

 struct student {
    char num [1000];
    char name [1000];
    char gender [4];
    int age;
} student [1000];

// By BD

int main () {
    int n;
    while (scanf ("% d", & n) == 1) {
        int i;
        for (i = 0; i <n; i ++)
            scanf ("% s% s% s% d ", student [i] .num, student [i] .name,
student [i] .gender, & student [i] .age);

        int m;
        char search [10000];
        scanf ("% d", & m);

        int j;
        for (i = 0; i <m; i ++) {
            scanf ("% s", search);

            for (j = 0; j <n; j ++) {
                if (strcmp (search, student [j] .num) == 0) {
                    printf ("% s% s% s% d \ n", student [j] .num, student
[j] .name, student [j] .gender, student [j] .age); j--
                    ;
                    break;
                }
            }
            if (j == n)
                printf ("No Answer! \ n") ;

        }
    }
    return 0;
}
