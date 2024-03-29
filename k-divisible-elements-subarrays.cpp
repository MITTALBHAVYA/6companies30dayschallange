class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            vector<int>temp;
            int count=0;
            for(int j=i;j>=0;j--){
                temp.push_back(nums[j]);
                if(nums[j]%p == 0){
                    count++;
                }
                if(count<=k){
                    ans.insert(temp);
                }
                else
                {
                    break;
                }
            }
        }
        return ans.size();
    }
};