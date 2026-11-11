
#include <stdio.h>
#include <string.h>

struct Peserta {
    char nama[50];
    int totalNilai;
};

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    struct Peserta peserta[100];

    int jumlahPeserta = 0;

    for (int i = 0; i < n; i++) {
        char namaInput[50];
        char soal;
        int score;

        scanf("%49s %c %d", namaInput, &soal, &score);

        int ditemukan = -1;

        for (int j = 0; j < jumlahPeserta; j++) {
            if (strcmp(peserta[j].nama, namaInput) == 0) {
                ditemukan = j;
                break;
            }
        }

        if (ditemukan == -1) {
            strcpy(peserta[jumlahPeserta].nama, namaInput);
            peserta[jumlahPeserta].totalNilai = score;
            jumlahPeserta++;
        } else {
            peserta[ditemukan].totalNilai += score;
        }
    }

    int nilaiTertinggi = 0;

    for (int i = 0; i < jumlahPeserta; i++) {
        if (peserta[i].totalNilai > nilaiTertinggi) {
            nilaiTertinggi = peserta[i].totalNilai;
        }
    }

    if (m >= nilaiTertinggi) {
        printf("YES MENANG\n");
    } else {
        printf("NICE TRY\n");
    }

    return 0;
}
