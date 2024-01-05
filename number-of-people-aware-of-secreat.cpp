class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod= 1e9 + 7;
        vector<long long>dp(n+1);
        dp[1]=1;
        int spread=0;
        int final_remain=0;
        for(int i=2;i<=n;i++){
            spread = (spread + dp[max(i-delay,0)] - dp[max(i-forget,0)] + mod)%mod;
            dp[i]=spread;
        }
        for(int i = n-forget+1;i<=n;i++){
            final_remain = (final_remain + dp[i])%mod;
        }
        return final_remain;
    }
};