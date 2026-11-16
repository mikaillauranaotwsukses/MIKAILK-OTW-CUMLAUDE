
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *tinggi = malloc(n * sizeof(int));
    int *offset = malloc((n + 1) * sizeof(int));

    size_t totalBalok = 0;

    offset[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &tinggi[i]);

        totalBalok += tinggi[i];
        offset[i + 1] = totalBalok;
    }

    
    int *jarak = malloc(totalBalok * sizeof(int));

    
    size_t *antrian = malloc(totalBalok * sizeof(size_t));

    for (size_t i = 0; i < totalBalok; i++) {
        jarak[i] = -1;
    }

    size_t depan = 0;
    size_t belakang = 0;

    
    for (int kolom = 0; kolom < n; kolom++) {
        for (int baris = 0; baris < tinggi[kolom]; baris++) {

            int terbukaKiri = (kolom == 0 || baris >= tinggi[kolom - 1]);
            int terbukaKanan = (kolom == n - 1 || baris >= tinggi[kolom + 1]);
            int terbukaAtas = (baris == tinggi[kolom] - 1);

            if (terbukaKiri || terbukaKanan || terbukaAtas) {
                size_t posisi = offset[kolom] + baris;

                jarak[posisi] = 0;
                antrian[belakang++] = posisi;
            }
        }
    }

    int jarakMaksimum = 0;

    
    while (depan < belakang) {
        size_t posisi = antrian[depan++];

        
        int kiri = 0;
        int kanan = n;

        while (kiri < kanan) {
            int tengah = (kiri + kanan) / 2;

            if (offset[tengah + 1] <= posisi) {
                kiri = tengah + 1;
            } else {
                kanan = tengah;
            }
        }

        int kolom = kiri;
        int baris = posisi - offset[kolom];

        
        if (baris + 1 < tinggi[kolom]) {
            size_t tujuan = posisi + 1;

            if (jarak[tujuan] == -1) {
                jarak[tujuan] = jarak[posisi] + 1;
                antrian[belakang++] = tujuan;
            }
        }

        
        if (baris > 0) {
            size_t tujuan = posisi - 1;

            if (jarak[tujuan] == -1) {
                jarak[tujuan] = jarak[posisi] + 1;
                antrian[belakang++] = tujuan;
            }
        }

        
        if (kolom > 0 && baris < tinggi[kolom - 1]) {
            size_t tujuan = offset[kolom - 1] + baris;

            if (jarak[tujuan] == -1) {
                jarak[tujuan] = jarak[posisi] + 1;
                antrian[belakang++] = tujuan;
            }
        }

        
        if (kolom + 1 < n && baris < tinggi[kolom + 1]) {
            size_t tujuan = offset[kolom + 1] + baris;

            if (jarak[tujuan] == -1) {
                jarak[tujuan] = jarak[posisi] + 1;
                antrian[belakang++] = tujuan;
            }
        }

        if (jarak[posisi] > jarakMaksimum) {
            jarakMaksimum = jarak[posisi];
        }
    }

    printf("%d\n", jarakMaksimum + 1);

    free(tinggi);
    free(offset);
    free(jarak);
    free(antrian);

    return 0;
}
