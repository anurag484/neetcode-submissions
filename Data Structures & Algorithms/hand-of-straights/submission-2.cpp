#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false; // must divide equally

        map<int, int> mp; // card -> frequency
        for (int card : hand) {
            mp[card]++;
        }

        while (!mp.empty()) {
            int start = mp.begin()->first; // smallest available card

            // Try to form group starting from 'start'
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (mp.find(card) == mp.end()) {
                    return false; // card missing, can't form group
                }
                mp[card]--;
                if (mp[card] == 0) {
                    mp.erase(card); // remove if no more left
                }
            }
        }

        return true;
    }
};
