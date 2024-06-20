class Solution {
public:
    bool possible(vector<int>&position,int m,int cap)
    {
        int i=0;
        while(i<position.size() and m)
        {
            int next_ind=lower_bound(position.begin()+i,position.end(),position[i]+cap)-position.begin();
            if(next_ind>position.size())break;
            else m--;
            i=next_ind;
        }
        // if(m<=0)
        // cout<<cap<<" ";
        return m<=0;   
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int least=1,high=position[n-1]-position[0],ans=0;
        while(least<=high)
        {
            int cap=(least+high)/2;
            if(possible(position,m,cap))
            {
                ans=max(ans,cap);
                least=cap+1;
            }
            else{
                high=cap-1;
            }
        }
        return ans;
    }
};