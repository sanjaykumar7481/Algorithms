class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>arr(201,0);
        for(auto i:nums)
        {
            if(i>=0)arr[i]++;
            else arr[abs(i)+100]++;
        }
//         sort(nums.begin(), nums.end(), [&](int &a, int &b) {
//         int fa = (a >= 0) ? arr[a] : arr[abs(a) + 100];
//         int fb = (b >= 0) ? arr[b] : arr[abs(b) + 100];
        
//         if (fa != fb) return fa < fb;
        
//         // If frequencies are the same, sort by value (negative numbers first)
//         int ta = (a >= 0) ? a : -abs(a);
//         int tb = (b >= 0) ? b : -abs(b);
//         return ta > tb;
//     });
        sort(nums.begin(),nums.end(), [&](int &a,int &b){
            // cout<<a<<" "<<b<<endl;
            // if(a==b)return true; 
            int fa=a<0?arr[abs(a)+100]:arr[a];
            int fb=b<0?arr[abs(b)+100]:arr[b];
            if(fa<fb)return true;
            else if(fa==fb)return a>b;
            return false;
        });
        return nums;
    }
};