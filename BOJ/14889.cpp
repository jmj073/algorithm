#include <iostream>
#include <cmath>

#define loop(i, b, e) for (decltype(b) i = (b), __e = (e); i < __e; ++i)

using namespace std;

int N, S[20][20], ans = 1e9;
bool sel[20];

void run(int n, int i) {
    if (!n--) {
        int tmp{};

        loop (i, 0, N) loop (j, 0, N) {
            if (sel[i]) {
                if (sel[j]) tmp += S[i][j];
            } else if (!sel[j]) {
                tmp -= S[i][j];
            }
        }

        ans = min(ans, abs(tmp));
        return;
    }

    while (i + n < N) {
        sel[i] = 1;
        run(n, i + 1);
        sel[i++] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    loop (i, 0, N) loop (j, 0, N) {
        cin >> S[i][j];
    }

    run(N / 2, 0);
    cout << ans;
}