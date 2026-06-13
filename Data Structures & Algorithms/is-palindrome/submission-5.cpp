class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";
        
        // Step 1: Extract all valid characters FIRST. 
        // This completely eliminates the "midpoint fallacy".
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c); // dumping them all in one place
            }
        }
        
        // Step 2: Now, the physical midpoint IS the logical midpoint.
        // We can safely split it exactly in half.
        int n = cleaned.size();
        for (int i = 0; i < n / 2; i++) {
            // Compare the left side to the mirrored right side
            if (cleaned[i] != cleaned[n - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
};