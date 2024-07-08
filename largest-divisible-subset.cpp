class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1); 
        vector<int> hash(n, 1); 
        for (int i = 0; i < n; i++) {
            hash[i] = i; 
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }
        int ans = -1;
        int last_index = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > ans) {
                ans = dp[i];
                last_index = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[last_index]);
        while (hash[last_index] != last_index) {
            last_index = hash[last_index];
            temp.push_back(nums[last_index]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};