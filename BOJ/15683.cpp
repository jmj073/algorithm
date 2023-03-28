#include <iostream>
#include <vector>

using namespace std;
struct Pos { int r, c; };
using Iter = vector<Pos>::iterator;

int R, C;
int map[8][8];
int min_cnt = 64;
vector<Pos> tv;
constexpr Pos delta[]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

inline bool OOB(int r, int c) { return r < 0 || c < 0 || r >= R || c >= C; }

inline void change(const Pos& o, const Pos& d, int a) {
    auto [r, c] = o;
    auto [dr, dc] = d;
    while (true) {
        r += dr, c += dc;
        auto& cur = map[r][c];
        if (OOB(r, c) || cur == 6) break;
        if (cur <= 0) cur += a;
    }
}

inline int get_cnt() {
    int cnt = 0;
    
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            cnt += !map[r][c];

    return cnt;
}

void run(Iter i) {
    if (i == end(tv)) {
        int cnt = get_cnt();
        min_cnt = min(min_cnt, cnt);
        return;
    }

    auto& o = *i++;
    auto [r, c] = o;

    switch (map[r][c]) {
        case 1:
            for (const auto& d: delta) {
                change(o, d, -1);
                run(i);
                change(o, d, 1);
            }
            break;
        case 2:
            for (int j = 0; j < 2; ++j) {
                change(o, delta[j], -1);
                change(o, delta[j + 2], -1);
                run(i);
                change(o, delta[j], 1);
                change(o, delta[j + 2], 1);
            }
            break;
        case 3:
            change(o, delta[0], -1);
            change(o, delta[1], -1);
            for (int j = 0; j < 3; ++j) {
                run(i);
                change(o, delta[j], 1);
                change(o, delta[j + 2 & 3], -1);
            }
            run(i);
            change(o, delta[0], 1);
            change(o, delta[3], 1);
            break;
        case 4:
            change(o, delta[1], -1);
            change(o, delta[2], -1);
            change(o, delta[3], -1);
            for (int j = 0; j < 3; ++j) {
                run(i);
                change(o, delta[j], -1);
                change(o, delta[j + 1], 1);
            }
            run(i);
            change(o, delta[0], 1);
            change(o, delta[1], 1);
            change(o, delta[2], 1);
            break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C;

    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            auto& tmp = map[r][c];
            cin >> tmp;
        }
    
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            auto& tmp = map[r][c];
            if (tmp <= 0 || tmp == 6) continue;

            Pos o = { r, c };
            if (tmp == 5) {
                for (const auto& d: delta)
                    change(o, d, -1);
            } else {
                tv.push_back(o);
            }
        }

    run(begin(tv));
    cout << min_cnt;
}