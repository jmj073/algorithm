#include <iostream>
#include <algorithm>

#define loop(i, n) for (int i = 0, __n = (n); i < __n; ++i)
#define GET(b, n) (((b) >> (n)) & 3)

using namespace std;

// from https://github.com/taylorconor/tinytetris
// {r-1,c-1}{x0,y0}{x1,y1}{x2,y2}{x3,y3}
constexpr int block[7][4] = {
    { 431424, 598356, 0, 0 },
    { 427089, 615696, 0, 0 },
    { 348480, 0, 0, 0 },
    { 599636, 431376, 598336, 432192 },
    { 411985, 610832, 415808, 595540 },
    { 247872, 799248, 0, 0 },
    { 614928, 399424, 615744, 428369 },
};

int N, M;
int map[500][500];

int run(int b) {
    int ret = 0;

    loop (r, N - GET(b, 18)) {
        loop (c, M - GET(b, 16)) {
            int tmp = 0, bb = b;
            loop (_, 4) {
                tmp += map[r + GET(bb, 0)][c + GET(bb, 2)];
                bb >>= 4;
            }
            ret = max(ret, tmp);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    loop (r, N) loop (c, M) {
        cin >> map[r][c];
    }

    int ans = 0;

    for (auto& p: block) {
        for (auto b : p) {
            if (!b) break;
            ans = max(ans, run(b));
        }
    }

    cout << ans;
}