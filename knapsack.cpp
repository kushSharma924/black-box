#include<bits/stdc++.h>
using namespace std;

/* Given N items, each with their own weight and profit values,
   find the maximum profit value you can obtain by putting
   the items into a bag with capacity W such that the bag does
   not overflow.
 */

int main() {
	vector<pair<int, int>> items = { // {weight, value}
		{10, 60},
		{20, 100},
		{30, 120},
	};
	int W = 50; // max weight

	// copy

	// items: {weight, value}, W: max weight
	auto knapsack = [&](vector<pair<int, int>> &items, int W) -> int {
		int N = items.size();

		// dp[i][j] is the maximum value using at most i items with a max weight of j
		vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

		for (int i = 0; i <= N; i++) {
			for (int w = 0; w <= W; w++) {
				if (i == 0 || w == 0) continue;
				if (items[i - 1].first > w) {
					dp[i][w] = dp[i - 1][w];
				}
				else {
					dp[i][w] = max(dp[i - 1][w], items[i - 1].second + dp[i - 1][w - items[i - 1].first]);
				}
			}
		}

		return dp[N][W];
	};

	// end copy
	
	cout << knapsack(items, 50) << "\n";
}