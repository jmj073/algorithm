#include <iostream>
#include <cstdint>
#include <queue>
#include <set>

#define loop(i, n) for (int i = 0, __n = (n); i < __n; ++i)

using namespace std;
using u32 = uint32_t;

constexpr int DELTA[]{ 1, -1, 11, -11 };

int N, M;
char map[10][11];
#define map2 ((char*)map)

u32 tilt(u32 cur, int delta) {
    if (map2[cur] == 'O') return cur;

    char color = map2[cur];
    map2[cur] = '.';

    while (true) {
        cur += delta;
        if (map2[cur] == 'O') {
            return cur;
        }
        if (map2[cur] != '.') {
            cur -= delta;
            break;
        }
    }

    map2[cur] = color;
    return cur;
}

int run() {
    queue<u32> q;
    set<u32> vis;

    u32 start{};

    loop (r, N) loop (c, M) {
        auto& cur = map[r][c];
        if (cur == 'R') {
            start |= r * 11 + c;
            cur = '.';
        } else if (cur == 'B') {
            start |= (r * 11 + c) << 16;
            cur = '.';
        }
    }

    vis.insert(start);
    q.push(start);

    auto breadth = q.size();
    int depth{};

    while (!q.empty()) {
        u32 cur = q.front();
        q.pop();
        u32 rcur = cur & 0xFFFF;
        u32 bcur = cur >> 16;

        for (auto delta: DELTA) {
            map2[rcur] = 'R';
            map2[bcur] = 'B';

            u32 rnxt = tilt(rcur, delta);
            u32 bnxt = tilt(bcur, delta);
                rnxt = tilt(rnxt, delta);

            if (map2[bnxt] != 'O') {
                if (map2[rnxt] == 'O') return depth + 1;

                u32 nxt = (bnxt << 16) | rnxt;

                if (!vis.count(nxt)) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }

            if (map2[bnxt] == 'B') map2[bnxt] = '.';
            if (map2[rnxt] == 'R') map2[rnxt] = '.';
        }

        if (!--breadth) {
            breadth = q.size();
            if (++depth > 9) break;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    loop (r, N) cin >> map[r];
    cout << run();
}