class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size()-1;        
        while (k>=0 && nums[k] == val) k--;
        for (int i = 0; i < k; i++) {
            if (nums[i] == val) {
                nums[i] = nums[k];
                k--;
                while (k>=0&&nums[k] == val) k--;
            }
        }
        return k+1;
    }
};