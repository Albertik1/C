#include <stdio.h>
int count;
void move (char a, int n, char b) {
    printf ("% 2d. Move disk% d from% c to% c \ n", count, n, a, b );
    count ++;
}

void hanoi (int n, char x, char y, char z) {
    if (n == 1) {
        move (x, 1, z);
    }
    else {
        hanoi (n-1, x, z, y);
        move (x, n, z);
        hanoi (n-1, y, x, z);
    }
}

void count_reset () {
    count = 1;
}

// By BD

int main () {
    int n;
    while (scanf ("% d", & n) == 1) {
        if (n! = 0) {
            count_reset ();
            hanoi (n, 'X', 'Y', 'Z ');
        }
        printf ("\ n");
    }
    return 0;
}
