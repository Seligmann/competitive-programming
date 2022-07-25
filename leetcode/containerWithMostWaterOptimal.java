class Solution {
    public int maxArea(int[] height) {
        
        int lo = 0;
        int hi = height.length - 1;
        int maxArea = Integer.MIN_VALUE;
        
        while (lo < hi) {
            int currArea = (hi - lo) * Math.min(height[lo], height[hi]);
                
            maxArea = (currArea > maxArea) ? currArea : maxArea;
            
            if (height[lo] <= height[hi])
                lo++;
            else
                hi--;
        }
        
        return maxArea;
    }
}
