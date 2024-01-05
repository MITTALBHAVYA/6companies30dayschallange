class Solution {
public:
    int mod=1e9 + 7;
    int solve(int start,int end,int k,vector<vector<int>>&dp){
        if(k==0){
            return start==end;
        }
        if(dp[999+start][k]!=-1){
            return dp[999+start][k];
        }
        int right=solve(start+1,end,k-1,dp);
        int left=solve(start-1,end,k-1,dp);
        return dp[999+start][k]=(right+left)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3000,vector<int>(k+1,-1));
        return solve(startPos,endPos,k,dp)%mod;
    }
};