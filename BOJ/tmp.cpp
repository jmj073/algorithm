#include <cstdio>
#include <bit>

#define foreach_bit(i, set) \
    for (ULL _ = (set), i{}; ({ auto d = std::countr_zero(_); i += d; _ >>= d; }); _ >>= 1, ++i)

using ULL = unsigned long long;

ULL fill_bit() {
    int n;
    scanf("%d", &n);
    ULL ret{};
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ret |= 1ULL << (a - 1);
    }
    return ret;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    ULL A = fill_bit();

    ULL party[50]{}, per[50]{};

    for (int i = 0; i < M; ++i) {
        ULL tmp = party[i] = fill_bit();
        foreach_bit(i, tmp) {
            per[i] |= tmp;
        }
    }

    ULL know{};

    while (A) {
        know |= A;
        ULL B{};
        foreach_bit(i, A) {
            B |= per[i];
        }
        A = B & ~know;
    }

    int ans{};
    for (int i = 0; i < M; ++i) {
        ans += !(party[i] & know);
    }

    printf("%d", ans);
}
