#include <stdio.h>
#include <stdlib.h>

int main() {
    int input;

    printf("Jumlah siswa: ");
    scanf("%d", &input);

    int *b = malloc(input * sizeof(int));

    for (int i = 0; i < input; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < input; i++) {
        printf("%d ", b[i]);
    }

    free(b);

    return 0;
}