class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        int count=0;
        int longest=0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1){
                count++;
            }
            if(count==j-i+1){
                longest=max(longest,j-i+1);
            }
            if(count<j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    count--;
                }
                i++;
            }
            j++;        
        }
        return longest;
    }
};
