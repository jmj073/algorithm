// backtracking: N과 M(4) nHm
#include <iostream>

using namespace std;

int N, M, arr[9];

void rec(int m) {
    if (!m) {
        for (int i = M; i--;)
            cout << char(arr[i] + '0') << ' ';
        cout << '\n';
        return;
    }
    
    int i = arr[m--];
    while (i <= N) {
        arr[m] = i++;
        rec(m);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    arr[M] = 1;
    rec(M);
}