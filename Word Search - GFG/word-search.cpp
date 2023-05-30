//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool fun(int i,int j,int n,int m,int val,vector<vector<char>> boa,string word){
        
        if(val==word.size()-1) return 1;
        if(boa[i][j]=='*') return 0;
        bool a=0,b=0,c=0,d=0;
        char temp=boa[i][j];
        boa[i][j]='*';
        if(i+1<n && boa[i+1][j]==word[val+1]){
            a=fun(i+1,j,n,m,val+1,boa,word);
        }
        if(i-1>=0 && boa[i-1][j]==word[val+1]){
            b=fun(i-1,j,n,m,val+1,boa,word);
        }
        if(j+1<m && boa[i][j+1]==word[val+1]){
            c=fun(i,j+1,n,m,val+1,boa,word);
        }
        if(j-1>=0 && boa[i][j-1]==word[val+1]){
            d=fun(i,j-1,n,m,val+1,boa,word);
        }
        boa[i][j]=temp;
        return a || b || c || d;
        

    }
    bool isWordExist(vector<vector<char>>& boa, string word) {
        // Code here
        int n=boa.size();
        int m=boa[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(boa[i][j]==word[0] && fun(i,j,n,m,0,boa,word)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends