//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int num1,int num2) {
    // Create a queue and add Num1 to it
    if(num1 == num2)
        return 0;
    std::queue<int> queue;
    queue.push(num1);
    std::unordered_set<int> visited{num1};  // Use a set to store visited numbers

    // Initialize the distance to 0
    int distance = 0;

    // BFS loop
    while (!queue.empty()) {
        // Increment the distance by 1
        distance++;

        // Iterate through the queue and change each digit of each number
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            int num = queue.front();
            queue.pop();
            for (int j = 0; j < 4; j++) {
                for (int d = 0; d <= 9; d++) {
                    // Skip the same digit
                    if (d == num / (int)pow(10, j) % 10) continue;

                    // Generate a new number by replacing the j-th digit
                    int new_num = num - (num / (int)pow(10, j) % 10) * (int)pow(10, j) + d * (int)pow(10, j);
                    if (new_num == num2) {
                        // Num2 found!
                        return distance;
                    }
                    if (visited.count(new_num)) {
                        // Skip visited numbers
                        continue;
                    }
                    if (is_prime(new_num) && new_num / 1000 > 0 && new_num / 10000 < 1) {
                        // Add the new number to the queue and mark it as visited
                        queue.push(new_num);
                        visited.insert(new_num);
                    }
                }
            }
        }
    }

    // Num2 not found
    return -1;
}

bool is_prime(int n) {
    for(int i = 2; i < n; i++)
        if(n % i == 0)
            return false;
    return true;
}
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends