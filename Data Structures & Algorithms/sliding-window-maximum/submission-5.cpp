class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
deque<int>dq;  // ✅ use deque here
int i = 0, j = 0;
int n = nums.size();

while(j < n) {
    // Remove all elements smaller than current from the back of deque
    while(!dq.empty() && dq.back() < nums[j]) {
        dq.pop_back();
    }

    dq.push_back(nums[j]);

    if(j - i + 1 == k) {
        ans.push_back(dq.front());

        // If the element at front of deque is going out of window
        if(dq.front() == nums[i]) {
            dq.pop_front();
        }
        i++;
    }
    j++;
}
return ans;

    }
};
