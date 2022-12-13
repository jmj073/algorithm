/*
���� ���� �κ� ����(LIS, Longest Increasing Subsequence)�� ����� �����̴�.

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
///* ���� A�� ũ�� */
//#define N_MIN 1
//#define N_MAX 1'000
//
///* �Է� ���� A�� ������ ũ�� */
//#define A_MIN 1
//#define A_MAX 1'000
//
///*
// * O(NlogN) 
// * �� ���Ҹ� ���������� ������ LIS�� ���̸� ��ȯ. 
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
// * flis[index] = ó������ ���̰� index + 1�� LIS�� ������ ������ �ε���
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