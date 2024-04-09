class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=tickets[k];
        for(int i=0;i<k;i++)
        {
         if(tickets[i]<=tickets[k])ans+=tickets[i]; 
         else ans+=tickets[k];
        }
        for(int i=k+1;i<tickets.size();i++)
        {
            if(tickets[i]<=tickets[k]-1)ans+=tickets[i];
            else ans+=tickets[k]-1;
        }
        return ans;
    }
};