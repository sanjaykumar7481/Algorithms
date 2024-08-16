class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi,mini;
        int fmin=1e9,smin=1e9,fmax=-1e9,smax=-1e9;
        for(int i=0;i<arrays.size();i++)
        {
            if(fmin>arrays[i][0])
            {
                smin=fmin;
                fmin=arrays[i][0];
                mini=i;
            }
            else if(smin>arrays[i][0])smin=arrays[i][0];
            int n=arrays[i].size();
            if(fmax<arrays[i][n-1])
            {
                smax=fmax;
                fmax=arrays[i][n-1];
                maxi=i;
            }
            else if(arrays[i][n-1]>smax)smax=arrays[i][n-1];
        }
//         cout<<fmin<<" "<<fmax<<endl;
//         cout<<smin<<" "<<smax<<endl;
        if(maxi!=mini)return fmax-fmin;
        if(smin==1e9 or smax==-1e9)return fmax-fmin;
        else return max( fmax-smin,smax-fmin);
    }
};