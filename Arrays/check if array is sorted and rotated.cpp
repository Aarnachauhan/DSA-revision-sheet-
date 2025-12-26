lc 1752
tc-o(N)
sc-o(1)
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // Check if the array is non-decreasing
        for (int i = 1; i < n; i++)
            if (nums[i - 1] > nums[i])
                count++;
        
        // Check if the last element is greater than the first element
        if (nums[n - 1] > nums[0])
            count++;
        
        // If the count of violations is less than or equal to 1, return true
        return count <= 1;
    }
};

in python
class Solution(object):
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        cnt,n=0, len(nums)
        for i in range(n):
            if nums[i]>nums[(i+1)%n]:
                cnt+=1
                if cnt>1 : return False;
        return True
        
