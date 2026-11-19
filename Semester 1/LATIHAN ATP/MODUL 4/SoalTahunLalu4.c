
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nama[100];
    int jumlah;
} Barang;

typedef struct {
    char nama[100];
    Barang barang[100];
    int jumlah_jenis;
} Gudang;

Gudang daftar_gudang[5];
int jumlah_gudang = 0;

Gudang* CariGudang(char* nama) {
    for (int i = 0; i < jumlah_gudang; i++) {
        if (strcmp(daftar_gudang[i].nama, nama) == 0) {
            return &daftar_gudang[i];
        }
    }

    return NULL;
}

int* CariBarang(Gudang* gudang, char* nama_barang) {
    for (int i = 0; i < gudang->jumlah_jenis; i++) {
        if (strcmp(gudang->barang[i].nama, nama_barang) == 0) {
            return &gudang->barang[i].jumlah;
        }
    }

    return NULL;
}

void TambahGudang(char* nama) {
    if (jumlah_gudang >= 5 || CariGudang(nama) != NULL) {
        printf("ERROR!\n");
        return;
    }

    strcpy(daftar_gudang[jumlah_gudang].nama, nama);
    daftar_gudang[jumlah_gudang].jumlah_jenis = 0;

    jumlah_gudang++;
}

void TambahBarang(char* nama_gudang, char* nama_barang, int jumlah) {
    Gudang* gudang = CariGudang(nama_gudang);

    if (gudang == NULL) {
        printf("ERROR!\n");
        return;
    }

    int* stok = CariBarang(gudang, nama_barang);

    if (stok != NULL) {
        *stok += jumlah;
    } else {
        if (gudang->jumlah_jenis >= 100) {
            printf("ERROR!\n");
            return;
        }

        int posisi = gudang->jumlah_jenis;

        strcpy(gudang->barang[posisi].nama, nama_barang);
        gudang->barang[posisi].jumlah = jumlah;

        gudang->jumlah_jenis++;
    }
}

void PindahBarang(char* asal, char* tujuan, char* nama_barang, int jumlah) {
    Gudang* gudang_asal = CariGudang(asal);
    Gudang* gudang_tujuan = CariGudang(tujuan);

    if (gudang_asal == NULL || gudang_tujuan == NULL) {
        printf("ERROR!\n");
        return;
    }

    int* stok_asal = CariBarang(gudang_asal, nama_barang);

    if (stok_asal == NULL || *stok_asal < jumlah) {
        printf("ERROR!\n");
        return;
    }

    if (gudang_asal == gudang_tujuan) {
        return;
    }

    int* stok_tujuan = CariBarang(gudang_tujuan, nama_barang);

    if (stok_tujuan == NULL && gudang_tujuan->jumlah_jenis >= 100) {
        printf("ERROR!\n");
        return;
    }

    if (stok_tujuan == NULL) {
        int posisi = gudang_tujuan->jumlah_jenis;

        strcpy(gudang_tujuan->barang[posisi].nama, nama_barang);
        gudang_tujuan->barang[posisi].jumlah = jumlah;

        gudang_tujuan->jumlah_jenis++;
    } else {
        *stok_tujuan += jumlah;
    }

    *stok_asal -= jumlah;
}

void LihatGudang(char* nama) {
    Gudang* gudang = CariGudang(nama);

    if (gudang == NULL) {
        printf("ERROR!\n");
        return;
    }

    int total = 0;

    for (int i = 0; i < gudang->jumlah_jenis; i++) {
        total += gudang->barang[i].jumlah;
    }

    printf("<GUDANG %s>:\n", gudang->nama);
    printf("Jumlah Barang: %d\n", gudang->jumlah_jenis);
    printf("Total: %d\n", total);
}

int main() {
    int Q;
    scanf("%d", &Q);

    char instruksi[30];
    char X[100], Y[100], Z[100];
    int I;

    for (int i = 0; i < Q; i++) {
        scanf("%s", instruksi);

        if (strcmp(instruksi, "TAMBAH_GUDANG") == 0) {
            scanf("%s", X);
            TambahGudang(X);
        } 
        else if (strcmp(instruksi, "TAMBAH_BARANG") == 0) {
            scanf("%s %s %d", X, Y, &I);
            TambahBarang(X, Y, I);
        } 
        else if (strcmp(instruksi, "PINDAH_BARANG") == 0) {
            scanf("%s %s %s %d", X, Z, Y, &I);
            PindahBarang(X, Z, Y, I);
        } 
        else if (strcmp(instruksi, "LIHAT_GUDANG") == 0) {
            scanf("%s", X);
            LihatGudang(X);
        }
    }

    return 0;
}
