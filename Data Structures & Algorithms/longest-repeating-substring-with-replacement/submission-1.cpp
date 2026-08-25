class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int longest=0;
        int i=0;
        int j=0;
        int maxf=0;
        int n=s.size();
        while(j<n){
            mp[s[j]]++;
            maxf=max(maxf,mp[s[j]]);

            while((j-i+1)-maxf>k){
                mp[s[i]]--;
                i++;
            }
            longest=max(longest,j-i+1);
            j++;
        }
        return longest;
    }
};
