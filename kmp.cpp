#include <bits/stdc++.h>
using namespace std;

// copy

void KMP(string S, string s, vector<int>& v) {
    int n = S.length();
    int m = s.length();
    vector<int> p(m);
    p[0] = 0;

    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && S[i] != s[j])
            j = p[j - 1];
        if (S[i] == s[j]) {
            j++;
        }
        if (j == m) {
            v.push_back(i - m + 1);
            j = p[j - 1];
        }
    }
}

// end copy

int main() {
    // usage
    string S = "kush thinks kumpetitive programming is kuul";
    string s = "ku";
    vector<int> v;

    KMP(S, s, v); // text, pattern, vector

    for (int i : v) {
        cout << i << " "; // 0 12 39
    }
}
