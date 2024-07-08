class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int prev=0,sum=0;
        for(int i=0;i<n;i++){
            prev+=i*nums[i];
            sum+=nums[i];
        }
        int j = n-1;
        int curr=prev;
        for(int i=1;i<n;i++){
            prev = prev + sum-n*nums[j--];
            curr = max(prev,curr);
        }
        return curr;
    }
};