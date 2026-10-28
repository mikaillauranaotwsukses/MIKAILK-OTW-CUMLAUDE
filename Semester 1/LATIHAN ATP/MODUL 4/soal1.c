
#include <stdio.h>
#include <string.h>

typedef struct {
    char namaSiswa[31];
    char namaRoh[31];
    int grade;
    long long energi;
} Misi;

typedef struct {
    char namaSiswa[31];
    int jumlahMisi;
    long long totalEnergi;
    char rohTerkuat[31];
    long long energiTerkuat;
    int jumlahSpecialGrade;
} DataSiswa;

int main() {
    int n, q;
    int i, j;

    Misi misi[1005];
    DataSiswa siswa[1005];

    int jumlahSiswa = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s %s %d %lld",
              misi[i].namaSiswa,
              misi[i].namaRoh,
              &misi[i].grade,
              &misi[i].energi);

        int ditemukan = -1;

        for (j = 0; j < jumlahSiswa; j++) {
            if (strcmp(siswa[j].namaSiswa, misi[i].namaSiswa) == 0) {
                ditemukan = j;
                break;
            }
        }

        if (ditemukan == -1) {
            ditemukan = jumlahSiswa;

            strcpy(siswa[ditemukan].namaSiswa, misi[i].namaSiswa);
            siswa[ditemukan].jumlahMisi = 0;
            siswa[ditemukan].totalEnergi = 0;
            strcpy(siswa[ditemukan].rohTerkuat, misi[i].namaRoh);
            siswa[ditemukan].energiTerkuat = misi[i].energi;
            siswa[ditemukan].jumlahSpecialGrade = 0;

            jumlahSiswa++;
        }

        siswa[ditemukan].jumlahMisi++;
        siswa[ditemukan].totalEnergi += misi[i].energi;

        if (misi[i].energi > siswa[ditemukan].energiTerkuat) {
            siswa[ditemukan].energiTerkuat = misi[i].energi;
            strcpy(siswa[ditemukan].rohTerkuat, misi[i].namaRoh);
        }

        if (misi[i].grade == 0) {
            siswa[ditemukan].jumlahSpecialGrade++;
        }
    }

    scanf("%d", &q);

    char query[31];

    for (i = 0; i < q; i++) {
        scanf("%s", query);

        int ditemukan = -1;

        for (j = 0; j < jumlahSiswa; j++) {
            if (strcmp(siswa[j].namaSiswa, query) == 0) {
                ditemukan = j;
                break;
            }
        }

        printf("%s\n", query);

        if (ditemukan == -1) {
            printf("TIDAK ADA MISI\n");
        } else {
            printf("Jumlah misi: %d\n", siswa[ditemukan].jumlahMisi);
            printf("Total energi terkutuk: %lld\n", siswa[ditemukan].totalEnergi);
            printf("Roh terkuat: %s (%lld)\n",
                   siswa[ditemukan].rohTerkuat,
                   siswa[ditemukan].energiTerkuat);
            printf("Special grade dikalahkan: %d\n",
                   siswa[ditemukan].jumlahSpecialGrade);

            if (siswa[ditemukan].totalEnergi >= 500000) {
                printf("Kategori: SPECIAL GRADE SISWA\n");
            } else if (siswa[ditemukan].totalEnergi >= 100000) {
                printf("Kategori: GRADE 1 SISWA\n");
            } else if (siswa[ditemukan].totalEnergi >= 10000) {
                printf("Kategori: GRADE 2 SISWA\n");
            } else {
                printf("Kategori: GRADE 3 SISWA\n");
            }
        }
    }

    return 0;
}
