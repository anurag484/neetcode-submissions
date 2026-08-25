class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mp;
        for (int card : hand) mp[card]++;

        for (auto it = mp.begin(); it != mp.end(); ) {
            int curr = it->first;
            int count = it->second;
            if (count > 0) {
                for (int i = curr; i < curr + groupSize; i++) {
                    if (mp[i] < count) return false;
                    mp[i] -= count;
                    if (mp[i] == 0) mp.erase(i);
                }
            }
            it = mp.begin(); // Reset iterator after potential erasures
        }
        return true;
    }
};
