//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long maxGcd(int n) {
        long long res = n;
        int cnt = 1;
        
        for(long long i=n-1; i>=2; i--){
            if(__gcd(res, i) == 1){
                res = res * i;
                cnt++;
            }
            if(cnt == 4) break;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends