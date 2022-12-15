//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
public:
    bool check(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum%2==0?true:false;
    }
   
    string BalancedString(int N) {
        string ans="";
        string repeat="abcdefghijklmnopqrstuvwxyz";
        int t=N/26;
        int n=N%26;
        
        for(int i=0;i<t;i++){
            ans+=repeat;
        }
        
        int s,e;
        if(n%2==0){
            s=n/2;
        }
        else{
            bool even=check(N);
            if(even) s=(n+1)/2;
            else s=(n-1)/2;
        }
        
        e=n-s;
        
        for(int i=0;i<s;i++){
            ans.push_back(repeat[i]);
        }
        
        for(int i=e;i>0;i--){
            ans.push_back(repeat[26-i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends