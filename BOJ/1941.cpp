#include <iostream>
#include <cstring>

using namespace std;
struct Pos { int r, c; };

constexpr int dx[]{ 1, -1, 0, 0 };
constexpr int dy[]{ 0, 0, 1, -1 };

char map[5][6], vis[5][5];
#define _vis ((char*)vis)
int cnt;

bool check(int r, int c) {
    Pos st[64], *top = st;
    int s{}, n{};
    char lvis[5][5];

    memcpy(lvis, vis, sizeof(vis));
    *top++ = { r, c };

    while (top != st) {
        auto [r, c] = *--top;

        if (!lvis[r][c]) continue;
        lvis[r][c] = 0;

        ++n;
        s += (map[r][c] == 'S');

        for (int i = 0; i < 4; ++i) {
            int dr = r + dx[i], dc = c + dy[i];
            if (dr < 0 || dr > 4 || dc < 0 || dc > 4) continue;
            *top++ = { dr, dc };
        }
    }

    return n > 6 && s > 3;
}

void rec(int m, int i) {
    if (!m--) {
        --i;
        cnt += check(i / 5, i % 5);

        return;
    }

    for (; i + m < 25; ++i) {
        _vis[i] = 1;
        rec(m, i + 1);
        _vis[i] = 0;
    }
}

int main() {
    for (int i = 0; i < 5; ++i)
        cin >> map[i];

    rec(7, 0);
    cout << cnt;
}

// void print() {
//     for (int i = 0; i < 5; ++i) {
//         for (int j = 0; j < 5; ++j)
//             cout << char(vis[i][j] + '0');
//         cout << '\n';
//     }
// }