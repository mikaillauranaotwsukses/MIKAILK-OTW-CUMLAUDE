#include <stdio.h>

// Fungsi menghitung AVERAGE
double average(double arr[], int n) {
    double total = 0;
    int i;
    for (i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

// Fungsi menghitung SUM
double sum(double arr[], int n) {
    double total = 0;
    int i;
    for (i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Fungsi mencari MAX
double max(double arr[], int n) {
    double maks = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

// Fungsi mencari MIN
double min(double arr[], int n) {
    double mini = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < mini) {
            mini = arr[i];
        }
    }
    return mini;
}

int main() {
    int n, opsi, i;
    double arr[50];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    scanf("%d", &opsi);

    if (opsi == 1) {
        printf("%.2lf\n", average(arr, n));
    } else if (opsi == 2) {
        printf("%.2lf\n", sum(arr, n));
    } else if (opsi == 3) {
        printf("%.2lf\n", max(arr, n));
    } else if (opsi == 4) {
        printf("%.2lf\n", min(arr, n));
    } else if (opsi == 5) {
        printf("TERIMAKASIH\n");
    }

    return 0;
}
