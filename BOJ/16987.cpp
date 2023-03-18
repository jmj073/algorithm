#include <iostream>
#include <algorithm>

using namespace std;
struct E { short s, w; };

int N, max_cnt;
E eggs[8];

inline void egg(int n, int cnt) {
    if (n == N) {
        max_cnt = max(max_cnt, cnt);
        return;
    }

    auto& cur = eggs[n];

    if (cur.s <= 0 || cnt == N - 1) {
        egg(n + 1, cnt);
        return;
    }

    for (int i = 0; i < N; ++i) {
        auto& targ = eggs[i];
        if (i == n || targ.s <= 0) continue;

        cur.s -= targ.w;
        targ.s -= cur.w;

        egg(n + 1, cnt + (cur.s <= 0) + (targ.s <= 0));

        cur.s += targ.w;
        targ.s += cur.w;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> eggs[i].s >> eggs[i].w;

    egg(0, 0);
    cout << max_cnt;
}