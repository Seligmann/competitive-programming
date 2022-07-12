class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        
        return minCoinsToAmount(coins, amount);
    }
    
    public static int minCoinsToAmount(int[] coins, int amount) {
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, 0);
        for (int i = 1; i <= amount; i++) {
            m.put(i, amount + 1);
            List<Integer> l = new ArrayList<>();
            for (int j = 0; j < coins.length; j++) {
                if (i - coins[j] >= 0)
                    m.put(i, Math.min(m.get(i), 1 + m.get(i - coins[j])));
            }
        }
        
        
        if (m.get(amount) == amount + 1)
            return -1;
        else
            return m.get(amount);
    }
}
