// backtracking: N과 M(2) nCm
#include <iostream>

using namespace std;

int N, M, arr[9];

void rec(int m) {
    if (!m--) {
        for (int i = M; i--;)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    int i = arr[m + 1];
    while (i + m < N) {
        arr[m] = ++i;
        rec(m);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    rec(M);
}