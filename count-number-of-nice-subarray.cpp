class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>dp;
        int even=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even++;
            }
            else{
                dp.push_back(even);
                even=0;
            }
        }
        dp.push_back(even);
        int sum=0;
        int i=0;
        while(i+k < dp.size()){
            sum+=(dp[i]+1)*(dp[i+k]+1);
            i++;
        }
        return sum;
    }
};