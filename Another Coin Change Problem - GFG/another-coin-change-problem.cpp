//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    bool makeChanges(int N, int K, int target, vector<int>& coins) {
        int v[1010][110] = {};

        function<int(int, int)> can = [&](int t, int k) -> int {
            if (v[t][k] != 0) return v[t][k];
            if (k == 0) return t ? -1 : 1;
            for (int i = 0; i < N; i++) {
                if (t >= coins[i] && can(t - coins[i], k - 1) == 1) {
                    return v[t][k] = 1;
                }
            }
            return v[t][k] = -1;
        };

        return can(target, K) == 1 ? true : false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends