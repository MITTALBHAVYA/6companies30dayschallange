//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
      unordered_map<int,int>mp;
      int repeated = -1;
      long long sum=0;
      int required = -1;
      for(auto i : arr){
        mp[i]++;
        sum+=i;
      }
      for(int i=1;i<=n;i++){
          if(mp[i]==0){
              required=i;
          }
          if(mp[i]==2){
              repeated=i;
          }
          if(repeated!=-1 && required!=-1){
              break;
          }
      }
      return {repeated,required};
      // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends