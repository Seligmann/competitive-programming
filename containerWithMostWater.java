class Solution {
    public int maxArea(int[] height) {
        int max = Integer.MIN_VALUE;
        
        int lo = 0;
        int hi = height.length - 1;
        int[] a = height.clone();
        Arrays.sort(a);
        int maxHeight = a[a.length - 1];
        
        // for (int i = 1; i < height.length - 1 && lo < hi; i++) {
        while (lo < hi) {
            int[] shorter = (height[lo] < height[hi]) ? new int[] {height[lo], lo, 0} : new int[]{height[hi], hi, 1};
            int area = shorter[0] * (Math.abs(lo - hi));
            
            if (area > max) {
                max = area;
                if (height[lo] == maxHeight && height[hi] == maxHeight)
                    break;
            }
            
            if (shorter[0] < maxHeight) {
                if (shorter[2] == 0)
                    lo++;
                else
                    hi--;
            } else {
                break;
            }

                
        }
        
        return max;
    }
}
