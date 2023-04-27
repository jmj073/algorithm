/*
정확한 좌표는 다르지만 의미상으로
같은 위치로 볼 수 있는 것들이 있다.
그것을 스킵하면 속도가 올라갈 것이다.
*/

#include <iostream>
#include <cstdint>
#include <bit>
#include <algorithm>

#define MAX 9

using namespace std;

// 30, 10
//  H, N, M
int R, C, N;
uint16_t map[30];

bool check() {
    char tmp[10];

    for (int i = 0; i < C; ++i)
        tmp[i] = i;

    for (int r = 0; r < R; ++r) {
        auto cur = map[r];
        int c = countr_zero(cur);
        cur >>= c;
        while (c < C - 1) {
            swap(tmp[c], tmp[c + 1]);
            auto d = countr_zero(cur >>= 1);
            c += d + 1, cur >>= d;
        }
    }

    for (int i = 0; i < C; ++i) {
        if (tmp[i] != i) return false;
    }

    return true;
}

int run(int n, int r, int c) {
    if (n++ >= 3) return MAX;

    int ret = MAX;

    for (; r < R; ++r) {
        uint16_t cur = map[r] >> c;

        while (c < C - 1) {
            if (!(cur & 3)) {
                map[r] |= 1 << c;
                if (check()) {
                    map[r] &= ~(1 << c);
                    return n;
                }
                ret = min(ret, run(n, r, c + 2));
                map[r] &= ~(1 << c);
            }

            auto d = countr_one(cur) + 1;
            c += d, cur >>= d;
        }

        c = 0;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> C >> N >> R;

    while (N--) {
        int r, c;
        cin >> r >> c;
        map[r - 1] |= 1 << (c - 1);
    }

    if (check()) {
        cout << '0';
        return 0;
    }

    int ans = run(0, 0, 0);
    cout << (ans == MAX ? -1 : ans);
}