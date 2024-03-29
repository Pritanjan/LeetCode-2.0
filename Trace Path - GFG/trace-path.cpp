//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code here
        int i=1, j=1;
        int L=1, R=1, U=1, D=1; 
        for(int k=0; k<s.size(); k++){
            if(s[k]=='L'){j--;}
            else if(s[k]=='R'){j++;}
            else if(s[k]=='U'){i--;}
            else{i++;}
            L = min(L, j);
            R = max(R, j);
            U = min(U, i);
            D = max(D, i);
        }
        int col = abs(R-L)+1;
        int row = abs(D-U)+1;
        if(row>n || col>m){return 0;}
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends