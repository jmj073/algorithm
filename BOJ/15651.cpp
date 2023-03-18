// backtracking: N과 M(3) nㅠm
#include <iostream>

using namespace std;

int N, M, arr[8];

void rec(int m) {
    if (!m--) {
        for (int i = M; i--;)
            cout << char(arr[i] + '0') << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i) {
        arr[m] = i;
        rec(m);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    rec(M);
}