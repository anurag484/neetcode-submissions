class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> mp;

        // if total cards cannot be divided into equal groups
        if (n % groupSize != 0) {
            return false;
        }

        // count frequency of each card
        for (auto it : hand) {
            mp[it]++;
        }

        // keep forming groups
        while (!mp.empty()) {
            int start = mp.begin()->first; // smallest available card

            // try to build a group of size groupSize starting from "start"
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                // if card is missing → can't form group
                if (mp.find(card) == mp.end()) {
                    return false;
                }

                // use one occurrence of this card
                mp[card]--;
                if (mp[card] == 0) {
                    mp.erase(card); // remove from map if count = 0
                }
            }
        }

        return true;
    }
};
