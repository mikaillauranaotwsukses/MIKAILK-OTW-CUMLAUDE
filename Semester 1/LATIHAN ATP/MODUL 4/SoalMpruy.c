#include <stdio.h>
#include <string.h>

#define MAX_GUDANG 5
#define MAX_JENIS 100

// Struct untuk satu jenis barang
struct Barang {
    char nama[50];
    int jumlah;
};

// Struct untuk satu gudang
struct Gudang {
    char nama[50];
    int terpakai;               // 1 = gudang ini ada
    int jumlahJenis;            // banyak jenis barang
    int total;                  // total semua kuantitas
    struct Barang barang[MAX_JENIS];
};

struct Gudang gudang[MAX_GUDANG];

// Cari index gudang berdasarkan nama. Return -1 jika tidak ada
int cariGudang(char *nama) {
    int i;
    for (i = 0; i < MAX_GUDANG; i++) {
        if (gudang[i].terpakai && strcmp(gudang[i].nama, nama) == 0) {
            return i;
        }
    }
    return -1;
}

// Cari index barang dalam gudang. Return -1 jika tidak ada
int cariBarang(struct Gudang *g, char *nama) {
    int i;
    for (i = 0; i < g->jumlahJenis; i++) {
        if (strcmp(g->barang[i].nama, nama) == 0) {
            return i;
        }
    }
    return -1;
}

// TAMBAH_GUDANG
void tambahGudang(char *nama) {
    int i;
    // Kalau sudah ada, tidak ditambah lagi (dianggap sukses)
    if (cariGudang(nama) != -1) {
        return;
    }
    // Cari slot kosong
    for (i = 0; i < MAX_GUDANG; i++) {
        if (!gudang[i].terpakai) {
            strcpy(gudang[i].nama, nama);
            gudang[i].terpakai = 1;
            gudang[i].jumlahJenis = 0;
            gudang[i].total = 0;
            return;
        }
    }
    // Kapasitas gudang penuh
    printf("ERROR!\n");
}

// TAMBAH_BARANG
void tambahBarang(char *namaGudang, char *namaBarang, int jumlah) {
    int gi = cariGudang(namaGudang);
    if (gi == -1) {
        printf("ERROR!\n");
        return;
    }

    struct Gudang *g = gudang + gi;

    // Cek kuota gudang (maks 100)
    if (g->total + jumlah > MAX_JENIS) {
        printf("ERROR!\n");
        return;
    }

    int bi = cariBarang(g, namaBarang);

    if (bi == -1) {
        // Barang baru
        if (g->jumlahJenis >= MAX_JENIS) {
            printf("ERROR!\n");
            return;
        }
        bi = g->jumlahJenis;
        strcpy(g->barang[bi].nama, namaBarang);
        g->barang[bi].jumlah = 0;
        g->jumlahJenis++;
    }

    g->barang[bi].jumlah += jumlah;
    g->total += jumlah;
}

// PINDAH_BARANG
void pindahBarang(char *dari, char *ke, char *namaBarang, int jumlah) {
    int giAsal = cariGudang(dari);
    int giTujuan = cariGudang(ke);

    // Gudang asal/tujuan tidak ada
    if (giAsal == -1 || giTujuan == -1) {
        printf("ERROR!\n");
        return;
    }

    struct Gudang *gAsal = gudang + giAsal;
    struct Gudang *gTujuan = gudang + giTujuan;

    int bi = cariBarang(gAsal, namaBarang);

    // Barang tidak ada di gudang asal
    if (bi == -1) {
        printf("ERROR!\n");
        return;
    }

    // Stok tidak cukup
    if (gAsal->barang[bi].jumlah < jumlah) {
        printf("ERROR!\n");
        return;
    }

    // Gudang tujuan tidak cukup kuota
    if (gTujuan->total + jumlah > MAX_JENIS) {
        printf("ERROR!\n");
        return;
    }

    // Lakukan pemindahan
    gAsal->barang[bi].jumlah -= jumlah;
    gAsal->total -= jumlah;

    int biTujuan = cariBarang(gTujuan, namaBarang);
    if (biTujuan == -1) {
        if (gTujuan->jumlahJenis >= MAX_JENIS) {
            // Kembalikan yang sudah dikurangi
            gAsal->barang[bi].jumlah += jumlah;
            gAsal->total += jumlah;
            printf("ERROR!\n");
            return;
        }
        biTujuan = gTujuan->jumlahJenis;
        strcpy(gTujuan->barang[biTujuan].nama, namaBarang);
        gTujuan->barang[biTujuan].jumlah = 0;
        gTujuan->jumlahJenis++;
    }
    gTujuan->barang[biTujuan].jumlah += jumlah;
    gTujuan->total += jumlah;

    // Kalau barang di gudang asal habis, hapus dari daftar
    if (gAsal->barang[bi].jumlah == 0) {
        int k;
        for (k = bi; k < gAsal->jumlahJenis - 1; k++) {
            gAsal->barang[k] = gAsal->barang[k + 1];
        }
        gAsal->jumlahJenis--;
    }
}

// LIHAT_GUDANG
void lihatGudang(char *nama) {
    int gi = cariGudang(nama);
    if (gi == -1) {
        printf("ERROR!\n");
        return;
    }
    struct Gudang *g = gudang + gi;
    printf("<GUDANG %s>:\n", g->nama);
    printf("Jumlah Barang: %d\n", g->jumlahJenis);
    printf("Total: %d\n", g->total);
}

int main() {
    int q, i;

    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        char perintah[30];
        scanf("%s", perintah);

        if (strcmp(perintah, "TAMBAH_GUDANG") == 0) {
            char x[50];
            scanf("%s", x);
            tambahGudang(x);
        } else if (strcmp(perintah, "TAMBAH_BARANG") == 0) {
            char x[50], y[50];
            int jumlah;
            scanf("%s %s %d", x, y, &jumlah);
            tambahBarang(x, y, jumlah);
        } else if (strcmp(perintah, "PINDAH_BARANG") == 0) {
            char x[50], z[50], y[50];
            int jumlah;
            scanf("%s %s %s %d", x, z, y, &jumlah);
            pindahBarang(x, z, y, jumlah);
        } else if (strcmp(perintah, "LIHAT_GUDANG") == 0) {
            char x[50];
            scanf("%s", x);
            lihatGudang(x);
        }
    }

    return 0;
}
