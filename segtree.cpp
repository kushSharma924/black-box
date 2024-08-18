#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	vector<int> a = {1, 3, -2, 8, 7};
	vector<pair<int, int>> q = {
		{1, 5}, 
		{2, 4},
		{3, 3},
		{1, 2},
		{1, 3},
	};
	int n = a.size();

	// copy

	vector<int> tree(4 * n, 0);

	auto build = [&](int cur_node, int left, int right, auto&& build) -> void {
		if (left == right) tree[cur_node] = a[left];
		else {
			int mid = (left + right) / 2;
			build(2 * cur_node, left, mid, build);
			build(2 * cur_node + 1, mid + 1, right, build);
			tree[cur_node] = tree[cur_node * 2] + tree[cur_node * 2 + 1]; // OPP
		}
	};

	auto query = [&](int cur_node, int cur_left, int cur_right, int query_left, int query_right, auto&& query) -> int {
		if (query_left > query_right) return 0;
		if (cur_left == query_left && cur_right == query_right) return tree[cur_node];
		int mid = (cur_left + cur_right) / 2;
		return query(2 * cur_node, cur_left, mid, query_left, min(query_right, mid), query) + query(2 * cur_node + 1, mid + 1, cur_right, max(mid + 1, query_left), query_right, query); // OPP
	};

	auto update = [&](int cur_node, int cur_left, int cur_right, int index, int val, auto&& update) -> void {
		if (cur_left == cur_right) tree[cur_node] = val;
    	else {
    		int mid = (cur_left + cur_right) / 2;
    		if (index <= mid) update(2 * cur_node, cur_left, mid, index, val, update);
	    	else update(2 * cur_node + 1, mid + 1, cur_right, index, val, update);
			tree[cur_node] = tree[cur_node * 2] + tree[cur_node * 2 + 1]; // OPP
		}
	};

	build(1, 0, n - 1, build);

	// end copy

	update(1, 0, n - 1, 2, 2, update);

	for (pair<int, int>& p : q) {
		cout << query(1, 0, n - 1, p.first - 1, p.second - 1, query) << "\n";
	}
}
