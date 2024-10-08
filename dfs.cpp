#include<bits/stdc++.h>
using namespace std;

/* Given a graph G and a source node S, traverse the graph starting from S by going as deep into the 
   graph as possible and then backtracking.
 */

int main() {

	//           0 
	//        /  |   \
	//       /   |    \
	//      1    2     3
	//    / |   / \    | \ 
	//   4  5  6   7   8  9
	
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

	// copy
	
	vector<bool> visited(graph.size(), false);
	auto dfs = [&](int node, auto&& dfs) -> void {
		visited[node] = true;
		cout << node << " ";
		for (int i : graph[node]) {
			if (!visited[i]) {
				dfs(i, dfs);
			}
		}
		visited[node] = false;
	};

	// end copy

	//usage
	int S = 0;
	dfs(S, dfs); // 0 1 4 5 2 6 7 3 8 9
}
