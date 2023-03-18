// backtracking: N과 M(8) nHm
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[9], seq[8];

void rec(int m) {
    if (!m) {
        for (int i = M; i--;)
            cout << seq[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    
    int i = arr[m--];
    while (i < N) {
        arr[m] = i++;
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