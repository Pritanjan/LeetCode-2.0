//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true;
        }
        return false;
    }
    char getVowel(vector<int>& arr){
        for(int i=0;i<26;i++){
            if(isVowel((char)(i+'a')) && arr[i] ){
                arr[i]--;
                return (char)(i+'a');
            }
        }
        return '0';
    }
    char getConsonants(vector<int>& arr){
        for(int i=0;i<26;i++){
            if(!isVowel((char)(i+'a')) && arr[i] ){
                arr[i]--;
                return (char)(i+'a');
            }
        }
        return '0';
    }
    
    string rearrange (string S, int N){
        vector<int> arr(26,0);
        
        int cntc = 0, cntv = 0;
        for(int i=0;i<N;i++){
            arr[S[i]-'a']++;
            if(isVowel(S[i])) 
				cntv++;
            else
				cntc++;
        }
        
        string ans = "";
        while(ans.size()!=N){
            if(ans.size()%2 ==0){
                if(cntv>=cntc){
                    char ch = getVowel(arr);
                    if(ch=='0') return "-1";
                    ans += ch;
                }
                else{
                    char ch = getConsonants(arr);
                    if(ch=='0') return "-1";
                    ans += ch;
                }
            }
            else{

                if(cntv >= cntc){
                    char ch = getConsonants(arr); 
                    if(ch=='0') return "-1";
                    ans+=ch;
                }
                else{
                    char ch = getVowel(arr);
                    if(ch=='0') return "-1";
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends