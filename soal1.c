#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char id[N][10];
    int durasi[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d", id[i], &durasi[i]);
    }

    // ORDER
    printf("ORDER");
    for (int i = 0; i < N; i++) {
        printf(" %s", id[i]);
    }
    printf("\n");

    int total_wait = 0;
    int current_time = 0;

    for (int i = 0; i < N - 1; i++) { // ❗ stop at N-1
        total_wait += current_time;
        current_time += durasi[i];
    }

    printf("WAIT %d", total_wait);

    return 0;
}
