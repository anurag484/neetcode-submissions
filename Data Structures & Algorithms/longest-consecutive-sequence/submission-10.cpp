class Solution {
public:

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

        sort(nums.begin(),nums.end());
        int longest=0;
        int curr_cnt=0;
        int last_smaller=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(last_smaller==nums[i]-1){
                curr_cnt++;
                last_smaller=nums[i];
            }
            else if(nums[i]!=last_smaller){
                curr_cnt=1;
                last_smaller=nums[i];
            }
            longest=max(longest,curr_cnt);
        }
        return longest;
    }
};
