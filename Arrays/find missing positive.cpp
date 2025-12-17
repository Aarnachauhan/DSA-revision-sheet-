leetcode 41
brute 
tc-o(n2)
sc-o(1)
take a number and find it in the array
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i <= n + 1; i++) {
            bool found = false;
            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    found = true;
                    break;
                }
            }
            if(!found) return i;
        }
        return n + 1;
    }
};

better: store in set and then see where it exist or not.
tc-o(n)
sc-o(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;

        for(int x:nums){
            if(x>0){
                st.insert(x);

            }
        }

        for(int i=1;i<=n+1;i++){
            if(st.find(i)==st.end()) return i;
        }
        return n+1;
    }
};


optimal
tc-O(n)
sc-o(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0  &&nums[i]<=n 
            && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};

