class Solution {
public:
    int trap(vector<int>& height) {
        int max1=height[0],max2=INT_MIN,max1Index=0,res=0;
        vector<int>prefix(height.size());
        prefix[0]=height[0];
        for(int i=1;i<height.size();i++)prefix[i]=prefix[i-1]+height[i];
        for(int i=1;i<height.size();i++)
        {
            max2=max(max2,height[i]);
            if(max1<=max2)
            {
                res+=(max1*(i-max1Index-1)-(prefix[i-1]-prefix[max1Index]));
                max1=max2;
                max2=INT_MIN;
                max1Index=i;
            }
        }
        if(max1Index==height.size()-1)return res;
        int lastIndex=0;
        while(lastIndex<height.size()-1)
        {
            max2=INT_MIN;
            for(int i=height.size()-1;i>max1Index;i--)
            {
                if(max2<height[i])
                {
                    max2=height[i];
                    lastIndex=i;
                }
            }
            res+=(max2*(lastIndex-max1Index-1)-(prefix[lastIndex-1]-prefix[max1Index]));
            max1Index=lastIndex;
        }
        return res;   
    }
};