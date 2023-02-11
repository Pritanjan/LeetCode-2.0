//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/


// celebraity knows noone -> every row element 0 
// celebratiy knows everyone -> all column 1 except diagonal element 

class Solution{
public:
    vector<int> nextSmallerElement(int* arr, int n){
        stack<int> stk;
        stk.push(-1);
        vector<int> res(n);

        for(auto i=n-1; i>=0; i--){
            int cur = arr[i];
        
            while(stk.top() != -1 && arr[stk.top()] >= cur) stk.pop();

            res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }

    vector<int> prevSmallerElement(int* arr, int n){
        stack<int> stk;
        stk.push(-1);
        vector<int> res(n);

        for(auto i=0; i<n; i++){
            int cur = arr[i];
        
            while(stk.top() != -1 && arr[stk.top()] >= cur) stk.pop();

            res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }

    int largestRectangleArea(int* h, int n) {
        vector<int> next(n);
        next = nextSmallerElement(h, n);

        vector<int> prev(n);
        prev = prevSmallerElement(h, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int L = h[i];
                        
            // when all element is equal 
            if(next[i] == -1) next[i] = n;

            int B = next[i] - prev[i] - 1;

            int newArea = L * B;
            area = max(area, newArea);
        }
        return area;
    }

    
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        // compute area for 1st row
        int area = largestRectangleArea(matrix[0], m);

        // compute area for rem row
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1) matrix[i][j] = matrix[i][j] + matrix[i-1][j];
                else  matrix[i][j] = 0;
            }
            area = max(area, largestRectangleArea( matrix[i], m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends