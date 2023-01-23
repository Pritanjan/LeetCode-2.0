//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string removePair(string s) {
        stack<char> stack; 
        for(char ch : s) {
            if(!stack.empty() && stack.top() == ch)  stack.pop();
            else stack.push(ch);
        }
        
        if (stack.empty()) return "-1";
        
        string st;
        while(!stack.empty()){
            st.push_back(stack.top());
            stack.pop();
        }
        
        reverse(st.begin(), st.end());
        
        return st;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends