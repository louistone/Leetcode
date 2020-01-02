// Author: Tong Xu
// Date: 1/1/2020
// straightforward solution

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size(), n = nums2.size();
        int total = m + n, count = 0, l = 0, r = 0, pre, cur = 0;

        while(count < total/2 + 1 && l < m && r < n) {
            pre = cur;
            if(nums1[l] <= nums2[r]) {
                cur = nums1[l++];
                if(++count == total/2 +1) { // bug write = rather than ==
                    if(total%2) return (double) cur;
                    return (double)(cur+pre)/2.0;
                }
            }
            else {
                cur = nums2[r++];
                if(++count == total/2 +1) {
                    if(total%2) return (double) cur;
                    return (double)(cur+pre)/2.0;
                }
            }
        }

        while(count < total/2 + 1 && l < m) {
            pre = cur;
            cur = nums1[l++];
            if(++count == total/2 +1) {
                if(total%2) return (double) cur;
                return (double)(cur+pre)/2.0;
            }
        }

        while(count < total/2 + 1 && r < n) {
            pre = cur;
            cur = nums2[r++];
            if(++count == total/2 +1) {
                if(total%2) return (double) cur;
                return (double)(cur+pre)/2.0;
            }
        }

        return 0.0;
    }
};
