//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &A, int n ) {
        //code here
        unordered_map<int, int> ump;
        int sum = 0;
        int ans = 0;
        ump[sum] = 1;
        
        for(int i=0; i<n; i++){
            sum += A[i];
            if (ump.find(sum - 0) != ump.end()) {
                ans += ump[sum - 0];
            }
            ump[sum]++;
        }
        return ans; 
    }
};



//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends