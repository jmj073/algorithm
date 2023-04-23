#include <stdio.h>
#include <string.h>

int arr[1000000];

void merge(int* arr, int* a, int an, int* b, int bn) {
    static int tmp[1000000];
    int i = 0, ai = 0, bi = 0;

    while (ai < an && bi < bn) {
        tmp[i++] = (a[ai] < b[bi] ? a[ai++] : b[bi++]);
    }

    if (ai < an) {
        memcpy(tmp + i, a + ai, sizeof(int) * (an - ai));
    } else if (bi < bn) {
        memcpy(tmp + i, b + bi, sizeof(int) * (bn - bi));
    }

    memcpy(arr, tmp, sizeof(int) * (an + bn));
}

void sort(int* arr, int n) {
    if (n < 2) return;
    int h = n / 2;

    sort(arr, h);
    sort(arr + h, n - h);
    merge(arr, arr, h, arr + h, n - h);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    sort(arr, n);

    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
}