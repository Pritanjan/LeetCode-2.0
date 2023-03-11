//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> solveQueries(int n, int num, vector<int> &arr, vector<vector<int>> &c) {
        unordered_map<int,int> mp;
        vector<int> count(n); 
       
        for(int i=n-1; i>=0; i--) {
            mp[arr[i]]++;
            count[i] = mp[arr[i]];
        }
        vector<int> ans;
        for(auto q : c) {
            int l = q[0];
            int r = q[1];
            int freq = q[2];
            int cnt = 0;
            for(int i=l; i<=r; i++) {
                if(count[i] == freq) cnt++;
                
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends