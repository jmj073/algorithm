#include <iostream>
#include <algorithm>

using namespace std;

int L, C, gat;
char arr[17], seq[15], isgat[15];

void rec(int l, int i) {
    if (!l) {
        if (gat && L - gat > 1) {
            cout << arr;
        }
        return;
    }
    
    for (; i + l <= C; ++i) {
        gat += isgat[i];
        arr[L - l] = seq[i];
        rec(l - 1, i + 1);
        gat -= isgat[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; ++i) {
        cin >> seq[i];
    }

    sort(seq, seq + C);

    for (int i = 0; i < C; ++i) {
        switch (seq[i]) {
            case 'a': case 'e':
            case 'i': case 'o':
            case 'u': isgat[i] = 1;
        }
    }

    arr[L] = '\n';
    arr[L + 1] = '\0';

    rec(L, 0);
}