class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Using vector as a stack for contiguous memory speed
        vector<int> st; 
        
        // Pass by const reference to avoid 10,000 memory copies
        for (const string& s : tokens) { 
            // If it's an operator (length 1 and not a digit)
            if (s.size() == 1 && !isdigit(s[0])) {
                int num2 = st.back(); st.pop_back();
                int num1 = st.back(); st.pop_back();
                
                if (s[0] == '+') st.push_back(num1 + num2);
                else if (s[0] == '-') st.push_back(num1 - num2);
                else if (s[0] == '*') st.push_back(num1 * num2);
                else if (s[0] == '/') st.push_back(num1 / num2);
            } 
            else {
                // It's a number
                st.push_back(stoi(s));
            }
        }
        
        return st.back();
    }
};