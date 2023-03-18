#if 0
#include <iostream>

using namespace std;

int N, cnt;

void queen(int n, int r, int l, int c) {
    int use = r | l | c;
    for (int a = 1; a <= ~use; a <<= 1) {
        if (use & a) continue;
        if (n == 1) { cnt++; break; }
        queen(n - 1, (r | a) << 1, (l | a) >> 1, c | a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    queen(N, 0, 0, ~((1 << N) - 1)); 
    cout << cnt;
}

#endif

#if 1 /* c++20 */

#include <iostream>
#include <bit>

using namespace std;

int N, cnt;

void queen(int n, int r, int l, int c) {
    int use = r | l | c, a = 1;
    while (~use) {
        if (!(use & 1)) {
            if (n != 1) queen(n - 1, (r | a) << 1, (l | a) >> 1, c | a);
            else ++cnt;
        }
        auto d = countr_one(unsigned(use >>= 1));
        a <<= d + 1, use >>= d;
    }
}

int main() {
    cin >> N;
    queen(N, 0, 0, ~((1 << N) - 1)); 
    cout << cnt;
}

#endif