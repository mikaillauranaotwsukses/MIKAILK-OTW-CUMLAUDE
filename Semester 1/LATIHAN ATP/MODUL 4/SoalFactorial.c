#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Konversi angka (0-35) ke karakter: 0-9 tetap digit, 10-35 jadi A-Z
char keKarakter(int nilai) {
    if (nilai < 10) {
        return (char)('0' + nilai);
    }
    return (char)('A' + (nilai - 10));
}

// Konversi karakter ke nilai: '0'-'9' -> 0-9, 'A'-'Z' -> 10-35
int keNilai(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

// Hitung n! menggunakan malloc (array faktorial dialokasikan dinamis)
unsigned long long *buatFaktorial(int n) {
    unsigned long long *fak = (unsigned long long *) malloc((n + 1) * sizeof(unsigned long long));
    int i;
    fak[0] = 1;
    for (i = 1; i <= n; i++) {
        fak[i] = fak[i - 1] * (unsigned long long) i;
    }
    return fak;
}

// ENCODE: desimal -> notasi faktorial
void encode(unsigned long long x) {
    int maxDigit = 21;

    // Alokasi dinamis untuk faktorial dan hasil
    unsigned long long *fak = buatFaktorial(maxDigit);
    int *digit = (int *) malloc((maxDigit + 1) * sizeof(int));
    char *hasil = (char *) malloc((maxDigit + 2) * sizeof(char));

    int len = 0;
    int i;

    // Cari faktorial terbesar yang <= x (posisi paling kiri notasi)
    int pos = 0;
    for (i = 0; i <= maxDigit; i++) {
        if (fak[i] <= x) {
            pos = i;
        } else {
            break;
        }
    }

    // Bagi berulang dari faktorial terbesar ke terkecil
    for (i = pos; i >= 0; i--) {
        int d = (int)(x / fak[i]);
        x = x % fak[i];
        digit[len] = d;
        len++;
    }

    // Ubah ke karakter (0-9, A-Z)
    for (i = 0; i < len; i++) {
        hasil[i] = keKarakter(digit[i]);
    }
    hasil[len] = '\0';

    printf("%s\n", hasil);

    free(fak);
    free(digit);
    free(hasil);
}

// DECODE: notasi faktorial -> desimal
void decode(char *y) {
    int len = strlen(y);
    int i;

    // digit: paling kanan = 0!, paling kiri = (len-1)!
    unsigned long long *fak = buatFaktorial(len);

    unsigned long long total = 0;
    for (i = 0; i < len; i++) {
        // karakter ke-i dari kiri punya pangkat faktorial (len-1-i)
        int pangkat = len - 1 - i;
        int d = keNilai(y[i]);
        total += (unsigned long long) d * fak[pangkat];
    }

    printf("%llu\n", total);

    free(fak);
}

int main() {
    char mode[20];
    char buffer[100];

    scanf("%s", mode);

    if (strcmp(mode, "ENCODE") == 0) {
        unsigned long long x;
        scanf("%llu", &x);
        encode(x);
    } else if (strcmp(mode, "DECODE") == 0) {
        scanf("%s", buffer);
        decode(buffer);
    }

    return 0;
}
