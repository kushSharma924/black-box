#include<bits/stdc++.h>
using namespace std;

/* Given 2 integers a and b, compute a ^ b mod 1000000007.
 */

int MOD = 1e9 + 7;

// copy

int binpow(int a, int b) {
	vector<int> e(31); // e[i] = a ^ (1 << i)
	e[0] = a;
	for (int i = 1; i <= 30; i++) e[i] = e[i - 1] * e[i - 1] % MOD;
	int ans = 1;
	for (int bit = 0; bit <= 30; bit++) {
		int val = (1 << bit);
		if (b & val) {
			ans *= e[bit]; ans %= MOD;
		}
	}
	return ans;
}

// end copy

int main() {
	//usage
	int a = 3;
	int b = 7;
	int ans = binpow(3, 7);
	cout << ans << "\n";
}