/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool valid(int a,int b,vector<vector<int>>&res)
    {
        if(a<0 or b<0 or a>=res.size() or b>=res[0].size() or res[a][b]!=-1)return false;
        return true;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int p=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty() and head)
        {
            auto a=q.front();
            int x=a.first,y=a.second;
            q.pop();
            res[x][y]=head->val;
            head=head->next;
            if(!valid(x+dir[p][0], y+dir[p][1],res))  p=(p+1)%4;
            if(valid(x+dir[p][0], y+dir[p][1],res))
                q.push({x+dir[p][0],y+dir[p][1]});
            
        }
        return res;
    }
};