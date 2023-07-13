#include<iostream>

using namespace std;

// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for(int i = 1; i < n; i++) {
        	for(int j = 0; j < i; j++) {
        		if(nums[i] > nums[j]) {
        			dp[i] = max(dp[i], (1 + dp[j]));
        			maxLen = max(maxLen, dp[i]);
        		}
        	}
        }
        for(auto v : dp) cout << v << " ";
        cout << endl;
        return maxLen;
    }
};

void solve() {
	Solution *soln = new Solution();
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	cout << soln->lengthOfLIS(nums);
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