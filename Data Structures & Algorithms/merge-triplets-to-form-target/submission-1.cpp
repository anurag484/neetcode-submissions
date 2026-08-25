class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found_x = false, found_y = false, found_z = false;

        for (auto &t : triplets) {
            // Ignore triplets that exceed target in any position
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;

            if (t[0] == target[0]) found_x = true;
            if (t[1] == target[1]) found_y = true;
            if (t[2] == target[2]) found_z = true;
        }

        return found_x && found_y && found_z;
    }
};
