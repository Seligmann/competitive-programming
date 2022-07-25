class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        double d = mass;
        
        for (int i = 0; i < asteroids.length; i++) {
            if (d < asteroids[i]) return false;
            else
                d += asteroids[i];
        }
        
        return true;
            
    }
}
