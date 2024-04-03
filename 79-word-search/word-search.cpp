class Solution {
public:
    bool fun(int i,int j,vector<vector<char>>&board,string &word,int k,vector<vector<int>>&vis)
    {
        if(k==word.size())return true;
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or vis[i][j] or board[i][j]!=word[k])return false;
        bool res=false;
        vis[i][j]=1;
        res=res or fun(i+1,j,board,word,k+1,vis);
        if(res)return res;
        res=res or fun(i,j+1,board,word,k+1,vis);
        if(res)return res;
        res=res or fun(i-1,j,board,word,k+1,vis);
        if(res)return res;
        res=res or fun(i,j-1,board,word,k+1,vis);
        vis[i][j]=0;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        vector<vector<int>>temp;
        bool res=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                temp=vis;
                if(board[i][j]==word[0])
                {
                    res=res or fun(i,j,board,word,0,temp);
                }
                if(res)return res;
            }
        }
        return res;
    }
};