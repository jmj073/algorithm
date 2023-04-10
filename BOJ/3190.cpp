// 0: empty, 1: snake, 2: apple

#include <iostream>
#include <queue>

using namespace std;
struct Pos { int r, c; };

constexpr int dy[]{ -1, 0, 1, 0 };
constexpr int dx[]{ 0, 1, 0, -1 };

int N, K, L;
int map[100][100];

inline bool OOB(int r, int c) { return r < 0 || r >= N || c < 0 || c >= N; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    while (K--) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 2; // apple
    }

    cin >> L;

    int time{}, d = 1;
    queue<Pos> q;

    map[0][0] = 1;
    q.push({ 0, 0 });

    int x; char c;
    cin >> x >> c;

    while (1) {
        if (L && x <= time) {
            d = (d + (c == 'L' ? 3 : 1)) % 4;
            if (--L) cin >> x >> c;
        }

        auto [r, c] = q.back();
        r += dy[d], c += dx[d];

        ++time;
        if (OOB(r, c) || map[r][c] == 1) break;

        if (!map[r][c]) { // empty
            auto [r, c] = q.front();
            q.pop();
            map[r][c] = 0;
        }

        q.push({ r, c });
        map[r][c] = 1; // snake
    }

    cout << time;
}