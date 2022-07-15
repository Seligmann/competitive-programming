class Solution {
    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer> v = new ArrayList<>();
        v.add(nums[0]);
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > v.get(v.size() - 1))
                v.add(nums[i]);
            else {
                int min = binarySearch(v, nums, nums[i]);
                v.set(min, nums[i]);
            }
        }
        return v.size();
    }
    
    public static int binarySearch(ArrayList<Integer> v, int[] nums, int target) {
        int l = 0;
        int r = v.size() - 1;
        int m = (l + r) / 2;
        
        while (l < r) {
            m = (l + r) / 2;
            if (v.get(m) == target)
                return m;
            else {
                if (v.get(m) > target)
                    r = m;
                else
                    l = m + 1;
            }
        }
        
        return r;
    }
}
