leetcode 217

brute force - sorting 
tc-o(nlogn)
sc-o(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        
        return false;        
    }
};

bette approach 
set 
tc-o(n)
sc-o(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;

        for (int n : nums) {
            if (numSet.find(n) != numSet.end()) {
                return true;
            }
            numSet.insert(n);
        }
        
        return false;        
    }
};


optimal approach-
check length 
tc-o(n)
sc-o(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        return st.size()< nums.size(); 
        //agar size bada hua toh true it has duplicates
        //agar size chota hai ya same toh false - no duplicates.
    }
};
