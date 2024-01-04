//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n=S.size();
        string ans(n+1,'$');
        int start=1;
        for(int i=0;i<n+1;i++){
            if(i==n || S[i]=='I'){
                for(int j = i-1 ; j>=-1 ; j--){
                    ans[j+1]=char('0'+start);
                    start++;
                    if(j>=0 && S[j]=='I'){
                        break;
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends