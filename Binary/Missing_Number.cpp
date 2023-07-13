#include<iostream>

using namespace std;

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

class Solution {
public:
	int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
        	ans ^= nums[i];
        	ans ^= (i + 1);
        }
        return ans;
    }
};

void solve() {
	Solution *soln = new Solution();
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	cout << soln->missingNumber(nums);
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