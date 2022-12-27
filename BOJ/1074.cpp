#include <iostream>

using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    int ans = 0;
    while (n--) {
        ans *= 4;
        auto cnt = 2 * (r >> n & 1) + (c >> n & 1);
        ans += cnt;
    }

    cout << ans;
}

// O(cnt) ===========================================
#if 0
size_t N, R, C;
int cnt;

void Z(size_t n, size_t r, size_t c) {
    if (n == 0) {
        if (r == R && c == C) {
            (cout << cnt).flush();
            exit(0);
        }
        ++cnt;
        return;
    }

    auto offset = 1 << --n;

    Z(n, r, c);
    Z(n, r, c + offset);
    Z(n, r + offset, c);
    Z(n, r + offset, c + offset);
}

int main() {
    cin >> N >> R >> C;
    Z(N, 0, 0);
}
#endif
// O(N)================================================
#if 0
int Z(int n, int r, int c) {
    if (n == 0) return 0;
    auto half = 1 << --n;
    auto cnt = 2 * (r / half) + (c / half);
    return Z(n, r % half, c % half) + cnt * half * half;
}

int main() {
    int N, R, C;
    cin >> N >> R >> C;
    cout << Z(N, R, C);
}
#endif
// =====================================================
#if 0
int main() {
    int n, r, c;
    cin >> n >> r >> c;
    
    int ans = 0;
    while (n--) {
        auto half = 1 << n;
        auto cnt = 2 * (r / half) + (c / half);
        r %= half;
        c %= half;
        ans += cnt * half * half;
    }

    cout << ans;
}
#endif
// =====================================================

