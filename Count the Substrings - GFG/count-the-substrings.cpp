//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool isUpperCase(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    
    bool isLowerCase(char c) {
        return (c >= 'a' && c <= 'z');
    }
    
    int countSubstring(string s) {
        int n = s.length();
        int count = 0;
        int diff = 0;
        int freq[2*n + 1] = {0};
        freq[n] = 1;
        for (int i = 0; i < n; i++) {
            if (isUpperCase(s[i])) diff++;
            else diff--;
            
            int index = n + diff;
            count += freq[index];
            freq[index]++;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends