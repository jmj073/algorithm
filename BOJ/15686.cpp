#include <iostream>
#include <algorithm>

using namespace std;
struct Pos { int r, c; };

int N, M;
int home_sz, chi_sz;
Pos home[100], chi[13], sel[13];

int getdist() {
    int dist = 0;

    for (int i = 0; i < home_sz; ++i) {
        auto [hr, hc] = home[i];

        int minv = 999;
        for (int j = 0; j < M; ++j) {
            auto [sr, sc] = sel[j];
            int d = abs(hr - sr) + abs(hc - sc);
            minv = min(minv, d);
        }

        dist += minv;
    }

    return dist;
}

int run(int m, int i) {
    if (!m--) return getdist();

    int md = 4321;

    while (m + i < chi_sz) {
        sel[m] = chi[i++];
        md = min(md, run(m, i));
    }

    return md;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c) {
            int tmp; cin >> tmp;
            if (!tmp) continue;
            (tmp == 1 ? home[home_sz++]
            : chi[chi_sz++]) = { r, c };
        }
    
    cout << run(M, 0);
}