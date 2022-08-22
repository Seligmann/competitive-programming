class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int curr = 0;
        int ret = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[nums.size() - 1] < nums.size()) {
                ret = nums[nums.size() - 1] + 1;
                break;
            }
            
            if (nums[i] != curr) {
                ret = curr;
                break;
            }
            curr++;
        }
        
        return ret;
    }
};
