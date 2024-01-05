class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            int value=ans[x][y];
            //up (x,y+1)
            if(y+1<m){
                if(ans[x][y+1]==-1){
                    ans[x][y+1]=value+1;
                    q.push({x,y+1});
                }
            }
            //down (x,y-1)
            if(y-1>=0){
                if(ans[x][y-1]==-1){
                    ans[x][y-1]=value+1;
                    q.push({x,y-1});
                }
            }
            //left(x-1,y)
            if(x-1>=0){
                if(ans[x-1][y]==-1){
                    ans[x-1][y]=value+1;
                    q.push({x-1,y});
                }
            }
            //right
            if(x+1<n){
                if(ans[x+1][y]==-1){
                    ans[x+1][y]=value+1;
                    q.push({x+1,y});
                }
            }

        }
        return ans;
    }
};