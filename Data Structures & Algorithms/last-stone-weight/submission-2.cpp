class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0]; // edge case

        priority_queue<int> maxHeap;
        for(int stone : stones) maxHeap.push(stone); // create our pq

        while(maxHeap.top() != 0 && maxHeap.size() >= 2){
            int big = maxHeap.top();
            maxHeap.pop();
            int small = maxHeap.top();
            maxHeap.pop();

            if(small == 0) return big; // so we don't loop infinitely

            int new_guy = big - small;
            maxHeap.push(new_guy);

            maxHeap.push(0);
        }
        return 0;
    }
};
