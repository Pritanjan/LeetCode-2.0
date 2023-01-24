//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int n = s.length();
        
        if(n == 0) return 0;
        else if(n%2 == 0 && s.substr(0, n/2) == s.substr(n/2, n/2)) return 1 + n/2;
        else return 1 + minOperation(s.substr(0, n-1));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends