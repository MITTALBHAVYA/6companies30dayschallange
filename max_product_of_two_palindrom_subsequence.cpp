class Solution {
public:
    bool check(string &s){
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    } 
    int maxProduct(string s) {
        int n=s.size();
        unordered_map<int,int>mp;
        for(int i=1;i<(1<<n);i++){
            string t;
            for(int j=0;j<n;j++){
                if(i&(1<<j))t.push_back(s[j]);
            }
            if(check(t))mp[i]=t.size();
        }
        int ans=0;
        for(auto& i : mp){
            for(auto& j : mp){
                if((i.first & j.first) == 0){
                    ans = max(ans,i.second * j.second);
                }
            }
        }
        return ans;
    }
};