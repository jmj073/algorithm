/*

대각선 개수: N * 2 - 1
정(사각형) -> 마(름모):  

*/

#include <iostream>
#include <algorithm>
#include <bit>

using namespace std;
struct P { int r, c; };

int N, M, CNT;
int _inval[2][20];
int* inval;

inline
P n2m(int r, int c) {
    return { r + c, c - r + N - 1 };
}

int run(int m, int l) {
    if (m == M) return 0;
    int use = inval[m] | l;
    if (!~use) return run(m + 1, l);
    int _max = 0, a = 1;

    while (~use) {
        auto d = countr_one(unsigned(use));
        a <<= d, use >>= d;
        _max = max(_max, run(m + 1, l | a) + 1);
        a <<= 1, use >>= 1;
    }

    return _max;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    M = N * 2 - 1;
    fill(_inval[0], _inval[0] + M, ~0);
    fill(_inval[1], _inval[1] + M, ~0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool tmp; cin >> tmp;
            if (tmp) {
                auto [r, c] = n2m(i, j);
                _inval[r & 1][c] &= ~(1 << r);
            }
        }
    }

    inval = _inval[0];
    int cnt = run(0, 0);
    inval = _inval[1];
    cout << cnt + run(0, 0);
}