class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int>temp;
        int res=0;
        for(auto i:people)
        {
            if(i<limit)temp.push_back(i);
            else res++;
        }
        int j=temp.size()-1,i=0;
        sort(temp.begin(),temp.end());
        while(i<j)
        {
            if(temp[i]+temp[j]>limit)
            {
                // c++;
                res++;
                j--;
            }
            else
            {
                res++;
                i++;
                j--;
                // c=0;
            }
        }
        if(i==j and temp[i]<=limit)res++;
        return res;
    }
};