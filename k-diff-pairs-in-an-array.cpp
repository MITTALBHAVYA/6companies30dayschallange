class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count = 0;
        for(auto i : mp){
            int pos = i.first + k;
            if(k!=0){
            if(mp.find(pos)!=mp.end()){
                count++;
            }
            }
            else{
                if(i.second>1){
                    count++;
                }
            }
        }
        return count;
    }
};