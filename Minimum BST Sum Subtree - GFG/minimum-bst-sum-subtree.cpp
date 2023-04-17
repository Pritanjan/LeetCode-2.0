//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int minSubtreeSumBST(int target, Node *root) {
        int min_len = INT_MAX;
        helper(target, root, min_len);
        return min_len == INT_MAX ? -1 : min_len;
    }
    
private:
    void helper(int target, Node *node, int &min_len) {
        if (!node) return;
        if (isBST(node, INT_MIN, INT_MAX) && sum(node) == target) {
            int len = getLen(node);
            if (len < min_len) min_len = len;
        }
        helper(target, node->left, min_len);
        helper(target, node->right, min_len);
    }
    
    bool isBST(Node *node, int min_val, int max_val) {
        if (!node) return true;
        if (node->data < min_val || node->data > max_val) return false;
        return isBST(node->left, min_val, node->data - 1) &&
               isBST(node->right, node->data + 1, max_val);
    }
    
    int sum(Node *node) {
        if (!node) return 0;
        return node->data + sum(node->left) + sum(node->right);
    }
    
    int getLen(Node *node) {
        if (!node) return 0;
        return 1 + getLen(node->left) + getLen(node->right);
    }
};



//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends