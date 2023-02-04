//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
// class Solution{
// public:	
// 	// calculate the maximum sum with out adjacent
// 	int findMaxSum(int *arr, int n) {
// 	    // code here
// 	}
// };

class Solution {
public:
    int findMaxSum(int arr[], int n) {
        // code here
        if(n == 1)                              // if n==1 then there is nothing to compare
            return arr[0];  
        if(n>2)                                // the last third element can be added to last element only 
            arr[n-3] += arr[n-1];              // jumping three index from this point will cost it ArrayIndexOutOfBound
        for(int i=n-4;i>=0;i--)
        {
            arr[i] += max(arr[i+2] ,arr[i+3]); // Checking at each step for the more optimized jump
        }                                      // and storing it on the current array
        return max(arr[0], arr[1]);            // The answer can be available on any of the index 0th or 1st so return the maximum one.
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends