#include <stdio.h>

// Fungsi rekursif untuk cek bilangan prima
int CekPrime(int Angka, int i) {
    if (Angka <= 1) {
        return 0;  // base case: 0 dan 1 bukan prima
    }
    if (i * i > Angka) {
        return 1;  // base case: tidak ada pembagi, berarti prima
    }
    if (Angka % i == 0) {
        return 0;  // base case: ketemu pembagi, bukan prima
    }
    return CekPrime(Angka, i + 1);  // recursive case: cek pembagi berikutnya
}

int main() {
    int input;

    scanf("%d", &input);
    if (CekPrime(input, 2) == 1) {  // mulai cek dari i = 2
        printf("Aman Harusnya");
    } else {
        printf("Tidak Aman");
    }

    return 0;
}
