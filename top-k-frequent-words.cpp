class Solution {
public:
    static bool cmp(pair<string,int>&a,pair<string,int>&b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int>mp;
        for(auto word : words){
            mp[word]++;
        }
        vector<pair<string,int>>vect;
        for(auto i : mp){
            vect.push_back({i.first,i.second});
        }
        sort(vect.begin(),vect.end(),cmp);
        vector<string>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=vect[i].first;
        }
        return ans;
    }
};