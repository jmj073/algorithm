#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, K, R, C;
bool map[40][40];
bool sticker[10][10];

void rotate() {
    bool tmp[10][10];

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int rr = c, rc = R - r - 1;
            tmp[rr][rc] = sticker[r][c];
        }
    }

    memcpy(sticker, tmp, sizeof(tmp));
    swap(R, C);
}

bool valid(int n, int m) {
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (map[r + n][c + m] && sticker[r][c]) return false;
        }
    }

    return true;
}

void attach(int n, int m) {
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (sticker[r][c])
                map[r + n][c + m] = true;
        }
    }
}

void stick() {
    for (int ro = 0;;++ro) {
        
        for (int n = 0; n <= N - R; ++n) {
            for (int m = 0; m <= M - C; ++m) {
                if (valid(n, m)) {
                    attach(n, m);
                    return;
                }
            }
        }

        if (ro > 2) break;
        rotate();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;

    while (K--) {
        cin >> R >> C;

        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                cin >> sticker[r][c];
        
        stick();
    }

    int cnt = 0;
    for (int n = 0; n < N; ++n)
        for (int m = 0; m < M; ++m)
            cnt += map[n][m];
    
    cout << cnt;
}

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);

//     cin >> N >> M >> K;

//     while (K--) {
//         cin >> R >> C;

//         for (int r = 0; r < R; ++r)
//             for (int c = 0; c < C; ++c)
//                 cin >> sticker[r][c];
        
//         for (int i = 0; i < 4; ++i) {
//             rotate();
//             cout << "sticker================\n";
//             print_sticker();
//         }
//     }
// }