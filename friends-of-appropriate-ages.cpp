class Solution {
public:
    bool allowed(int x,int y){
        if(y <= 0.5*x + 7)return false;
        if(y > x)return false;
        if(y>100 && x<100)return false;
        return true;
    }
    int numFriendRequests(vector<int>& ages) {
        int ans=0;
        vector<int>freq(121,0);
        for(int age : ages){
            ++freq[age];
        }
        for(int i=0;i<121;i++){
            for(int j=0;j<121;j++){
                if(allowed(i,j)){
                    if(i!=j){
                        ans+=freq[i]*freq[j];
                    }
                    else{
                        ans+=freq[i]*(freq[i]-1);
                    }
                }
            }
        }
        return ans;
    }
};