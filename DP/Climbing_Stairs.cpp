#include<iostream>

using namespace std;


// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0 || n == 1 || n == 2) return n;
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 2;
		for(int i = 2; i < n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
        return dp[n - 1]; 
    }	
	// int climbStairsHelper(int n, vector<int> &dp) {
	// 	if (n == 0 || n == 1 || n == 2) return n;
	// 	if (dp[n] != -1) return dp[n];
	// 	return dp[n] = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);
	// }

	// int climbStairs(int n) {
	// 	vector<int> dp(50, -1);
	// 	return climbStairsHelper(n, dp);		
    // }	
};

void solve() {
	Solution *soln = new Solution();
	int n; cin >> n;
	cout << soln->climbStairs(n);
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