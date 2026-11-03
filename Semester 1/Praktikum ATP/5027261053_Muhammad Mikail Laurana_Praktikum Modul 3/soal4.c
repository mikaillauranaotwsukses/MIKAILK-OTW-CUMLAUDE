#include <stdio.h>
#include <string.h>

int n, k;
int berat[105];
int nilai[105];
long long memo[105][1005];

// Fungsi rekursif dengan memoization (top-down DP)
// i = indeks echo yang sedang dipertimbangkan
// sisa = kapasitas berat yang masih tersedia
long long knapsack(int i, int sisa) {
    // Base case: semua echo sudah dipertimbangkan
    if (i == n) {
        return 0;
    }

    // Kalau sudah pernah dihitung, langsung pakai hasil memo
    if (memo[i][sisa] != -1) {
        return memo[i][sisa];
    }

    // Pilihan 1: LEWATKAN echo ke-i
    long long lewat = knapsack(i + 1, sisa);

    // Pilihan 2: AMBIL echo ke-i (hanya jika beratnya muat)
    long long ambil = -1;
    if (berat[i] <= sisa) {
        ambil = nilai[i] + knapsack(i + 1, sisa - berat[i]);
    }

    // Ambil yang nilainya lebih besar
    long long hasil;
    if (ambil > lewat) {
        hasil = ambil;
    } else {
        hasil = lewat;
    }

    // Simpan ke memo sebelum return
    memo[i][sisa] = hasil;
    return hasil;
}

int main() {
    int i;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &berat[i], &nilai[i]);
    }

    // Isi seluruh array memo dengan -1 (tanda "belum dihitung")
    memset(memo, -1, sizeof(memo));

    printf("%lld\n", knapsack(0, k));

    return 0;
}
