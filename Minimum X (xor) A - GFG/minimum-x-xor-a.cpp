//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int count=__builtin_popcount(b);
        int res=0;
        for(int bit=30;bit>=0 && count>0;bit--){
            if((a & (1 << bit))==0){  // if unset, continue
                continue;
            }
            res=res | (1 << bit);  // we set our bits where a's bit is set
            count--;
        }
        for(int i=0;i<=30 && count>0;i++){
            if((a & (1 << i))==0){ // check if bit is unset, we wanna place our remaining bits where bits are unset in a
                res=res | (1 << i);
                count--;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends