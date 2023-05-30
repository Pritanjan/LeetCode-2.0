//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
            int maxi=*max_element(arr,arr+n),freq=mp[maxi];
        for(int i=0;i<n;i++){
            if(mp[arr[i]]<freq){
                maxi=arr[i];
                freq=mp[arr[i]];
            }
            if(freq==mp[arr[i]]&&arr[i]>maxi)
                maxi=arr[i];
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends