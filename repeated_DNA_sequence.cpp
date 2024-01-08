class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       unordered_map<string,int>mp;
       vector<string>ans;
       int n=s.size();
       for(int i=0;i<n-9;i++){
           string str=s.substr(i,10);
           mp[str]++;
       }
       for(auto i : mp){
           if(i.second>1){
               ans.push_back(i.first);
           }
       }
       return ans;
    }
};