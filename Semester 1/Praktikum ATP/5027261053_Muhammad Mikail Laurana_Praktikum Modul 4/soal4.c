#include <stdio.h>
#include <string.h>

struct Misi {
    char siswa[31];
    char roh[31];
    int grade;
    long long energi;
    int sah;            // 1 = sah, 0 = sudah dihapus
};

// pass by address: parameter berupa pointer ke struct
void revisiLog(struct Misi *log, long long energiBaru) {
    (*log).energi = energiBaru;
}

void hapusLog(struct Misi *log) {
    (*log).sah = 0;
}

void tukarLog(struct Misi *a, struct Misi *b) {
    char temp[31];
    strcpy(temp, (*a).siswa);
    strcpy((*a).siswa, (*b).siswa);
    strcpy((*b).siswa, temp);
}

int main() {
    static struct Misi logs[2000];
    int jumlah = 0;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %lld",
              logs[jumlah].siswa, logs[jumlah].roh,
              &logs[jumlah].grade, &logs[jumlah].energi);
        logs[jumlah].sah = 1;
        jumlah++;
    }

    int m;
    scanf("%d", &m);
    for (int q = 0; q < m; q++) {
        char perintah[10];
        scanf("%s", perintah);

        if (strcmp(perintah, "MISI") == 0) {
            scanf("%s %s %d %lld",
                  logs[jumlah].siswa, logs[jumlah].roh,
                  &logs[jumlah].grade, &logs[jumlah].energi);
            logs[jumlah].sah = 1;
            jumlah++;
        } else if (strcmp(perintah, "REVISI") == 0) {
            int k;
            long long e;
            scanf("%d %lld", &k, &e);
            revisiLog(&logs[k - 1], e);
        } else if (strcmp(perintah, "TUKAR") == 0) {
            int i, j;
            scanf("%d %d", &i, &j);
            tukarLog(&logs[i - 1], &logs[j - 1]);
        } else if (strcmp(perintah, "HAPUS") == 0) {
            int k;
            scanf("%d", &k);
            hapusLog(&logs[k - 1]);
        } else if (strcmp(perintah, "LAPOR") == 0) {
            char nama[31];
            scanf("%s", nama);

            int banyak = 0, special = 0, idxTerkuat = -1;
            long long total = 0;

            for (int i = 0; i < jumlah; i++) {
                if (logs[i].sah && strcmp(logs[i].siswa, nama) == 0) {
                    banyak++;
                    total += logs[i].energi;
                    if (logs[i].grade == 0) {
                        special++;
                    }
                    // '>' ketat: kalau seri, yang muncul pertama tetap menang
                    if (idxTerkuat == -1 || logs[i].energi > logs[idxTerkuat].energi) {
                        idxTerkuat = i;
                    }
                }
            }

            printf("%s\n", nama);
            if (banyak == 0) {
                printf("TIDAK ADA MISI\n");
            } else {
                printf("Jumlah misi: %d\n", banyak);
                printf("Total energi terkutuk: %lld\n", total);
                printf("Roh terkuat: %s (%lld)\n",
                       logs[idxTerkuat].roh, logs[idxTerkuat].energi);
                printf("Special grade dikalahkan: %d\n", special);

                if (total >= 500000) {
                    printf("Kategori: SPECIAL GRADE SISWA\n");
                } else if (total >= 100000) {
                    printf("Kategori: GRADE 1 SISWA\n");
                } else if (total >= 10000) {
                    printf("Kategori: GRADE 2 SISWA\n");
                } else {
                    printf("Kategori: GRADE 3 SISWA\n");
                }
            }
        }
    }

    return 0;
}