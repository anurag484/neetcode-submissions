class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int start = 0, currGas = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += gas[i] - cost[i];
            
            if (currGas < 0) { // If we run out of gas, reset the start index
                start = i + 1;
                currGas = 0; // Restart counting from next station
            }
        }
        
        return totalGas >= totalCost ? start : -1;
    }
};
