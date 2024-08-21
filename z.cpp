#include<bits/stdc++.h>
using namespace std;

int main() {
	string S = "kush thinks kumpetitive programming is kuul";
	string s = "ku";

	// copy

	auto z = [&](string &text, string &pattern) -> vector<int> {
		string s = pattern + text;
		int n = s.size();
		int L = 0; int R = 0;
		vector<int> z_arr(n, 0); z_arr[0] = -1;
		for (int i = 1; i < n; i++) {
			if (i > R) {
				L = i; R = i;
				while (R < n && s[R - L] == s[R]) R++;
				R--;
				z_arr[i] = R - L + 1;
			}
			else {
				int K = i - L;
				if (z_arr[K] + i <= R) z_arr[i] = z_arr[K];
				else {
					L = i;
					while (R < n && s[R] == s[R - L]) R++;
					R--;
					z_arr[i] = R - L + 1;
				}
			}
		}
		return z_arr;
	};

	// end copy

	vector<int> z_arr = z(S, s);

	for (int i : z_arr) {
		cout << i << " ";
		// -1 0 2 0 0 0 0 0 0 0 0 1 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0
	}
}
