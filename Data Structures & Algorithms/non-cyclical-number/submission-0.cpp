class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1){
            if(seen.count(n)){
                return false;
            }
            seen.insert(n);

            int sum=0;
            int temp=n;
            while(temp>0){
                int digit=temp%10;
                sum+=digit*digit;
                temp/=10;
            }
            n=sum;
        }
        return true;
    }
};
