class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd Warshall
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2)); // Using INT_MAX / 2 to avoid overflow
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for (auto edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int minCities = INT_MAX;
        int answer = -1;
        for (int i = 0; i < n; i++) {
            int citiesWithinThreshold = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    citiesWithinThreshold++;
                }
            }
            if (citiesWithinThreshold <= minCities) {
                minCities = citiesWithinThreshold;
                answer = i;
            }
        }
        return answer;
    }
};