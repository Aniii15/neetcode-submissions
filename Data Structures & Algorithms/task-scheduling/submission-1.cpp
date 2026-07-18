class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequencies using the fast array trick
        int freq[26] = {0};
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // Step 2: Push all active frequencies into a Max-Heap
        // We only care about the counts, not the actual letters!
        priority_queue<int> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push(freq[i]);
            }
        }

        // Step 3: The Waiting Room queue -> {remaining_count, available_time}
        queue<pair<int, int>> waitQueue;
        int time = 0; // Our CPU clock

        // Step 4: Simulate until ALL tasks are completely finished
        while (!maxHeap.empty() || !waitQueue.empty()) {
            time++; // The clock ticks forward 1 cycle

            // Try to process a task from the Heap
            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                
                count--; // We just executed it once
                
                // If the task still needs to be run again, send it to the waiting room
                if (count > 0) {
                    waitQueue.push({count, time + n});
                }
            }

            // Check if anyone in the waiting room is ready to rejoin the Heap
            if (!waitQueue.empty() && waitQueue.front().second == time) {
                maxHeap.push(waitQueue.front().first);
                waitQueue.pop();
            }
        }

        return time;
    }
};