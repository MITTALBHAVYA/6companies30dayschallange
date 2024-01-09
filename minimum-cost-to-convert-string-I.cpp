class Solution {
public:
    const long long INF = INT_MAX;

    int minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26, vector<int>(26, INF));

        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        int cod_len = original.size();
        for (int i = 0; i < cod_len; i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] = min(cost[i],dist[original[i] - 'a'][changed[i] - 'a'] );
        }

        // Floyd Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                        
                    }
                }
            }
        }

        long long ans = 0ll;
        int n = source.size();
        for (int i = 0; i < n; i++) {
            long long cal = dist[source[i] - 'a'][target[i] - 'a'];
            if (cal == INF) {
                cout<<source[i]<<" "<<target[i]<<endl;
                return -1ll; // Return -1 immediately for unreachable characters
            } else {
                ans += (long long)cal;
            }
        }
        return ans;
    }
};