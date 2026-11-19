#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mencariGCD(int a, int b) {
    while (b != 0) {
        int sisa = a % b;
        a = b;
        b = sisa;
    }

    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    int gcd;
    int angka;

    for (int i = 0; i < n; i++) {
        scanf("%d", &angka);

        if (i == 0) {
            gcd = angka;
        } else {
            gcd = mencariGCD(gcd, angka);
        }
    }

    if (gcd > 1) {
        printf("1\n");
        printf("%d 1\n", gcd);
    } else {
        printf("2\n");
        printf("1000000000 500000000\n");
        printf("2 1\n");
    }

    return 0;
}
