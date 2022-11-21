//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>A){
	    int cnt = 0;
	    int n = A.size();
	    
	    for(int i=0; i<n; i++){
	        int a = 0, s = 0;
	        for(int j=0; j<i; j++){
	            if(A[i] > A[j])
	                a++;
	        }
	        
	        
	        for(int j=i+1; j<n; j++){
	            if(A[i] < A[j])
	                s++;
	        }
	        cnt += a*s;
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends