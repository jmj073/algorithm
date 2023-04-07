//   1
// 3 0 2
//   4
//   5
// 동 서 북 남
//   3
// 2 o 1  
//   4

#include <iostream>

using namespace std;

constexpr int ro[][4]{
    { 0, 2, 5, 3 },
    { 3, 5, 2, 0 },
    { 0, 1, 5, 4 },
    { 4, 5, 1, 0 },
};
constexpr int dx[]{ 1, -1, 0, 0 };
constexpr int dy[]{ 0, 0, -1, 1 };

int map[20][20];
int dice[6];
int R, C, r, c, k;

inline bool OOB(int r, int c) { return r < 0 || r >= R || c < 0 || c >= C; }

bool run(int dir) {
    int dr = r + dy[dir], dc = c + dx[dir];
    if (OOB(dr, dc)) return false;
    r = dr, c = dc;

    auto arr = ro[dir];
    int first = dice[arr[0]];
    for (int i = 0; i < 3; ++i)
        dice[arr[i]] = dice[arr[i + 1]];
    dice[arr[3]] = first;

    auto& cur = map[r][c];
    
    if (cur) {
        dice[5] = cur;
        cur = 0;
    } else {
        cur = dice[5];
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C >> r >> c >> k;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> map[i][j];

    while (k--) {
        int dir; cin >> dir;
        if (run(dir - 1)) {
            cout << dice[0] << '\n';
        }
    }
}