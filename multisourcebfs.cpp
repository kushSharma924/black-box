#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = (int)1e18 + 7;

signed main() {

	//           0 
	//        /  |  \
	//       /   |   \
	//      1    2    3
	//    / |   / \   | \
	//   4  5  6   7  8  9
	
	vector<vector<int>> graph = {
		{1, 2, 3},
		{0, 4, 5},
		{0, 6, 7},
		{0, 8, 9},
		{1},
		{1}, 
		{2}, 
		{2}, 
		{3}, 
		{3}
	};

	vector<int> source = {0, 2};

	// copy

	auto bfs = [&](vector<int>& source) -> vector<int> {
		vector<int> dist(graph.size(), INF);
		queue<int> q;
		for (int i : source) {
			dist[i] = 0;
			q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i : graph[cur]) {
				if (dist[i] == INF) {
					dist[i] = dist[cur] + 1;
					q.push(i);
				}
			}
		}
		return dist;
	};

	// end copy

	vector<int> ans = bfs(source);
	for (int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}
