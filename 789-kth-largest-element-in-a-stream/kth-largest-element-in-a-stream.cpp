class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<k and i<nums.size();i++)pq.push(nums[i]);
        size=k;
    }
    int add(int val) {
        if(pq.empty() or pq.size()<size)
        {
            pq.push(val);
            return pq.top();
        }
        if(val<pq.top())return pq.top();
        pq.pop();
        pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */