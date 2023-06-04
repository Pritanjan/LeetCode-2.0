//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string reverseEqn (string s) {
        string res = "";
        int n = s.length ();
        int i = n-1;
        stack<char> st;
        while (i >= 0) {
            if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
                while (!st.empty ()) {
                    res += st.top ();
                    st.pop ();
                }
                res += s[i];
            }
            else st.push (s[i]);
            i--;
        }
        
        while(!st.empty ()) {
            res += st.top ();
            st.pop ();
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends