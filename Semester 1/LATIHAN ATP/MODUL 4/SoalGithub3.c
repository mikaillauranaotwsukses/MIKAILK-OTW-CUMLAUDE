#include <stdio.h>

// Fungsi reverse array integer menggunakan pointer
void reverse(int *arr, int n) {
    int *kiri = arr;           // pointer ke elemen pertama
    int *kanan = arr + n - 1;  // pointer ke elemen terakhir
    int temp;

    while (kiri < kanan) {
        // Tukar nilai yang ditunjuk kiri dan kanan
        temp = *kiri;
        *kiri = *kanan;
        *kanan = temp;

        kiri++;    // geser pointer kiri ke kanan
        kanan--;   // geser pointer kanan ke kiri
    }
}

int main() {
    int n, i;
    int arr[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverse(arr, n);

    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
