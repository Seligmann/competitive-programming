class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        int currIdx = 0;
        string currStr;
        map<char, string> numPad;
        numPad.insert(pair<char, string>('2', "abc"));
        numPad.insert(pair<char, string>('3', "def"));
        numPad.insert(pair<char, string>('4', "ghi"));
        numPad.insert(pair<char, string>('5', "jkl"));
        numPad.insert(pair<char, string>('6', "mno"));
        numPad.insert(pair<char, string>('7', "pqrs"));
        numPad.insert(pair<char, string>('8', "tuv"));
        numPad.insert(pair<char, string>('9', "wxyz"));
        
        if (digits.size() == 0)
            return combinations;
        
        for (int i = 0; i < numPad[digits[currIdx]].size(); i++) {
            rec(combinations, 0, digits, currStr, numPad, numPad[digits[currIdx]][i]);
        }
        
        return combinations;
    }
    
    void rec(vector<string>& combinations, int currIdx, string& digits, string currStr, map<char, string>& numPad, char currChar) {
        currStr.push_back(currChar);
        
        if (currStr.size() == digits.size()) {
            combinations.push_back(currStr);
        } else if (currStr.size() < digits.size()) {
            // currStr.push_back(currChar);
            currIdx++;
            
            for (int i = 0; i < numPad[digits[currIdx]].size(); i++)
                rec(combinations, currIdx, digits, currStr, numPad, numPad[digits[currIdx]][i]);
        }
    }
};
