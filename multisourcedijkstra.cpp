#include<bits/stdc++.h>
using namespace std;

/* Given a graph G = (V, E) with V vertices and E edges, and a vector of starting vertices source, find the shortest path
   from any vertex in source to all vertices.
 */

#define int long long
#define F first
#define S second
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>

const int INF = (int)1e18 + 7;
 
signed main() {
	int v = 6; // 6 vertices, numbered from 0 to v - 1
	int e = 7; // 7 edges
	vi source = {0, 1}; // starting vertices

	// in p.F moves, we can reach p.S
	vector<vpii> graph(v, vector<pii>());
	graph[0] = {{5, 5}, {4, 3}, {1, 1}};
	graph[1] = {{4, 4}, {3, 2}, {1, 0}};
	graph[2] = {{6, 3}, {3, 1}};
	graph[3] = {{6, 2}, {4, 0}};
	graph[4] = {{2, 5}, {4, 1}};
	graph[5] = {{5, 0}, {2, 4}};

	// copy

	auto dijkstra = [&](vi& source) -> vi {
		vi shortest(v, INF);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		for (int &i : source) {
			shortest[i] = 0;
			pq.push({0, i});
		}
		while (!pq.empty()) {
			pii cur = pq.top(); pq.pop();
			if (cur.F > shortest[cur.S]) continue;
			shortest[cur.S] = cur.F;
			for (pii& next : graph[cur.S]) {
				if (shortest[cur.S] + next.F < shortest[next.S]) {
					shortest[next.S] = shortest[cur.S] + next.F;
					pq.push({shortest[next.S], next.S});
				}
			}
		}
		return shortest;
	};

	// end copy

	vi shortest = dijkstra(source);
	for (int i : shortest) {
		cout << i << " ";
	}
	cout << "\n";
}
