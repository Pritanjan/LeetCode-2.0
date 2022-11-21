//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	void f(vector<vector<int>> &ans, vector<int> &cur, int i, int n){
	    if(n == 0){
	        ans.push_back(cur);
	        return ;
	    }
	    
	    if(i < 1)
	        return;
	    
	    if(i <= n){
	        cur.push_back(i);
	        f(ans, cur, i, n-i);
	        cur.pop_back();
	        f(ans, cur, i-1, n);
	    }
	    else
	        f(ans, cur, i-1, n);
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        f(ans, cur, n, n);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends