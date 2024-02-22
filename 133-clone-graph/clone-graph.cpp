/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<int,Node*>mp;
        Node *res=new Node(node->val);
        Node *result=res;
        queue<Node*>q;
        q.push(node);
        mp[node->val]=res;
        while(!q.empty())
        {
            auto top=q.front();
            res=mp[top->val];
            q.pop();
            for(auto i:top->neighbors)
            {
                if(mp.find(i->val)==mp.end()){
                    Node *nn=new Node(i->val);
                    mp[i->val]=nn;
                    q.push(i);
                    res->neighbors.push_back(nn);
                }
                else res->neighbors.push_back(mp[i->val]);
            }
            
        }
        return result;
    }
};