class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m){
            return false;
        }
        sort(s1.begin(),s1.end());
        for(int i=0;i<=m-n;i++){
            string substr=s2.substr(i,n);
            sort(substr.begin(),substr.end());
            if(s1==substr){
                return true;
            }
        }
        return false;
        /*
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
    */
}

};
