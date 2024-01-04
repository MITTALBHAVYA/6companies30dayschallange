class Solution {
public:
   static bool compareVectors(const vector<string>& v1, const vector<string>& v2) {
        if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        else{
            return v1[0] < v2[0];
        }
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(),access_times.end(),compareVectors);
        int n=access_times.size();
        vector<string>ans;
        unordered_map<string,int>input;
        for(int i=0;i<n-2;i++){
            if(access_times[i][0]==access_times[i+1][0] && access_times[i+1][0]==access_times[i+2][0]){
                int bottom=stoi(access_times[i][1]);
                int upper = bottom+100;
                if((stoi(access_times[i+1][1])>=bottom && stoi(access_times[i+1][1])<upper)&&(stoi(access_times[i+2][1])>=bottom && stoi(access_times[i+2][1])<upper)){
                    input[access_times[i][0]]++;
                }
            }
        }
        for(auto i:input){
            if(i.second>0){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};