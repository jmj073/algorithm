/*

# reference

https://en.wikipedia.org/wiki/Breadth-first_search

*/

#include <iostream>
#include <queue>

using namespace std;

using E = vector<size_t>;
using Graph = vector<E>;

vector<size_t> BFS(const Graph& graph, size_t start) {
	vector<bool> visit(graph.size());
	vector<size_t> order;
	order.reserve(graph.size());

	queue<size_t> q;
	visit[start] = true;
	q.push(start);

	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		order.push_back(u);

		for (size_t v : graph[u]) {
			if (!visit[v]) {
				visit[v] = true;
				q.push(v);
			}
		}
	}

	return order;
}

int main() {
	Graph graph(12);

	graph[0].push_back(1);
	graph[0].push_back(2);
		graph[2].push_back(4);
			graph[4].push_back(8);
			graph[4].push_back(9);
		graph[1].push_back(5);
	graph[0].push_back(3);
		graph[3].push_back(6);
			graph[6].push_back(10);
			graph[6].push_back(11);
		graph[3].push_back(7);


	auto order = BFS(graph, 0);

	for (size_t u : order)
		cout << u + 1 << '\n';
}

/* BFS code snippets
 * 
 * 1. 2차원 
 */

#if 0 /* 2차원 */

struct Coord { size_t r, c; };
#define refa(arr, crd) ((arr)[(crd).r][(crd).c])

constexpr ptrdiff_t dr[]{ 1, 0, -1, 0 };
constexpr ptrdiff_t dc[]{ 0, 1, 0, -1 };

Coord bnd;

bool map[100][100];

void BFS(const Coord& start) {
	size_t depth{}, breadth{}, count{};

	queue<Coord> q;
	refa(map, start) = 0;
	q.push(start);
	++breadth;

	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		++count;

		for (size_t i = 0; i < size(dr); ++i) {
			Coord v = { u.r + dr[i], u.c + dc[i] };

			if (v.r < bnd.r && v.c < bnd.c && refa(map, v)) {
				refa(map, v) = 0;
				q.push(v);
			}
		}

		if (!--breadth) {
			breadth = q.size();
			++depth;
		}
	}
}

#endif /* 2차원 */