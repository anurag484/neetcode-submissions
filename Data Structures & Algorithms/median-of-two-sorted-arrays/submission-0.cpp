class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; // To store the merged sorted array
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        // Merge the two sorted arrays
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1 (if any)
        while (i < n) {
            ans.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2 (if any)
        while (j < m) {
            ans.push_back(nums2[j]);
            j++;
        }

        int size = n + m;

        // If the merged array has an odd size, return the middle element
        if (size % 2 == 1) {
            return ans[size / 2];
        }

        // If the merged array has an even size, return the average of the two middle elements
        return (double)(ans[size / 2] + ans[size / 2 - 1]) / 2.0;
    }
};
