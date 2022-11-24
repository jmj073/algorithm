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

using namespace std;

/* 수열 A의 크기 */
#define N_MIN 1
#define N_MAX 1'000

/* 입력 수열 A */
#define A_MIN 1
#define A_MAX 1'000

/* O(N * A) */
int solution1(int* A, int N) {
	int d[A_MAX + 1]{};

	for (int i = 0; i < N; i++) { // O(N)
		d[A[i]] = *max_element(d, d + A[i]) + 1; // O(A[i])
	}

	return *max_element(d, end(d)); // O(A_MAX)
}

/* O(N^2) */
int solution2(int* A, int N) {
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
int solution3(int* A, int N) {
	int d[N_MAX], L = 0;

	for (int i = 0; i < N; i++) { // O(N)
		int idx = lower_bound(d, d + L, A[i]) - d; // O(logN)

		if (idx == L) {
			d[L++] = A[i];
		}

		d[idx] = A[i];
	}

	return L;
}

int main() {
	int N, A[A_MAX];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << solution1(A, N);
}