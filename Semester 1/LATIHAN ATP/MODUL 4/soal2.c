
#include <stdio.h>

void statistik(int *arr, int n, int *min, int *max, int *sum) {
    int i;

    *min = *arr;
    *max = *arr;
    *sum = 0;

    for (i = 0; i < n; i++) {
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }

        if (*(arr + i) > *max) {
            *max = *(arr + i);
        }

        *sum += *(arr + i);
    }
}

int main() {
    int n;
    int arr[100];
    int min, max, sum;
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    statistik(arr, n, &min, &max, &sum);

    double rataRata = (double) sum / n;

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Sum: %d\n", sum);
    printf("Rata-rata: %.2f\n", rataRata);

    return 0;
}
