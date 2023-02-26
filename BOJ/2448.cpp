#include <iostream>
#include <bitset>

using namespace std;

bitset<1024> map[1024];
const char* shape[]{ 
    "  *   ",
    " * *  ",
    "***** ",
};

void star(int n, int r, int c) {
    if (n == 1) {
        map[r].set(c);
        return;
    }

    n /= 2;
    star(n, r, c);
    star(n, r + n, c);
    star(n, r + n, c + n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    star(n /= 3, 0, 0);

    for (int r = 0; r < n; ++r) {
        for (int i = 0; i < 3; ++i) {
            for (int j = r; ++j < n;) cout << "   ";
            for (int c = 0; c <= r; ++c) {
                cout << (map[r].test(c) ? shape[i] : "      ");
            }
            for (int j = r; ++j < n;) cout << "   ";
            cout << '\n';
        }
    }
}