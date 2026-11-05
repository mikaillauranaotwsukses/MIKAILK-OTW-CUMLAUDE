#include <iostream>

using namespace std;

int main() {
    int n;
    double total = 0;

    cin >> n;

    // Alokasi memori dinamis untuk n buah nilai
    double *nilai = new double[n];

    // Input nilai-nilai
    for (int i = 0; i < n; i++) {
        cin >> nilai[i];
        total += nilai[i];
    }

    // Hitung rata-rata
    cout << total / n << endl;

    // Bebaskan memori
    delete[] nilai;

    return 0;
}
