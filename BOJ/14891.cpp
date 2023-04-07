#include <iostream>
#include <cstdint>

using namespace std;
using u8 = uint8_t;

#define LR(n) (((n) << 1) | (((n) >> 7) & 1))
#define RR(n) (((n) >> 1) | (((n) & 1) << 7))

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    u8 gear[4]{};

    for (int i = 0; i < 4; ++i) {
        char buf[9]; cin >> buf;

        for (int j = 0; j < 8; ++j) {
            gear[i] |= (buf[j] & 1) << j; 
        }
    }

    int K; cin >> K;

    while (K--) {
        int n, d, f;
        cin >> n >> d;

        u8 can{};

        for (int i = 0; i < 4; ++i) {
            if (i == n-1) continue;
            if (i < n) {
                bool tmp = ((gear[i] >> 2) ^ (gear[i + 1] >> 6)) & 1;
                can = (tmp ? can | (1 << i) : 0);
            } else {
                bool tmp = ((gear[i - 1] >> 2) ^ (gear[i] >> 6)) & 1;
                if (tmp) can |= 1 << i;
                else break;
            }
        }
        
        d = (n & 1 ? d : -d);
        can |= 1 << (n - 1);

        for (int i = 0; i < 4; ++i) {
            if (can & 1) {
                gear[i] = (~d ? LR(gear[i]) : RR(gear[i]));
            }
            d = -d;
            can >>= 1;
        }

    }

    int ans{};
    for (int i = 0; i < 4; ++i)
        ans |= (gear[i] & 1) << i;
    
    cout << ans;
}

void print_bin(u8 a) {
    for (int i = 0; i < 8; ++i) {
        cout << char('0' + ((a >> i) & 1));
    }
}