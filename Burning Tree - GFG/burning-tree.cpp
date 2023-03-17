//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// 1. map parent to the child
// 2. find tgt
// 3.check node is visted or not

class Solution {
public:
    // Level order traversal
    Node* createParentMapping(Node* root, int tgt, map<Node*, Node*> &nodeToParent){
        Node* res = NULL;
        queue<Node*> que;
        que.push(root);
        nodeToParent[root] = NULL;
        
        while(!que.empty()){
            Node* front = que.front();
            que.pop();
            
            if(front -> data == tgt) res = front;
            
            if(front -> left) {
                nodeToParent[front -> left] = front;
                que.push(front -> left);
            }
            
            if(front -> right) {
                nodeToParent[front -> right] = front;
                que.push(front -> right);
            }
        }
        return res;
    }
    
    int burn(Node* root, map<Node*, Node*> &nodeToParent){
        map<Node*, bool> visited;
        
        queue<Node*> que;
        que.push(root);
        
        visited[root] = true;
        
        int cnt = 0;
        
        while(!que.empty()){
            
            bool flag = 0; // to check whether node is visited or not if visted then mark as true
            int n = que.size();
            for(int i=0; i<n; i++){
                // process neighouring nodes
                Node* front = que.front();
                que.pop();
                
                if(front -> left && !visited[front -> left]){
                    flag = 1;
                    que.push(front -> left);
                    visited[front -> left] = 1;
                }
                
                if(front -> right && !visited[front -> right]){
                    flag = 1;
                    que.push(front -> right);
                    visited[front -> right] = 1;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    que.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if(flag == 1){
                cnt++;
            }
        }
        return cnt;
    }
    
    int minTime(Node* root, int target) {
        
        map<Node*, Node*> mp; // nodeToParent
        Node* tgt = createParentMapping(root, target, mp);
        
        int res = burn(tgt, mp);
        
        return res;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends