#include <stdio.h>

#define INF 1000000000

int dp[10001];

int main() {
    int K, T;
    scanf("%d %d", &K, &T);

    int coin[100];
    for (int i = 0; i < K; i++) {
        scanf("%d", &coin[i]);
    }

    dp[0] = 0;
    for (int i = 1; i <= T; i++) {
        dp[i] = INF;
        for (int j = 0; j < K; j++) {
            if (coin[j] <= i && dp[i - coin[j]] != INF) {
                if (dp[i - coin[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coin[j]] + 1;
                }
            }
        }
    }

    if (dp[T] == INF) printf("-1\n");
    else printf("%d\n", dp[T]);

    return 0;
}