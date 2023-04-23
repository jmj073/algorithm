#include <iostream>
#include <cmath>

#define loop(i, b, e) for (decltype(b) i = (b), __e = (e); i < __e; ++i)

using namespace std;

int N, L;
int map[100][100];
#define map2 ((int*)map)

bool check(int i, int d) {
    int l{};
    auto p = map2[i];

    loop (_, 0, N) {
        auto c = map2[i];

        if (abs(c - p) > 1) {
            return false;
        }
        if (p < c) {
            if (l < L) return false;
            l = 0;
        } else if (p > c) {
            if (l < 0) return false;
            l = -L;
        }

        ++l;
        p = c;
        i += d;
    }

    return l >= 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> L;

    loop (r, 0, N) loop (c, 0, N) {
        cin >> map[r][c];
    }

    int ans{};

    loop (i, 0, N) {
        ans += check(i * 100, 1);
        ans += check(i, 100);
    }

    cout << ans;
}