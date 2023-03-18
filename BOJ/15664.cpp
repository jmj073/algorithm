// backtracking: N과 M(10)
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[9], _seq[9], cnt[8];
#define seq (_seq + 1)

void rec(int m) {
    if (!m) {
        for (int i = M; i--;)
            cout << seq[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    
    int i = arr[m] + !cnt[arr[m]];
    --m;
    while (i < N) {
        --cnt[i];
        arr[m] = i;
        rec(m);
        ++cnt[i++];
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
        ++cnt[s];
    }
    N = s + 1;

    rec(M);
}