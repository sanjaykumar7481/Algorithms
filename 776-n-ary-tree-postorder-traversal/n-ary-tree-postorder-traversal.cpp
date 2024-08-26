/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void fun(Node *root,vector<int>&temp)
    {
        if(!root)return;
        for(auto i:root->children)
        {
            fun(i,temp);
        }
        temp.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>temp;
        fun(root,temp);
        return temp;
    }
};