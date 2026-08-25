class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }
    vector<int>s1_freq(26,0);
    vector<int>s2_freq(26,0);
    for(char ch:s1){
        s1_freq[ch-'a']++;
    }
    int i=0;
    int j=0;
    while(j<s2.length()){
        s2_freq[s2[j]-'a']++;
        if(j-i+1>s1.length()){
            s2_freq[s2[i]-'a']--;
            i++;
        }
        if(s1_freq==s2_freq){
            return true;
        }
        j++;
    }
    return false;
}

};
