#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    char id[N][10];
    int durasi[N];

    // input
    for (int i = 0; i < N; i++) {
        scanf("%s %d", id[i], &durasi[i]);
    }

    // output ORDER
    printf("ORDER ");
    for (int i = 0; i < N; i++) {
        printf("%s", id[i]);
        if (i != N - 1) printf(" ");
    }
    printf("\n");

    // hitung WAIT
    int total_wait = 0;
    int current_time = 0;

    for (int i = 0; i < N; i++) {
        total_wait += current_time;
        current_time += durasi[i];
    }

    printf("WAIT %d\n", total_wait);

    return 0; //TES
}
