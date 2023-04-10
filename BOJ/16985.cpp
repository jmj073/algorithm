#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define ALL(c) begin(c), end(c)
#define LOOP(i, n) for (int i = 0, __n = (n); i < __n; ++i)

#define MAX 999

using namespace std;
struct Pos { int k, r, c; };

constexpr int dx[]{ 0, 0, 0, 0, 1, -1 };
constexpr int dy[]{ 0, 0, 1, -1, 0, 0 };
constexpr int dz[]{ 1, -1, 0, 0, 0, 0 };

bool map[5][5][5];
bool (*map2[5])[5];
int ans = MAX;

inline bool OOB(int k, int r, int c) {
    return k < 0 || k >= 5 || r < 0 || r >= 5 || c < 0 || c >= 5;
}

int bfs() {
    if (!map2[0][0][0] || !map2[4][4][4]) return MAX;

    int d = 0;
    bool vis[5][5][5];
    
    LOOP (k, 5) {
        memcpy(vis[k], map2[k], sizeof(vis[0]));
    }

    queue<Pos> q;
    vis[0][0][0] = 0;
    q.push({ 0, 0, 0 });

    while (!q.empty()) {
        for (auto b = q.size(); b--;) {
            auto [k, r, c] = q.front();
            q.pop();

            if (k + r + c == 12) return d;

            LOOP (i, 6) {
                int dk = k + dx[i];
                int dr = r + dy[i];
                int dc = c + dz[i];

                if (OOB(dk, dr, dc) 
                    || !vis[dk][dr][dc]
                    ) continue;

                vis[dk][dr][dc] = 0;
                q.push({ dk, dr, dc });
            }
        }
        ++d;
    }

    return MAX;
}

void run2() {
    LOOP (i, 5) {
        map2[i] = map[i];
    }

    do {
        ans = min(bfs(), ans);
        if (ans == 12) {
            cout << "12";
            exit(0);
        }
    } while (next_permutation(ALL(map2)));
}

void rotate(bool (*map)[5]) {
    bool tmp[5][5];

    LOOP (r, 5) LOOP(c, 5) {
            tmp[c][4 - r] = map[r][c];
    }

    memcpy(map, tmp, sizeof(tmp));
}

void run(int n) {
    if (!n--) return run2();

    LOOP (_, 4) {
        run(n);
        rotate(map[n]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    LOOP (k, 5) LOOP (r, 5) LOOP (c, 5) {
        cin >> map[k][r][c];
    }

    run(5);
    cout << (ans == MAX ? -1 : ans);
}