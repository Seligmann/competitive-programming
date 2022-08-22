class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        
        for (int i = 0; i < n + 1; i++) {
            int count = 0;
            int val = i;
            
            while (val) {
                count += val & 1; // if bs contains a 1 bit, count
                val = val >> 1;
            }
            
            ret[i] = count;
        }
        
        return ret;
    }
};
