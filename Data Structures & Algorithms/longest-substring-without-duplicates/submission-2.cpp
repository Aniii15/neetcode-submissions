class Solution {
public:
int lengthOfLongestSubstring(string s) {
  
    if (s.size() < 1)
    {
        // cout << 0 << endl;
        return 0;
    }

    unordered_set<char> seen;

    int left, right;
    left = 0;
    right = 0;
    int ans = 1;

    while (left <= right && right < s.size())
    {
        if (!seen.count(s[right]))
        {
            seen.insert(s[right]);
            right++;
            ans = max(ans, right - left);
        }

        else
        {
            seen.erase(s[left]);
            left++;
        }
    }

    // cout << ans << endl;
    return ans;
}
};
