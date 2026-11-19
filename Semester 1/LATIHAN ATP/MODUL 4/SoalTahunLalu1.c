#include <stdio.h>
#include <string.h>

// Struct untuk menyimpan data institusi
struct Institusi {
    char nama[100];
    int emas;
    int perak;
    int perunggu;
    int totalPoin;
};

int main() {
    struct Institusi inst[10];   // Array of Struct: 10 institusi
    int i;

    // Input data 10 institusi
    for (i = 0; i < 10; i++) {
        scanf("%s %d %d %d", inst[i].nama,
                            &inst[i].emas,
                            &inst[i].perak,
                            &inst[i].perunggu);

        // Hitung total poin: EMAS=4, PERAK=2, PERUNGGU=1
        inst[i].totalPoin = (inst[i].emas * 4)
                          + (inst[i].perak * 2)
                          + (inst[i].perunggu * 1);
    }

    // Cari poin tertinggi
    int maxPoin = inst[0].totalPoin;
    for (i = 1; i < 10; i++) {
        if (inst[i].totalPoin > maxPoin) {
            maxPoin = inst[i].totalPoin;
        }
    }

    // Hitung berapa institusi yang punya poin tertinggi
    int jumlahMax = 0;
    int indexMax = 0;
    for (i = 0; i < 10; i++) {
        if (inst[i].totalPoin == maxPoin) {
            jumlahMax++;
            indexMax = i;
        }
    }

    // Kalau lebih dari satu -> susah diprediksi
    if (jumlahMax > 1) {
        printf("Susah diprediksi!\n");
    } else {
        printf("%s\n", inst[indexMax].nama);
    }

    return 0;
}
