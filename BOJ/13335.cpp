/*
기본적으로 (다리 길이 + 버스 수)
*/

#include <iostream>
#include <queue>

using namespace std;
struct T { int l, w; };

// 트럭 수, 다리 길이, 최대 하중
int N, L, W;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> L >> W;

    int weight{}, len{}, ans{};
    queue<T> q;

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        weight += a;

        while (weight > W) {
            auto [l, w] = q.front();
            q.pop();
            len -= l;
            weight -= w;
        }

        if (len == L) {
            --len;
            auto& [l, w] = q.front();
            if (!--l) {
                weight -= w;
                q.pop();
            }
        }

        int l = L - len;
        int w = a;
        q.push({ l, w });

        ans += l;
        len = L;
    }

    cout << ans + 1;
}