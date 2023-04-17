#include <iostream>
#include <algorithm>

#define loop(i, b, e) for (decltype(b) i = (b), __e = (e); i < __e; ++i)

using namespace std;

// + - * /
int N, A[11], oper[4];
int _min = 1e9, _max = -1e9;

void run(int n, int a) {
    if (++n == N) {
        _min = min(_min, a);
        _max = max(_max, a);
        return;
    }

    loop (i, 0, 4) {
        auto& o = oper[i];
        if (!o) continue;
        int tmp = a;
        --o;

        switch (i) {
            case 0:
                tmp += A[n];
                break;
            case 1:
                tmp -= A[n];
                break;
            case 2:
                tmp *= A[n];
                break;
            case 3:
                tmp /= A[n];
                break;
        }

        run(n, tmp);

        ++o;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    
    loop (i, 0, N) cin >> A[i];
    loop (i, 0, 4) cin >> oper[i];

    run(0, A[0]);

    cout << _max << '\n' << _min;
}