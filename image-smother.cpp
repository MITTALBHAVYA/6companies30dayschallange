class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<int> dirs = {-1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                int count = 0;
                
                for (int dx : dirs) {
                    for (int dy : dirs) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }
                int avg = sum / count;
                ans[i][j] = avg;
            }
        }
        return ans;
    }
};