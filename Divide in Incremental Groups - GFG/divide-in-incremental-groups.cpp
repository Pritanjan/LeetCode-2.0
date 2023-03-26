//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countWaystoDivide(int N, int K) {
        int dp[101][101][101];
        
        for (int j = 1; j <= N; j++) {
            dp[0][j][0] = 1;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 1; k <= K; k++) {
                    dp[i][j][k] = dp[i][j - 1][k];
                    if (j <= i) {
                        dp[i][j][k] += dp[i - j][j][k - 1];
                    }
                }
            }
        }
        return dp[N][N][K];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends