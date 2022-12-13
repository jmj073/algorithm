/*
최장 증가 부분 수열(LIS, Longest Increasing Subsequence)와 비슷한 문제이다.

# BOJ

https://www.acmicpc.net/problem/11054

# Input Example

```in
10
1 5 2 1 4 3 4 5 2 1
```

```out
7
```
*/

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//#define ALL(c) begin(c), end(c)
//
//using namespace std;
//
//template <typename T>
//using RevIt = reverse_iterator<T>;
//
///* 수열 A의 크기 */
//#define N_MIN 1
//#define N_MAX 1'000
//
///* 입력 수열 A의 원소의 크기 */
//#define A_MIN 1
//#define A_MAX 1'000
//
///*
// * O(NlogN) 
// * 각 원소를 마지막으로 가지는 LIS의 길이를 반환. 
// */
//template <typename InIt, typename OutIt>
//size_t get_elis(InIt first, InIt last, OutIt dst) {
//	vector<decay<decltype(*first)>::type> d; // N_MAX
//
//	for (; first != last; ++first, ++dst) { // O(N)
//		size_t idx = lower_bound(ALL(d), *first) - begin(d); // O(logN)
//
//		if (idx == d.size()) {
//			d.push_back(*first);
//		} else {
//			d[idx] = *first;
//		}
//
//		*dst = idx + 1;
//	}
//
//	return d.size();
//}
//
//size_t solution1(const int* A, size_t N) {
//	vector<size_t> elis1(N_MAX); 
//	vector<size_t> elis2(N_MAX);
//	get_elis(A, A + N, elis1.begin());
//	get_elis(RevIt<const int*>(A + N), RevIt<const int*>(A), begin(elis2));
//
//	size_t max_v = 0;
//
//	for (size_t i = 0; i < N; ++i) {
//		max_v = max(max_v, elis1[i] + elis2[N - i - 1]);
//	}
//
//	return max_v - 1;
//}
//
///*
// * O(NlogN)
// * flis[index] = 처음으로 길이가 index + 1인 LIS를 가지는 원소의 인덱스
// */
//template <typename InIt>
//auto get_flis(InIt first, InIt last) {
//	vector<decay<decltype(*first)>::type> d; // N_MAX
//	vector<size_t> flis;
//
//	for (auto a = first; a != last; ++a) { // O(N)
//		size_t idx = lower_bound(ALL(d), *a) - begin(d); // O(logN)
//
//		if (idx == d.size()) {
//			d.push_back(*a);
//			flis.push_back(a - first);
//		} else {
//			d[idx] = *a;
//		}
//	}
//
//	return flis;
//}
//
//size_t solution2(const int* A, size_t N) {
//	auto flis1 = get_flis(A, A + N);
//	auto flis2 = get_flis(RevIt<const int*>(A + N), RevIt<const int*>(A));
//
//	size_t ans = 0, j = flis2.size() - 1;
//	for (size_t i = 0; i < flis1.size(); ++i) {
//		while (flis1[i] + flis2[j] >= N) --j;
//		ans = max(ans, i + j);
//	}
//
//	return ans + 1;
//}
//
//int main() {
//	size_t N = 10;
//	int A[N_MAX]{ 1, 5, 2, 1, 4, 3, 4, 5, 2, 1 };
//
//	cout << solution1(A, N) << '\n';
//	cout << solution2(A, N) << '\n';
//}