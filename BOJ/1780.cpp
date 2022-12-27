#include <iostream>
#include <algorithm>
#include <cstdint>

#define ALL(c) begin(c), end(c)

using namespace std;
using i8 = int8_t;
using u32 = uint32_t;

i8 map[2187][2187];
u32 _cnt[4];
constexpr auto cnt = _cnt + 1;

i8 paper(u32 n, u32 r, u32 c) {
    if (n <= 1) return map[r][c];

    n /= 3;

    i8 sub[9];
    for (u32 i = 0; i < 3; ++i) {
        for (u32 j = 0; j < 3; ++j) {
            sub[i * 3 + j] = paper(n, r + i * n, c + j * n);
        }
    }

    if (all_of(ALL(sub), [&] (auto e) { return e == sub[0]; })) {
        return sub[0];
    }

    for (auto e : sub) ++cnt[e];
    return 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    u32 n;
    cin >> n;

    for (u32 i = 0; i < n; ++i) {
        for (u32 j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }
    }

    ++cnt[paper(n, 0, 0)];

    for (u32 i = 0; i < 3; ++i) {
        cout << _cnt[i] << '\n';
    }
}