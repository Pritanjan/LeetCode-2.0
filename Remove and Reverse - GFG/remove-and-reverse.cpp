//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    string removeReverse(string S) {
        unordered_map<char, int> map;
        int i=0, j=S.length()-1;
        bool rev = false;
        unordered_set<int> del;
        
        for(char ch : S){
            map[ch]++;
        }
        
        while(i<j){
            char first = S[i];
            char last = S[j];
            
            if(!rev){
                if(map[first] > 1){
                    map[first]--;
                    del.insert(i);
                    rev = !rev;
                }
                i++;
            } else {
                if(map[last] > 1){
                    map[last]--;
                    del.insert(j);
                    rev = !rev;
                }
                j--;
            }
        }
        
        string ans = "";
        for(i=0; i<S.length(); i++) if(!del.count(i)) ans += S[i];
        
        if(rev) reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends