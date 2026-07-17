class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k_outer;

    KthLargest(int k, vector<int>& nums) {
        k_outer = k;

        for(int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k_outer) minHeap.pop();

        return minHeap.top();
    }
};
