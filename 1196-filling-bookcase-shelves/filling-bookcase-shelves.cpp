class Solution {
public:
    int fun(int i,vector<vector<int>>&books,int width,int height,int max_width,vector<vector<int>>&dp)
    {
        if(i>=books.size())return height;
        int a=INT_MAX,b;
        if(dp[i][width]!=-1)return dp[i][width];
        if(width+books[i][0]<=max_width)
        {
            a=fun(i+1,books,width+books[i][0],max(height,books[i][1]),max_width,dp);
        }
        b=height+fun(i+1,books,books[i][0],books[i][1],max_width,dp);
        return dp[i][width]=min(a,b);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>>dp(books.size(),vector<int>(1001,-1));
        return fun(0,books,0,0,shelfWidth,dp);
    }
};