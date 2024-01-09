class Solution {
public:
//
    // Twisted Knapsack
    unordered_map<string,int>mp;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        string needString="";
        int minPrice = 0;
        for (int i = 0; i < needs.size(); ++i) {
            minPrice += needs[i] * price[i];
            needString+=char('0'+needs[i]);
        }
        needString+=char('0'+needs.size());
        if(mp.find(needString) != mp.end()){
            return mp[needString];
        }
        for (const auto &offer : special) {
            bool validOffer = true;

            for (int i = 0; i < needs.size(); ++i) {
                if (offer[i] > needs[i]) {
                    validOffer = false;
                    break;
                }
            }

            if (validOffer) {
                for (int i = 0; i < needs.size(); ++i) {
                    needs[i] -= offer[i]; // Altering the needs vector
                }
                minPrice = min(minPrice, offer.back() + shoppingOffers(price, special, needs));
                for (int i = 0; i < needs.size(); ++i) {
                    needs[i] += offer[i]; // Restoring the needs vector to its original state
                }
            }
        }

        return mp[needString]=minPrice;
    }
};
