class Solution {
    public int coinChange(int[] coins, int amount) {
        Map<Integer, Integer> m = new HashMap<>();
        return recurse(coins, amount, m);
    }
    
    public static int recurse(int[] coins, int remain, Map<Integer, Integer> m) {
        if (remain == 0) return 0;
        if (remain < 0) return -1;
        if (m.containsKey(remain)) return m.get(remain);
        
        int min = Integer.MAX_VALUE;
        
        for (int coin : coins) {
            int count = recurse(coins, remain - coin, m);
            if (count == -1) continue;
            min = (count + 1 < min) ? count + 1 : min;
        }
        
        min = (min != Integer.MAX_VALUE) ? min : -1;
        m.put(remain, min);
        return min;
    }
}
