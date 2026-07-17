class KthLargest {
public:
    int k_out;
    vector<int> nums_out;

    KthLargest(int k, vector<int>& nums) {
        k_out = k;
        nums_out = nums;
    }


    int add(int val) {
        nums_out.push_back(val);
        sort(nums_out.begin(), nums_out.end());

        return nums_out[nums_out.size() - k_out];
        
    }

};
