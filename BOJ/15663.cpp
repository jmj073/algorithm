// backtracking: N과 M(9)
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[8], use[8], _seq[9];
#define seq (_seq + 1)

void rec(int m) {
    if (!m--) {
        for (int i = M; i--;)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (use[i]) {
            --use[i];
            arr[m] = seq[i];
            rec(m);
            ++use[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> seq[i];
    
    sort(seq, seq + N);
    int s = -1;
    for (int i = 0; i < N; i++) {
        if (seq[s] != seq[i])
            seq[++s] = seq[i];
        ++use[s];
    }
    N = s + 1;

    rec(M);
}