//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int solve(int i, vector<int>& dp, vector<int>& arr) {
        if(i >= arr.size() || i < 0) return 1;
        if(dp[i] > 0) return dp[i];
        if(dp[i] == 0) return dp[i] = 2;
        dp[i] = 0;
        dp[i] = solve(i+arr[i], dp, arr);
        return dp[i];
    }

    int goodStones(int n,vector<int> &arr){
        vector<int>dp(n, -1);
        for(int i=0; i<n; i++){
            if(dp[i] == -1) solve(i, dp, arr);
        }

        int c = 0;
        for(int i=0; i<n; i++) if(dp[i] == 1) c++;
        return c;
    }   
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends