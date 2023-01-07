//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        long cnt = 0;
        for(int i=0; i<n; i++){
            arr[i] = (arr[i] + k) % k ;
        }
        
        vector<long> v(k) ;
        // unordered_map<int, int> v;
        for(int j=0; j<n; j++){
            v[arr[j]]++;
        }
        
        for(int j=0; j<k; j++){
            cnt += (v[j] * (v[j] - 1))/2;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends