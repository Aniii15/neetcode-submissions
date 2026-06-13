class Solution {
public:
bool isPalindrome(string s) {
     vector<int> v1, v2;
    int s1, s2;
    s1 = 0;
    s2 = 0;
    if(s.size()<2){
        return true;
    }


    for (int i = 0; i<s.size()/2; i++){
        if (int (s[i] - 'a') < 26 && int (s[i] - 'a') >= 0){
            auto c1 = int (s[i] - 'a');
            v1.push_back(c1);
            s1++;
        }
        else if (int (s[i] - 'A') < 26 && int (s[i] - 'A') >= 0){
            auto c1 = int (s[i] - 'A');
            v1.push_back(c1);
            s1++;
        }
        else if (int (s[i] - '0') < 9 && int (s[i] - '0') >= 0){
            auto c1 = int (s[i] - '0');
            v1.push_back(c1);
            s1++;
        }
        continue;
    }

    for (int j = s.size()-1; j>=s.size()/2; j--){
        if (int (s[j] - 'a') < 26 && int (s[j] - 'a') >= 0){
            auto c2 = int (s[j] - 'a');
            v2.push_back(c2);
            s2++;
        }
        else if (int (s[j] - 'A') < 26 && int (s[j] - 'A') >= 0){
            auto c2 = int (s[j] - 'A');
            v2.push_back(c2);
            s2++;
        }
        else if (int (s[j] - '0') < 9 && int (s[j] - '0') >= 0){
            auto c2 = int (s[j] - '0');
            v2.push_back(c2);
            s2++;
        }
        continue;
    }

    for(int k = 0; k < min({s1, s2}); k++){
        //cout << v1[k] << " " << v2[k] << endl;
        if (v1[k] != v2[k]){
            return false;
        } 
    }
    return true;
      
}
};
