class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,start=0,mini=INT_MAX;
        unordered_map<char,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int count=mp.size();
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            while(count==0){
                if(mini>j-i+1){
                    mini=j-i+1;
                    start=i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return mini==INT_MAX?"":s.substr(start,mini);
    }
};
