#include <stdio.h>

// Fungsi untuk konversi menit ke jam
int keJam(int totalMenit) {
    return totalMenit / 60;
}

// Fungsi untuk hitung sisa menit
int sisaMenit(int totalMenit) {
    return totalMenit % 60;
}

int main() {
    int totalMenit;

    scanf("%d", &totalMenit);

    printf("%d jam %d menit\n", keJam(totalMenit), sisaMenit(totalMenit));

    return 0;
}
