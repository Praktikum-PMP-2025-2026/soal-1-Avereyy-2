#include <stdio.h>

int main() {
    int N;

    if (scanf("%d", &N) != 1) return 0;

    int arr[N];
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }

    int level = 0;
    int index = 0;

    while (index < N) {
        int nodes = 1 << level;  // 2^level TANPA pow()

        printf("LEVEL %d:", level);

        for (int i = 0; i < nodes && index < N; i++) {
            printf(" %d", arr[index]);
            index++;
        }

        if (index < N) printf("\n");  // ❗ no extra newline at end
        level++;
    }

    return 0;
}
