#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct Pos { size_t r, c; };
using Q = queue<Pos>;

constexpr int dx[]{ 1, -1, 0, 0 };
constexpr int dy[]{ 0, 0, 1, -1 };

size_t N, M, G, R;
char map[50][50];
int dis[50][50];
Pos bro[10];
size_t bro_sz;

inline bool OOB(size_t r, size_t c) { return r >= N || c >= M; }

int bfs(Q&& q) {
    int cnt{};
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        auto& cur = dis[r][c];
        if (cur == 1 << 15) continue;
        int dd = cur + (cur > 0 ? 1 : -1);

        for (int i = 0; i < 4; ++i) {
            size_t dr = r + dx[i], dc = c + dy[i];
            if (OOB(dr, dc) || !map[dr][dc]) continue;
            auto& nxt = dis[dr][dc];
            if (!nxt) {
                q.push({ dr, dc });
                nxt = dd;
            } else if (dd == -nxt) {
                ++cnt;
                nxt = 1 << 15;
            }
        }
    }

    return cnt;
}

int run(int* kind) {
    int cnt{};

    for (size_t r = 0; r < N; ++r)
        fill(dis[r], dis[r] + M, 0);

    Q q;

    for (int i = 0; i < bro_sz; ++i) {
        if (kind[i]) {
            q.push(bro[i]);
            auto [r, c] = bro[i];
            dis[r][c] = kind[i];
        }
    }

    return bfs(move(q));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> G >> R;

    for (size_t r = 0; r < N; ++r) {
        for (size_t c = 0; c < M; ++c) {
            cin >> map[r][c];
            map[r][c] -= '0';
            if (map[r][c] == 2)
                bro[bro_sz++] = { r, c };
        }
    }

    int kind[10]{};
    int cnt{};
    auto knd = kind + bro_sz;

    fill(kind, kind + G, -1); // GREEN
    fill(knd - R, knd, 1); // RED

    do {
        cnt = max(cnt, run(kind));
    } while (next_permutation(kind, knd));

    cout << cnt;
}