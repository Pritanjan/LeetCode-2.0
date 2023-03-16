//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    long long count = 0;
    long long start = 0, end = 0;
    
    while(end < n) {
        if(arr[end] == 0) {
            end++;
        }else{
            count += (end - start) * (end - start + 1) / 2;
            start = end + 1;
            end = start;
        }
    }
    
    if (arr[n-1] == 0) {
        count += (end - start) * (end - start + 1) / 2;
    }
    
    return count;
}



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends