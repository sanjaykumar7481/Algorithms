class Solution {
    public int minMoves(int[] nums, int limit) {
        // Difference array to record changes in move counts.
        // Size is 2 * limit + 2 to accommodate the maximum sum (2*limit) and the R+1 index.
        int[] diff = new int[2 * limit + 2];
        int n = nums.length;

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            // Step 1: Default to 2 moves for all target sums [2, 2 * limit]
            // We increment at 2, and we don't strictly need to decrement at 2*limit+1
            // because our final loop only goes up to 2*limit.
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // Step 2: In the range [min(a, b) + 1, max(a, b) + limit], 
            // only 1 move is needed instead of 2. So we subtract 1 move.
            int minVal = Math.min(a, b);
            int maxVal = Math.max(a, b);

            diff[minVal + 1] -= 1;
            diff[maxVal + limit + 1] += 1;

            // Step 3: At the exact sum a + b, 0 moves are needed instead of 1.
            // So we subtract another 1 move at (a+b) and add it back at (a+b+1).
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int minMoves = n; // Maximum possible moves would be n
        int currentMoves = 0;

        // Step 4: Calculate prefix sum to find the minimum total moves
        for (int s = 2; s <= 2 * limit; s++) {
            currentMoves += diff[s];
            minMoves = Math.min(minMoves, currentMoves);
        }

        return minMoves;
    }
}