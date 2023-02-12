//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char, int> cnt;
		    queue<int> q;
		    
		    string ans = "";
		    
		    for(int i=0; i<A.size(); i++){
		        char ch = A[i];
		        
		        //  incerement the count
		        cnt[ch]++;
		        
		        //  push into queue
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(cnt[q.front()] > 1) q.pop(); // repeating character
		            else {
		                ans += q.front();
		                break;
		            }
		        }
		        if(q.empty())
		            ans.push_back('#');
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends