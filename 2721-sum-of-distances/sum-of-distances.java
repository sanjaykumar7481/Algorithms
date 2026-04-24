class Solution {
    static class Info {
        int count;          // Total occurrences
        long sum;           // Sum of all indices
        int currCount;      // Running prefix count
        long currSum;       // Running prefix sum
        
        public void addIndex(int idx) {
            count++;
            sum += idx;
        }
        
        public void updateCurr(int idx) {
            currCount++;
            currSum += idx;
        }
    }
    
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] result = new long[n];
        Map<Integer, Info> map = new HashMap<>();
        
        // Pass 1: Build total stats for each number
        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(nums[i], k -> new Info()).addIndex(i);
        }
        
        // Pass 2: Calculate distances using running prefix
        for (int i = 0; i < n; i++) {
            Info info = map.get(nums[i]);
            
            // Left contribution: elements before current index
            long left = (long)info.currCount * i - info.currSum;
            
            // Right contribution: elements after current index
            long right = (info.sum - info.currSum) 
                       - (long)(info.count - info.currCount) * i;
            
            result[i] = left + right;
            
            // Update running prefix for next occurrence
            info.updateCurr(i);
        }
        
        return result;
    }
}