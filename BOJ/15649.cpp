// backtracking
#include <iostream>

using namespace std;

// ========================================
#if 0

int N, M, arr[8], use[9];

void rec(int m) {
    if (!m--) {
        for (int i = M; i--;)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (!use[i]) {
            use[i] = 1;
            arr[m] = i;
            rec(m);
            use[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    rec(M);
}
#endif

// ========================================
#if 1
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M, arr[8]{}, use[9]{};
    cin >> N >> M;

    int m = 0;
    while (true) {
        if (m == M) {
            for (int i = 0; i < M; ++i)
                cout << arr[i] << ' ';
            cout << '\n';
            --m;
            continue;
        }

        use[arr[m]] = 0;
        while (++arr[m] <= N && use[arr[m]]);
        if (arr[m] > N) {
            arr[m--] = 0;
            if (m < 0) break;
        } else {
            use[arr[m++]] = 1;
        }
    }
}
#endif