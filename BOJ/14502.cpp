#include <iostream>
#include <algorithm>

#define loop(i, b, e) for (decltype(b) i = (b), __e = (e); i < __e; ++i)

using namespace std;
struct Pos { int r, c; };

constexpr int dy[]{ -1, 0, 1, 0 };
constexpr int dx[]{ 0, 1, 0, -1 };

int N, M;
char map[8][8];

#define OOB(r, c) (r < 0 || r >= N || c < 0 || c >= M)

int dfs(int r, int c, bool (*vis)[8]) {
    Pos stack[64], *sp = stack;
    int ret{}, v = 0;

    *sp++ = { r, c };
    vis[r][c] = 1;

    while (sp - stack) {
        auto [r, c] = *--sp;
        ++ret;

        for (int i = 0; i < 4; ++i) {
            int dr = r + dy[i], dc = c + dx[i];
            auto& nxt = map[dr][dc];
            if (OOB(dr, dc) || vis[dr][dc]) continue;
            if (nxt == 2) v = 1;
            if (!nxt) {
                *sp++ = { dr, dc };
                vis[dr][dc] = 1;
            }
        }
    }

    return v ? 0 : ret;
}

int count0() {
    bool vis[8][8]{};
    int ret{};
    
    loop (r, 0, N) loop(c, 0, M) {
        if (map[r][c] || vis[r][c]) continue;
        ret += dfs(r, c, vis);
    }

    return ret;
}

int run(int d, int r, int c) {
    if (!d--) return count0();

    int ret{}, j = c;

    loop (i, r, N) {
        for (; j < M; ++j) {
            auto& cur = map[i][j];
            if (cur) continue;
            cur = 1;
            ret = max(ret, run(d, i, j + 1));
            cur = 0;
        }
        j = 0;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    loop (r, 0, N) loop (c, 0, M) {
        auto& cur = map[r][c];
        cin >> cur;
        cur -= '0';
    }

    cout << run(3, 0, 0);
}