#include <stdio.h>

int main() {
    char buf[32], *p = buf;
    int n;
    scanf("%s %d", buf, &n);

    int ans = 0;

    while (*p) {
        ans *= n;
        ans += *p - (*p > 64 ? 'A' - 10 : '0');
        ++p;
    }

    printf("%d", ans);
}