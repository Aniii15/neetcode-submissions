class Solution {
public:
bool isPalindrome(string s) {
    
    string s2 = "";

    for (char c : s)
    {
        if (isalnum(c))
        {
            s2 += tolower(c);
        }
    }
    // cout << s2 << endl;

    int left = 0;
    int right = s2.size() - 1;

    while (left < right)
    {
        if (s2[left] == s2[right])
        {
            left++;
            right--;
        }
        else
        {
            return 0;
        }
    }
    return 1;        
}
};
