#include <stdio.h>

// Array nama anggota GOONERS (8 orang, berulang)
// Karena tidak boleh pakai struct (maks modul 3), pakai fungsi untuk cetak nama
void cetakNama(int cave) {
    int urutan = (cave - 1) % 8;  // cave dimulai dari 1, modulo 8 untuk urutan

    if (urutan == 0) printf("Nao");
    else if (urutan == 1) printf("Hanazonkk");
    else if (urutan == 2) printf("Zynch");
    else if (urutan == 3) printf("ChikenCip");
    else if (urutan == 4) printf("Zaro");
    else if (urutan == 5) printf("Nanno");
    else if (urutan == 6) printf("Ftx");
    else if (urutan == 7) printf("Kokee");
}

// Fungsi penjelajahan cave (wajib pakai fungsi sesuai soal)
// Mengembalikan total diamond yang ditemukan
int jelajahiCave(int d[], int n) {
    int total = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (d[i] > 0) {
            cetakNama(i + 1);  // i+1 karena cave dimulai dari 1
            printf(" menemukan %d jumlah diamond di cave ke-%d\n", d[i], i + 1);
            total += d[i];
        }
    }

    return total;
}

int main() {
    int n, i;
    int d[10000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    int total = jelajahiCave(d, n);

    if (total > 0) {
        printf("DIAMOND! DIAMOND! DIAMOND! DIAMOND!\n");
        printf("Total jumlah diamond yang didapat: %d\n", total);

        if (total >= 1 && total <= 64) {
            printf("Ftx sama Zynch wajib traktir GOONERS lain\n");
        } else if (total >= 65 && total <= 128) {
            printf("GOONERS tidur besok nguli lagi\n");
        } else if (total >= 129 && total <= 192) {
            printf("Para GOONERS makan-makan hari ini\n");
        }
    } else {
        printf("That's La Peace\n");
        printf("Sayang sekali Tim GOONERS pulang dengan tangan kosong\n");
    }

    return 0;
}
