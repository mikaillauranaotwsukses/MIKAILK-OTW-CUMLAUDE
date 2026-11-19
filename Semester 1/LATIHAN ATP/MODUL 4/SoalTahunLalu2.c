#include <stdio.h>

// Fungsi mencari nilai minimum dan maksimum
// WAJIB pakai pointer untuk iterasi (bukan indeks biasa)
void cariMinMax(int *arr, int n, int *min, int *max) {
    int *p = arr;        // pointer menunjuk elemen pertama
    int *akhir = arr + n; // pointer menunjuk SATU SETELAH elemen terakhir

    // Inisialisasi min & max dengan elemen pertama
    *min = *arr;
    *max = *arr;

    // Iterasi pakai pointer
    while (p < akhir) {
        if (*p < *min) {
            *min = *p;
        }
        if (*p > *max) {
            *max = *p;
        }
        p++;   // geser pointer ke elemen berikutnya
    }
}

int main() {
    int n, i;
    int arr[10];
    int min, max;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    cariMinMax(arr, n, &min, &max);

    printf("%d %d\n", min, max);

    return 0;
}
