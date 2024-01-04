class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<string, int>>> mp;
        int looper=1;
        for (auto num : nums) {
            int n = num.size();
            
            for (int i = n-1; i >= 0; i--) {
                mp[n-i].push_back(make_pair(num.substr(i), looper));
            }
            looper++;
        }
        for(auto& i : mp){
            sort(i.second.begin(),i.second.end());
        }
        vector<int> ans;
        for(auto query : queries){
           int a=query[0];
           int b=query[1];
           int c = mp[b][a-1].second;
           ans.push_back(c-1);
        }
        return ans;
    }
};
