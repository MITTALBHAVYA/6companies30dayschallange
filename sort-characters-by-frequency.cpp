class Solution {
public:
    static bool cmp(pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }
        vector<pair<char,int>>vect;
        for(auto i : mp){
            vect.push_back({i.first,i.second});
        }
        sort(vect.begin(),vect.end(),cmp);
        string ans="";
        for(auto i : vect){
            for(int j = 0; j < i.second; j++){
                ans+=i.first;
            }
        }
        return ans;
    }
};