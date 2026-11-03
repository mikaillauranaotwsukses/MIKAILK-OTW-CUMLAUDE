#include <stdio.h>

// Fungsi rekursif: hitung berapa kali N dibagi 2 sampai jadi 0
long long mugen(long long n) {
    if (n <= 0) {
        return 0;  // base case: jarak sudah 0
    }
    return 1 + mugen(n / 2);  // recursive case: potong setengah, hitung +1
}

int main() {
    long long n;

    scanf("%lld", &n);
    printf("%lld\n", mugen(n));

    return 0;
}
