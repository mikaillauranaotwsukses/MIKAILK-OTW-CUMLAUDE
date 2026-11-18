#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 65536

// ---- Output buffer (mempercepat printf) ----
static char outBuf[BUFSIZE];
static int outPos = 0;

void flushOut(void) {
    if (outPos > 0) {
        fwrite(outBuf, 1, outPos, stdout);
        outPos = 0;
    }
}

void putChar(char c) {
    if (outPos == BUFSIZE) flushOut();
    outBuf[outPos++] = c;
}

void putInt(int x) {
    char tmp[12];
    int len = 0;
    if (x == 0) { putChar('0'); return; }
    while (x > 0) { tmp[len++] = (char)('0' + x % 10); x /= 10; }
    while (len > 0) putChar(tmp[--len]);
}

void putLL(long long x) {
    char tmp[24];
    int len = 0;
    if (x == 0) { putChar('0'); return; }
    while (x > 0) { tmp[len++] = (char)('0' + x % 10); x /= 10; }
    while (len > 0) putChar(tmp[--len]);
}

// ---- Input buffer (mempercepat scanf) ----
static char inBuf[BUFSIZE];
static int inPos = 0, inLen = 0;

int bacaChar(void) {
    if (inPos == inLen) {
        inLen = (int)fread(inBuf, 1, BUFSIZE, stdin);
        inPos = 0;
        if (inLen == 0) return -1;
    }
    return (unsigned char)inBuf[inPos++];
}

long long bacaLL(void) {
    long long num = 0;
    int c = bacaChar();
    while (c <= ' ' && c != -1) c = bacaChar();
    while (c > ' ') {
        num = num * 10 + (c - '0');
        c = bacaChar();
    }
    return num;
}

int bacaInt(void) {
    return (int)bacaLL();
}

// Binary search manual: indeks terakhir yang <= p (0-based), -1 jika tidak ada
int batasAtas(long long *arr, int n, long long p) {
    int kiri = 0, kanan = n - 1, hasil = -1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (arr[tengah] <= p) {
            hasil = tengah;
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return hasil;
}

int main() {
    int n = bacaInt();
    int q = bacaInt();
    int i;

    long long *bounty = (long long *) malloc((size_t)n * sizeof(long long));
    long long *prefix = (long long *) malloc((size_t)(n + 1) * sizeof(long long));

    for (i = 0; i < n; i++) {
        bounty[i] = bacaLL();
    }

    // Prefix sum
    prefix[0] = 0;
    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + bounty[i];
    }

    for (i = 0; i < q; i++) {
        long long p = bacaLL();
        int k = bacaInt();

        int idx = batasAtas(bounty, n, p);

        if (idx == -1) {
            putChar('0'); putChar(' '); putChar('0'); putChar('\n');
            continue;
        }

        int kandidat = idx + 1;
        int ambil = (k < kandidat) ? k : kandidat;
        int mulai = idx - ambil + 1;

        long long total = prefix[idx + 1] - prefix[mulai];

        putInt(ambil);
        putChar(' ');
        putLL(total);
        putChar('\n');
    }

    flushOut();

    free(bounty);
    free(prefix);

    return 0;
}
