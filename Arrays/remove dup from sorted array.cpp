lc 26 
tc-O(n)
sc-o(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
            
        }
        return i+1;
    }
};

python :
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i,n=0, len(nums)
        for j in range(1,n):
            if nums[j]!=nums[i]:
                i+=1
                nums[i]=nums[j]

        return i+1


        
