// backtracking: N과 M(7) nㅠm
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[8], seq[8];

void rec(int m) {
    if (!m--) {
        for (int i = M; i--;)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; ++i) {
        arr[m] = seq[i];
        rec(m);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> seq[i];

    sort(seq, seq + N);
    rec(M);
}