#include<iostream>

using namespace std;


// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.


class Solution {
public:
	int coinChangeHelper(vector<int> &coins, int amount, int numOfCoins, vector<long long int> &dp) {
		if (amount == 0) return 0; // Base Case
		if (dp[amount] != 0) return dp[amount];
		long long int ans = INT_MAX;
		for(int i = 0; i < numOfCoins; i++) {
			if (amount - coins[i] >= 0) {
				long long int subProblem = coinChangeHelper(coins, amount - coins[i], numOfCoins, dp);
				ans = min(ans, subProblem + 1);
			}
		}
		return dp[amount] = ans;
	}

	int coinChange(vector<int>& coins, int amount) {
		vector<long long int> dp(amount + 1);
		long long int result = coinChangeHelper(coins, amount, coins.size(), dp);
		if (result == INT_MAX) return -1;
		return result;
    }
};

void solve() {
	Solution *soln = new Solution();
	vector<int> coins = {1, 2, 5};
	cout << soln->coinChange(coins, 11);
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