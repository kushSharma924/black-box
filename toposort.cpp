#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = (int)1e18 + 7;

/* Topological sort: Given a DAG where an an edge from u to v means we need to process u before v,
 * generate a valid ordering that allows us to process every node.
 */

signed main() {

	//           0 
	//        /  |  \
	//       ↓   ↓   ↓
	//      1    2    3
	//    ↓ ↓   ↓ ↓   ↓ ↓
	//   4  5  6   7  8  9
	
	vector<vector<int>> graph = {
		{},
		{4, 5},
		{6, 7},
		{8, 9},
		{},
		{}, 
		{}, 
		{}, 
		{}, 
		{}
	};

	int n = graph.size();

	// copy

	map<int, int> indegree;

	for (vector<int> &v : graph) {
		for (int i : v) indegree[i]++;
	}

	vector<int> source;

	for (int i = 0; i < n; i++) if (indegree[i] == 0) source.push_back(i);

	auto topo_sort = [&](vector<int>& source) -> vector<int> {
		vector<int> ordering;
		queue<int> q; // note: change to priority_queue for lexicographically smallest ordering
		for (int i : source) {
			q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			ordering.push_back(cur);
			for (int i : graph[cur]) {
				indegree[i]--;
				if (indegree[i] == 0) q.push(i);
			}
		}
		return ordering;
	};

	// end copy

	vector<int> ans = topo_sort(source);
	for (int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}
