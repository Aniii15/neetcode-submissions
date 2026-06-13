class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) {
    // vector<int> temperatures = {30, 38, 30, 36, 35, 40, 28};

    stack<pair<int, int>> st;
    vector<int> result(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && st.top().first < temperatures[i])
        {
            result[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push({temperatures[i], i});
    }    
    return result;    
}
};
