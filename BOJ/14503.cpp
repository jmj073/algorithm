#include <iostream>

#define LOOP(i, n) for (int i = 0, __n = (n); i < __n; ++i)

using namespace std;

constexpr int dy[]{ -1, 0, 1, 0 };
constexpr int dx[]{ 0, 1, 0, -1 };

// 북, 동, 남, 서
int R, C, r, c, d;
int map[50][50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C >> r >> c >> d;

    int cnt{};

    LOOP (r, R) LOOP (c, C) {
        cin >> map[r][c];
    }

    int ans{};

    while (true) {
    SKIP:
        ans += !map[r][c];
        map[r][c] = 2; // 청소 됨

        LOOP(_, 4) {
            d = (d + 3) % 4;
            int dr = r + dy[d], dc = c + dx[d];
            if (map[dr][dc]) continue;
            r = dr, c = dc;
            goto SKIP;
        }

        r -= dy[d], c -= dx[d];
        if (map[r][c] == 1) break;
    }

    cout << ans;
}