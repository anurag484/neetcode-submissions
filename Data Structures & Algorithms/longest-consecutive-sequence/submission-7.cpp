class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int el=it;
                while(st.find(el+1)!=st.end()){
                    count++;
                    el=el+1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};
