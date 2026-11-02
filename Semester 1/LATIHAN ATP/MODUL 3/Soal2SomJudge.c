#include <stdio.h>

int N, S;
int A[100];

// Mengembalikan L (lompatan minimum), atau -1 jika tidak ketemu
int bfs(int start) {
    int dist[100];
    int queue[100];
    int head = 0, tail = 0;

    for (int i = 0; i < N; i++) dist[i] = -1;

    dist[start] = 0;
    queue[tail++] = start;

    while (head < tail) {
        int cur = queue[head++];

        if (A[cur] == 0) return dist[cur];

        int kanan = cur + A[cur];
        int kiri = cur - A[cur];

        if (kanan < N && dist[kanan] == -1) {
            dist[kanan] = dist[cur] + 1;
            queue[tail++] = kanan;
        }
        if (kiri >= 0 && dist[kiri] == -1) {
            dist[kiri] = dist[cur] + 1;
            queue[tail++] = kiri;
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    int L = bfs(S);

    if (L == -1) printf("-1\n");
    else printf("%d %d %d\n", L, L * 3, L + 7);

    return 0;
}