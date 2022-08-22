class Solution {
public:
    int getSum(int a, int b) {
        int power = 0;
        
        while (b && power != 32) {
            a += (b & 1) << power;
            power++;
            b >>= 1;
        }
        
        return a;
    }
};
