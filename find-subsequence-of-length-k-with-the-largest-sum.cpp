class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>vect;
        for(int i=0;i<n;i++){
            vect.push_back({nums[i],i});
        }
        sort(vect.begin(),vect.end());
        vector<int>ans;
        for(int i = n-1;i>=n-k;i--){
            ans.push_back(vect[i].second);
        }
        sort(ans.begin(),ans.end());
        for(int j = 0;j<k;j++){
            ans[j]=nums[ans[j]];
        }
        return ans;
    }
};