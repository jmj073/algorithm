#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 20

using namespace std;
using Map = int[MAX][MAX];

int N, bmax;

void rotate(Map dst, Map src) {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            int rr = c, rc = N - r - 1;
            dst[rr][rc] = src[r][c];
        }
    }
}

void slide_line(int* line) {
    int prev = -1, flag = 0;
    for (int i = 0; i < N; ++i) {
        if (!line[i]) continue;
        int cur = line[i];
        line[i] = 0;

        if (flag && line[prev] == cur) {
            line[prev] *= 2;
            flag = 0;
        } else {
            line[++prev] = cur;
            flag = 1;
        }
    }
}

void slide(Map map) {
    for (int r = 0; r < N; ++r)
        slide_line(map[r]);
}

int max_blk(Map map) {
    int res = 0;
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
            res = max(res, map[r][c]);
    return res;
}

void run(int n, Map map) {
    if (!n) {
        bmax = max(bmax, max_blk(map));
        return;
    }

    Map tmp{};
    memcpy(tmp, map, sizeof(tmp));

    for (int i = 0; i < 4; ++i) {
        slide(tmp);
        run(n - 1, tmp);
        rotate(tmp, map);
        memcpy(map, tmp, sizeof(tmp));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    Map map;
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c)
        cin >> map[r][c];
    
    run(5, map);

    cout << bmax;
}