class Solution {
    public int coinChange(int[] coins, int amount) {
        
        return recurse(coins, amount);
    }
    
    public static int recurse(int[] coins, int remain) {
        if (remain == 0) return 0;
        if (remain < 0) return -1;
        
        int min = Integer.MAX_VALUE;
        
        for (int coin : coins) {
            int count = recurse(coins, remain - coin);
            if (count == -1) continue;
            min = (count + 1 < min) ? count + 1 : min;
        }
        
        return (min != Integer.MAX_VALUE) ? min : -1;
    }
}
