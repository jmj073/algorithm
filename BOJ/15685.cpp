#include <iostream>

using namespace std;

constexpr int D[]{ 1, -101, -1, 101 };

bool seq[1<<10];
bool map[101][101];
#define map2 ((bool*)map)

void dragon(int pos, int d, int g) {
    int n = 1 << g;

    for (int i = 0; i < n; ++i) {
        map2[pos] = 1;
        pos += D[d];
        d = (d + (seq[i] ? 3 : 1)) % 4;
    }

    map2[pos] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < 10; ++i) {
        int cur = (1 << i) - 1;
        for (int j = 0; j < cur; ++j) {
            seq[cur + 1 + j] = !seq[cur - 1 - j];
        }
    }

    while (N--) {
        int r, c, d, g;
        cin >> c >> r >> d >> g;
        dragon(r * 101 + c, d, g);
    }

    int ans{};

    for (int r = 0; r < 100; ++r) {
        for (int c = 0; c < 100; ++c) {
            int a = map[r][c] + map[r + 1][c + 1]
                  + map[r][c + 1] + map[r + 1][c];
            ans += (a == 4);
        }
    }

    cout << ans;
}