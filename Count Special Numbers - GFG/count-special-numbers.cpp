//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        int cnt = 0;
        unordered_map<int, int> mp;
        int maxx = INT_MIN;
        for(int i=0; i<N; i++) {
            maxx = max(maxx, arr[i]);
            mp[arr[i]]++;
        }
        
        for(int i=0; i<N; i++) {
            if(mp[arr[i]] > 1) {
                cnt++;
                continue;
            }
            
            for(int j=1; j<=arr[i]/2; j++) {
                if((arr[i] % j == 0) && mp[j] >= 1) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends