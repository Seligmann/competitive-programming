class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // numOfBoxes, numOfUnitsPerBox
        int totalBoxes = 0;
        int totalUnits = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        
        for (int i = 0; i < boxTypes.size(); i++) {
            int count = min(boxTypes[i][0], truckSize);
            totalUnits += boxTypes[i][1] * count;
            truckSize -= count;
            
            if (truckSize <= 0) break;
        }
            
        return totalUnits;
    }
};
