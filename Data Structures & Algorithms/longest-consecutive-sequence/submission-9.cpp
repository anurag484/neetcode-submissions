class Solution {
public:
    bool ls(int el,vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        // int longest=0;
        // unordered_set<int>st;
        // for(auto it:nums){
        //     st.insert(it);
        // }
        // for(auto it:st){
        //     if(st.find(it-1)==st.end()){
        //         int count=1;
        //         int el=it;
        //         while(st.find(el+1)!=st.end()){
        //             count++;
        //             el=el+1;
        //         }
        //         longest=max(longest,count);
        //     }
        // }
        // return longest;
                int n = nums.size();
        int longest = 0;

        for (int i = 0; i < n; i++) {
            int currentNum = nums[i];
            int count = 1;

            // Check next elements one by one
            while (ls(currentNum + 1, nums)) {
                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};
