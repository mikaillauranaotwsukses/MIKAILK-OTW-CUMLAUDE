#include <stdio.h>

int arr[100001];
int temp[100001];
int sub[100001];

// Fungsi merge sort yang menghitung jumlah inversion
long long mergeCount(int a[], int t[], int left, int right) {
    long long count = 0;
    int mid, i, j, k;

    if (left >= right) {
        return 0;
    }

    mid = (left + right) / 2;

    // Rekursi: bagi dua lalu hitung masing-masing
    count += mergeCount(a, t, left, mid);
    count += mergeCount(a, t, mid + 1, right);

    // Merge dan hitung inversion antar dua bagian
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            t[k] = a[i];
            i++;
        } else {
            // Semua elemen dari i sampai mid lebih besar dari a[j]
            // jadi semuanya membentuk inversion dengan a[j]
            count += (mid - i + 1);
            t[k] = a[j];
            j++;
        }
        k++;
    }

    // Sisa elemen kiri
    while (i <= mid) {
        t[k] = a[i];
        i++;
        k++;
    }

    // Sisa elemen kanan
    while (j <= right) {
        t[k] = a[j];
        j++;
        k++;
    }

    // Salin kembali ke array asli
    for (i = left; i <= right; i++) {
        a[i] = t[i];
    }

    return count;
}

int main() {
    int n, q, l, r, i, j;

    scanf("%d %d", &n, &q);

    for (i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);

        // Copy segmen [l, r] ke sub array agar array asli tidak berubah
        for (j = l; j <= r; j++) {
            sub[j] = arr[j];
        }

        printf("%lld\n", mergeCount(sub, temp, l, r));
    }

    return 0;
}
