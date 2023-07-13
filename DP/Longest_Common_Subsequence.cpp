#include<iostream>

using namespace std;


// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        vector<vector<int> > dp(l1 + 1, vector<int> (l2 + 1, 0));
        for(int i = 1; i <= l1; i++) {
        	for(int j = 1; j <= l2; j++) {
        		if (text1[i - 1] == text2[j - 1]) {
        			dp[i][j] = 1 + dp[i - 1][j - 1];
        		} else {
        			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        		}
        	}
        }
        return dp[l1][l2];
    }
};

void solve() {
	Solution *soln = new Solution();
	string s1, s2;
	cin >> s1 >> s2;
	cout << soln->longestCommonSubsequence(s1, s2);
	return;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	freopen("../error.txt", "w", stderr);
#endif	

	clock_t startTime = clock();

	int testCases = 1;
	// cin >> testCases;
	while(testCases--) solve();

	cerr << "Run Time : " << ((double)(clock() - startTime) / CLOCKS_PER_SEC);

	return 0;
}