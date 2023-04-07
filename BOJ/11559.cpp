#include <iostream>

using namespace std;
struct Pos { int r, c; };

constexpr int dx[]{ 1, -1, 0, 0 };
constexpr int dy[]{ 0, 0, 1, -1 };
constexpr int R = 12, C = 6;

char map[R][C + 1];

inline bool OOB(int r, int c) { return r < 0 || r >= R || c < 0 || c >= C; }

void dfs(int r, int c) {
    char cur = map[r][c];
    map[r][c] = '.';

    for (int i = 0; i < 4; ++i) {
        int dr = r + dx[i], dc = c + dy[i];
        if (OOB(dr, dc) || map[dr][dc] != cur) continue;
        dfs(dr, dc);
    }
}

bool check(int r, int c) {
    int cnt = 1;
    char vis[R][C]{};
    Pos sta[R * C], *top = end(sta);

    vis[r][c] = 1;
    *--top = { r, c };

    while (end(sta) != top) {
        auto [r, c] = *top++;
        for (int i = 0; i < 4; ++i) {
            int dr = r + dx[i], dc = c + dy[i];
            if (OOB(dr, dc) || vis[dr][dc] || map[dr][dc] != map[r][c]) continue;
            vis[dr][dc] = 1;
            if (++cnt > 3) return true;
            *--top = { dr, dc };
        }
    }

    return false;
}

void update() {
    for (int c = 0; c < C; ++c) {
        int i = R;
        for (int r = R; r--;) {
            char cur = map[r][c];
            if (cur != '.') {
                map[r][c] = '.';
                map[--i][c] = cur;
            }
        }
    }
}

int run() {
    int cnt{};

    while (true) {
        bool boom{};
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (map[r][c] != '.') {
                    bool chk = check(r, c);
                    boom |= chk;
                    if (chk) dfs(r, c);
                }
            }
        }
        if (!boom) break;
        update();
        ++cnt;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int r = 0; r < R; ++r)
        cin >> map[r];
    
    cout << run();
}

void print() {
    for (int r = 0; r < R; ++r)
        cout << map[r] << '\n';
}

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);

//     for (int r = R; r--;)
//         cin >> map[r];
    
//     update();
//     cout << '\n';
//     print();
// }