class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int longest=0;
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int ele=it;
                while(st.find(ele+1)!=st.end()){
                    cnt+=1;
                    ele=ele+1;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};
