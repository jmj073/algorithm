#include <iostream>
#include <algorithm>

using namespace std;

int K, arr[7], seq[12];

void rec(int m) {
    if (!m) {
        for (int i = 6; i--;)
            cout << seq[arr[i] - 1] << ' ';
        cout << '\n';
        return;
    }
    
    int i = arr[m--];
    while (i + m < K) {
        arr[m] = ++i;
        rec(m);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    
    while (1) {
        cin >> K;
        if (!K) break;
        for (int i = 0; i < K; ++i)
            cin >> seq[i];
        rec(6);
        cout << '\n';
    }
}