class Solution {
public:
    bool solve(int index, string &A, unordered_set<string> &st,vector<int>&dp) {
    if (index >= A.size()) {
        return true;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    for (int i = index; i < A.size(); i++) {
        string temp = A.substr(index, i - index + 1);
        if (st.find(temp) != st.end() && solve(i + 1, A, st,dp)) {
            return dp[index]=true;
        }
    }

    return dp[index]=false;
}

int wordBreak(string A, vector<string> &B) {
    unordered_set<string> st;
    vector<int>dp(1101,-1);
    for (auto word : B) {
        st.insert(word);
    }

    return solve(0, A, st,dp);
}
};