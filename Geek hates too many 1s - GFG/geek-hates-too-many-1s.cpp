//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int noConseBits(int n) {
        int sum = 0;
        for(int i=31,j=31;j>=0;j--){
            sum += (n & (1 << j)) ? 1 : 0;
            while(i-j+1 == 3){
                if(sum == 3) n &= (~(1<<j)), sum--;
                sum -= (n & (1 << i)) ? 1 : 0;
                i--;
            }
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends