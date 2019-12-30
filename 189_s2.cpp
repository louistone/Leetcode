
// Author: Tong Xu
// Date: 12/30/2019

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if(nums.empty() || k <= 0) return;
        int count = 0, total = nums.size(), numToBeRotated = nums[0], tmp = 0, start = 0, cur = 0;

        while(count < total) {
            do {
                tmp  = nums[(k+cur)%total];
                nums[(k+cur)%total] = numToBeRotated;
                numToBeRotated = tmp;
                cur = (k+cur)%total;
                count++;
            } while(cur != start);

            if(count == total) break;
            start++;
            cur = start;
            numToBeRotated = nums[cur];
        }
    }
};
