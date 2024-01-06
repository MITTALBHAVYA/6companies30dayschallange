class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        unordered_map<char, int> mp1, mp2;
        int matched = 0;
        
        for (int i = 0; i < n; i++) {
            mp1[secret[i]]++;
            mp2[guess[i]]++;
            if (secret[i] == guess[i]) {
                matched++;
            }
        }
        
        int similar_match = 0;
        for (auto i : mp1) {
            char ch = i.first;
            int a = i.second;
            int b = mp2[ch];
            similar_match += min(a, b);
        }
        
        similar_match -= matched;
        string Al = to_string(matched);
        string Bl = to_string(similar_match);
        string ans = Al + 'A' + Bl + 'B';
        return ans;
    }
};