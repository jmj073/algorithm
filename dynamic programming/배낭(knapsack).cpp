/* 
 * reference: https://en.wikipedia.org/wiki/Knapsack_problem
 * BOJ: https://www.acmicpc.net/problem/12865
 */ 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <functional>
#include <span>

using namespace std;

struct Item {
	int w, v;
};

/* O(2^N) */
int solution1(int weight, const vector<Item>& items) {

	function<int(size_t, int)> m = 
	[&] (size_t n, int w) -> int {
		if (n == 0) return 0;
		if (w < items[n - 1].w) return m(n - 1, w);
		return max(m(n - 1, w), m(n - 1, w - items[n - 1].w) + items[n - 1].v);
	};

	return m(items.size(), weight);
}

/* O(NW) */
int solution2(int weight, const vector<Item>& items) {
	vector<int> d(weight + 1);

	for (auto i : items) {
		for (int w = weight; w >= i.w; --w)
			d[w] = max(d[w], d[w - i.w] + i.v);
	}

	return d[weight];
}

int main() {
	vector<Item> items{
		{6, 13},
		{4,  8},
		{3,  6},
		{5, 12},
	};

	cout << solution1(7, items) << '\n';
	cout << solution2(7, items) << '\n';
	
}