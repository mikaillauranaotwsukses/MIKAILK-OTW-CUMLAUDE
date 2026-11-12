#include <stdio.h>
#include <string.h>

// Deklarasi struct untuk menyimpan data nilai UN mahasiswa
struct Mahasiswa {
    char nama[100];
    int matematika;
    int ipa;
    int bahasaIndonesia;
    int bahasaInggris;
};

int main() {
    int n, q, i, j;
    struct Mahasiswa mhs[100];   // array of struct
    char cari[100];
    int ketemu;

    // Input jumlah data
    scanf("%d", &n);

    // Input data tiap mahasiswa
    // Urutan: nama, Matematika, IPA, Bahasa Indonesia, Bahasa Inggris
    for (i = 0; i < n; i++) {
        scanf("%s", mhs[i].nama);
        scanf("%d", &mhs[i].matematika);
        scanf("%d", &mhs[i].ipa);
        scanf("%d", &mhs[i].bahasaIndonesia);
        scanf("%d", &mhs[i].bahasaInggris);
    }

    // Input jumlah nama yang akan dicari
    scanf("%d", &q);

    // Proses pencarian data berdasarkan nama
    for (i = 0; i < q; i++) {
        scanf("%s", cari);

        ketemu = 0;
        for (j = 0; j < n; j++) {
            if (strcmp(mhs[j].nama, cari) == 0) {
                printf("Nilai %s\n", mhs[j].nama);
                printf("Matematika : %d\n", mhs[j].matematika);
                printf("IPA : %d\n", mhs[j].ipa);
                printf("Bahasa Indonesia : %d\n", mhs[j].bahasaIndonesia);
                printf("Bahasa Inggris : %d\n", mhs[j].bahasaInggris);
                ketemu = 1;
                break;
            }
        }

        if (ketemu == 0) {
            printf("Nilai %s tidak ditemukan\n", cari);
        }
    }

    return 0;
}
