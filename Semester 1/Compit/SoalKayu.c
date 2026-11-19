
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int W[N];
    int kiri[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &W[i]);
    }

    
    int sebelumnya = 0;

    for (int i = 0; i < N; i++) {
        if (W[i] == 0) {
            kiri[i] = 0;
            sebelumnya = 0;
        } else {
            kiri[i] = W[i];

            if (sebelumnya + 1 < kiri[i]) {
                kiri[i] = sebelumnya + 1;
            }

            sebelumnya = kiri[i];
        }
    }

    
    sebelumnya = 0;

    int jawaban = 0;

    for (int i = N - 1; i >= 0; i--) {
        int kanan;

        if (W[i] == 0) {
            kanan = 0;
            sebelumnya = 0;
        } else {
            kanan = W[i];

            if (sebelumnya + 1 < kanan) {
                kanan = sebelumnya + 1;
            }

            sebelumnya = kanan;
        }

        
        int waktu = kiri[i];

        if (kanan < waktu) {
            waktu = kanan;
        }

        
        if (waktu > jawaban) {
            jawaban = waktu;
        }
    }

    printf("%d\n", jawaban);

    return 0;
}
