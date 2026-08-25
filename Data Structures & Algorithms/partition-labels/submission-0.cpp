class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26, 0);  // To store last occurrence of each character
        
        // Step 1: Store last index of each character
        for (int i = 0; i < s.size(); i++) {
            last_index[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0, end = 0;
        
        // Step 2: Traverse the string and create partitions
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_index[s[i] - 'a']);  // Extend partition if needed
            
            // If we reached the end of the partition, add its size to result
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;  // Move to next partition
            }
        }
        
        return result;
    }
};
