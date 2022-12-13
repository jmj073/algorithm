/*
# reference

https://en.wikipedia.org/wiki/Longest_increasing_subsequence

# BOJ

https://www.acmicpc.net/problem/11053

# Input Example

```in
6
10 20 10 30 20 50
```

```out
4
```
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "util/util_print.h"

#define ALL(c) begin(c), end(c)

using namespace std;

/* 수열 A의 크기 */
#define N_MIN 1
#define N_MAX 1'000

/* 입력 수열 A의 항 */
#define A_MIN 1
#define A_MAX 1'000

/* O(N * A) */
int solution1(const int* A, int N) {
	int d[A_MAX + 1]{};

	for (int i = 0; i < N; i++) { // O(N)
		d[A[i]] = *max_element(d, d + A[i]) + 1; // O(A[i])
	}

	return *max_element(d, end(d)); // O(A_MAX)
}

/* O(N^2) */
int solution2(const int* A, int N) {
	int d[N_MAX];

	for (int i = 0; i < N; i++) { // O(N)
		int tmp = 0;

		for (int j = 0; j < i; j++) { // O(i)
			if (A[j] < A[i] && d[j] > tmp) {
				tmp = d[j];
			}
		}

		d[i] = tmp + 1;
	}

	return *max_element(d, d + N); // O(N)
}

/* O(NlogN) */
int solution3(const int* A, int N) {
	int d[N_MAX], L = 0;

	for (int i = 0; i < N; i++) { // O(N)
		int idx = lower_bound(d, d + L, A[i]) - d; // O(logN)
		L += (idx == L);
		d[idx] = A[i];
	}

	return L;
}

/*
 * O(NlogN)
 * 각 원소를 마지막으로 가지는 LIS의 길이를 반환.
 */
template <typename InIt, typename OutIt>
size_t get_elis(InIt first, InIt last, OutIt dst) {
	vector<decay<decltype(*first)>::type> d; // N_MAX

	for (; first != last; ++first, ++dst) { // O(N)
		size_t idx = lower_bound(ALL(d), *first) - begin(d); // O(logN)

		if (idx == d.size()) {
			d.push_back(*first);
		} else {
			d[idx] = *first;
		}

		*dst = idx + 1;
	}

	return d.size();
}

/* 
 * 크기 뿐만 아니라 LIS까지 반환한다.
 */
int solution4(const int* A, int N, int* LIS) {

	vector<size_t> pos(N);
	size_t L = get_elis(A, A + N, begin(pos));

	size_t tmp = L;
	for (int i = N; i-- > 0;) { // O(N)
		if (pos[i] == tmp) {
			LIS[--tmp] = A[i];
		}
	}

	return L;
}

int main() {
	int N = 6;
	int A[N_MAX]{ 10, 20, 10, 30, 20, 50 };

	cout << solution3(A, N) << '\n';

	int LIS[N_MAX];
	int L = solution4(A, N, LIS);

	cout << L << '\n';
	print_seq(LIS, LIS + L, ' ');
}