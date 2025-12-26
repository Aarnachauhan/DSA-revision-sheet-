lc 268
public int missingNumber(int[] nums) { //xor
    int res = nums.length;
    for(int i=0; i<nums.length; i++){
        res ^= i;
        res ^= nums[i];
    }
    return res;
}

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int nsum=0;
        for(int i=0;i<n;i++){
            nsum+=nums[i];
        }
        return sum-nsum;
    }
};
