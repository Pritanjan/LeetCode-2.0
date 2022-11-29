//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int numoffbt(long long int arr[], int n){
        int a = 1e5 + 1;
        int mod = 1e9 + 7;
        vector<int> v(a, 0);
        long long int mx = INT_MIN;
        long long int mi = INT_MAX;
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            v[arr[i]] = 1;
            mx = max(mx, arr[i]);
            mi = min(mi, arr[i]);
        }
        
        for(int i=mi; i<=mx; i++){
            if(v[i] != 1 or v[i] == 0) continue;
            
            for(int j=mi; j*j<=i; j++){
                if(i % j == 0 and v[i/j] != 0 and v[j] != 0){
                    if(i/j != j) v[i] += 2 * (v[i/j] * v[j]);
                    else v[i] += v[j] * v[j];
                
                v[i] = v[i] % mod;
                }
                
            }
            ans += v[i];
            ans = ans % mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends