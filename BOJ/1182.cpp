#include <iostream>

using namespace std;

int n, s, a[20], cnt;

void dfs(int i, int sum) {
    cnt += (sum + a[i] == s);
	if (++i != n)
        dfs(i, sum),
        dfs(i, sum + a[i - 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	dfs(0, 0);

	cout << cnt;
}