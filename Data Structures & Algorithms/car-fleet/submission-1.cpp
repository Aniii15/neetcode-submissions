class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> final;

        for (int i = 0; i < speed.size(); i++){
            final.push_back({position[i], speed[i]});
        }

        sort(final.begin(), final.end(), [](pair<int, int> a, pair<int, int> b){return a.first > b.first;});

        double bottleneck = 0;
        int count = 0;
        for(auto pr : final){
            double dist = target - pr.first;
            int spd = pr.second;
            double time = (dist/spd);
            if (time > bottleneck){
                count++;
                bottleneck = time;
            }
        }
        return count;
    }
};
