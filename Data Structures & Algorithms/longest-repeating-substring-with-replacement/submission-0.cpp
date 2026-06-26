class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        vector<int> frequencies (26, 0);
        int m = 1;
        while(left <= right && right < s.size()){
            // alphabet to integer:
            int num = static_cast<int>(s[right]) - static_cast<int>('A');

            frequencies[num]++;

            int curr = *max_element(frequencies.begin(), frequencies.end());

            while(right-left-curr+1 > k){
                int num2 = static_cast<int>(s[left]) - static_cast<int>('A');
                frequencies[num2]--;
                left++;
            }
            m = max(m, right-left+1);

            right++;
        }

        return m;

    }
};
