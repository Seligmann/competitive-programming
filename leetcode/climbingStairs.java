class Solution {
    public int climbStairs(int n) {
        Map<Integer, Integer> steps = new HashMap<>();
        return countSteps(n, n, steps);
    }
    
    public static int countSteps(int i, int n, Map<Integer, Integer> steps) {
        // where do i land whne taking each decision from curr position
        for (int pos = i; pos >= 0; pos--) {
            if (pos == n) {
                steps.put(pos, 1);
            } else {
                if (steps.containsKey(pos + 2))
                    steps.put(pos, steps.get(pos + 1) + steps.get(pos + 2));
                else
                    steps.put(pos, steps.get(pos + 1));
            }
        }
        
        return steps.get(0);
    }
}
