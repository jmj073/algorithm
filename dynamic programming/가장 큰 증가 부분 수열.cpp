/*
# BOJ
 
https://www.acmicpc.net/problem/11055
 
# Input Example
 
```in
10
1 100 2 50 60 3 5 6 7 8
```
 
```out
113
```
*/

#include <iostream>
#include <algorithm>

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
		d[A[i]] = *max_element(d, d + A[i]) + A[i]; // O(A[i])
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

		d[i] = tmp + A[i];
	}

	return *max_element(d, d + N); // O(N)
}

int main() {
	int N, A[N_MAX];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << solution1(A, N);
}