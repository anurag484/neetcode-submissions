class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        for (int i = 0; i < n; i++) {
            if (gas[i] < cost[i]) continue; // If we can't even leave station i, skip it
            
            int j = (i + 1) % n; // Next station
            int currGas = gas[i] - cost[i]; // Remaining gas after leaving station i
            
            while (j != i) {
                if (currGas < 0) break; // If at any point gas is negative, break

                currGas += gas[j] - cost[j]; // Update remaining gas
                j = (j + 1) % n; // Move to next station
            }
            
            if (j == i && currGas >= 0) return i; // If we made a full circle, return start index
        }
        
        return -1; // No valid starting point found
    }
};
