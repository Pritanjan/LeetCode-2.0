//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string removeBrackets(string Exp) {
        char expChars[Exp.length() + 1];
        strcpy(expChars, Exp.c_str());
        int n = strlen(expChars);
    
        int ans[n + 1];
        memset(ans, 1, sizeof(ans));
        int lastOperator[n + 1];
        int nextOperator[n + 1];
    
        int l = -1;
        for (int i = 0; i < n; i++) {
            lastOperator[i] = l;
            if (expChars[i] == '*' || expChars[i] == '+' || expChars[i] == '-' || expChars[i] == '/') {
                l = expChars[i];
            }
        }
        l = -1;
        for (int i = n - 1; i >= 0; i--) {
            nextOperator[i] = l;
            if (expChars[i] == '*' || expChars[i] == '+' || expChars[i] == '-' || expChars[i] == '/') {
                l = expChars[i];
            }
        }
    
        stack<int> st;
        int operatorSign[256];
        int operatorMap[256];
        memset(operatorSign, -1, sizeof(operatorSign));
        char operators[] = {'*', '+', '-', '/'};
    
        for (int p = 0; p < n; p++) {
            memset(operatorMap, 0, sizeof(operatorMap));
            for (char x : operators) {
                if (x == expChars[p]) {
                    operatorSign[x] = p;
                }
            }
            if (expChars[p] == '(') {
                st.push(p);
            } else if (expChars[p] == ')') {
                int i = st.top();
                st.pop();
                int j = p;
    
                int next = nextOperator[j];
                int last = lastOperator[i];
    
                for (char x : operators) {
                    if (operatorSign[x] >= i) {
                        operatorMap[x] = 1;
                    }
                }
    
                bool isValid = false;
                
                if (i > 0 && j + 1 < n && expChars[i - 1] == '(' && expChars[j + 1] == ')') {
                    isValid = true;
                }
                
                if (operatorMap['+'] == 0 && operatorMap['*'] == 0 && operatorMap['-'] == 0 && operatorMap['/'] == 0) {
                    isValid = true;
                }
                
                if (last == -1 && next == -1) {
                    isValid = true;
                }
                
                if (last == '/') {
                
                } else if (last == '-' && (operatorMap['+'] == 1 || operatorMap['-'] == 1)) {
                
                } else if (operatorMap['-'] == 0 && operatorMap['+'] == 0) {
                    isValid = true;
                } else {
                    if ((last == -1 || last == '+' || last == '-') && (next == -1 || next == '+' || next == '-')) {
                        isValid = true;
                    }
                }
    
                if (isValid) {
                    ans[i] = 0;
                    ans[j] = 0;
                }
            }
        }
    
        string res = "";
        for (int i = 0; i < n; i++) {
            if (ans[i] > 0) {
                res += expChars[i];
            }
        }
    
        return res;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string Exp;
        cin >> Exp;
        
        Solution ob;
        cout << ob.removeBrackets(Exp) << endl;
    }
    return 0; 
} 

// } Driver Code Ends