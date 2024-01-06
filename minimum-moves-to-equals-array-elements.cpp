class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=0;
        if(n%2==0){
            median = (n+1)/2;
        }
        else{
            median = n/2;
        }
        int sum=0;
        for(auto i : nums){
            sum+=abs(nums[median]-i);
        }
        return sum;
    }
};