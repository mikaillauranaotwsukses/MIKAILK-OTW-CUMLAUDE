#include <stdio.h>

int arr[100];
int visited[100];  


void radar(int i, int n, int s, int langkah) {
    // Cek keluar batas
    if (i < 0 || i >= n) {
        printf("-1\n");
        return;
    }

    // Cek ketemu Dragon Ball
    if (arr[i] == 0) {
        printf("%d %d %d\n", s, i, langkah);
        return;
    }

    // Cek loop (sudah pernah dikunjungi)
    if (visited[i] == 1) {
        printf("-1\n");
        return;
    }

    // Tandai sudah dikunjungi
    visited[i] = 1;

    // Tentukan lompatan berikutnya
    if (arr[i] % 2 == 0) {
        // Genap -> lompat ke kanan
        radar(i + arr[i], n, s, langkah + 1);
    } else {
        // Ganjil -> lompat ke kiri
        radar(i - arr[i], n, s, langkah + 1);
    }
}

int main() {
    int n, s, i;

    scanf("%d %d", &n, &s);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    radar(s, n, s, 0);

    return 0;
}
