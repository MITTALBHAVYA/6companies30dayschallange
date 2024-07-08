class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>dictSet;
        int n = s.size();
        for(auto word : dictionary){
            dictSet.insert(word);
        }
        vector<int>dp(n+1);
        for(int right = 1;right<=n;right++){
            dp[right]=1+dp[right-1];
            for(int left=right;left>0;left--){
                string word = s.substr(left-1,right-left+1);
                if(dictSet.count(word)){
                    dp[right]=min(dp[right],dp[left-1]);
                }
            }
        }
        return dp[n];
    }
};