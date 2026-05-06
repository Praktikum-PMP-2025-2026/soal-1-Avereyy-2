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

    // WAIT
    int total_wait = 0;
    int current_time = 0;

    for (int i = 0; i < N; i++) {
        total_wait += current_time;
        current_time += durasi[i];
    }

    printf("WAIT %d", total_wait); // ❗ no extra newline at end

    return 0;
}
