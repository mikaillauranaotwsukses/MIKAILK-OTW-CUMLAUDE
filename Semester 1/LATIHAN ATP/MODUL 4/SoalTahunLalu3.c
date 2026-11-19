#include <stdio.h>
#include <string.h>

#define SIZE 200003
#define MAXLEN 64

// Struct: satu entri di tabel hash
struct Node {
    char nama[MAXLEN];
    int dipakai;        // 1 = slot terisi
    int counter;        // angka berikutnya yang perlu dicoba untuk nama ini
};

struct Node tabel[SIZE];

// Fungsi hash untuk string
unsigned int hash(char *s) {
    unsigned int h = 0;
    while (*s) {
        h = h * 31 + (unsigned char)*s;
        s++;
    }
    return h % SIZE;
}

// Cari slot nama di tabel. Return index; *ditemukan = 1/0
int cariSlot(char *nama, int *ditemukan) {
    unsigned int idx = hash(nama);

    while (tabel[idx].dipakai) {
        if (strcmp(tabel[idx].nama, nama) == 0) {
            *ditemukan = 1;
            return idx;
        }
        idx = (idx + 1) % SIZE;
    }

    *ditemukan = 0;
    return idx;     // slot kosong
}

// Tambah nama ke tabel (dengan counter awal = 1)
void tambah(char *nama) {
    int found;
    int idx = cariSlot(nama, &found);
    strcpy(tabel[idx].nama, nama);
    tabel[idx].dipakai = 1;
    tabel[idx].counter = 1;
}

int main() {
    int n, i, found;
    char nama[MAXLEN];
    char baru[MAXLEN];

    // Inisialisasi tabel dengan pointer (bukan indeks)
    struct Node *p = tabel;
    struct Node *e = tabel + SIZE;
    while (p < e) {
        p->dipakai = 0;
        p->counter = 1;
        p++;
    }

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", nama);

        int idxAsli = cariSlot(nama, &found);

        if (!found) {
            // Nama belum ada -> daftarkan, cetak OK
            strcpy(tabel[idxAsli].nama, nama);
            tabel[idxAsli].dipakai = 1;
            tabel[idxAsli].counter = 1;
            printf("OK\n");
        } else {
            // Nama sudah ada -> pakai counter (bukan mulai dari 1 lagi)
            int k = tabel[idxAsli].counter;

            while (1) {
                snprintf(baru, MAXLEN, "%s%d", nama, k);
                int idxBaru = cariSlot(baru, &found);

                if (!found) {
                    strcpy(tabel[idxBaru].nama, baru);
                    tabel[idxBaru].dipakai = 1;
                    tabel[idxBaru].counter = 1;
                    tabel[idxAsli].counter = k + 1;   // simpan progres
                    printf("%s\n", baru);
                    break;
                }
                k++;
            }
        }
    }

    return 0;
}
