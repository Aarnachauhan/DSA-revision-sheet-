leetcode 


brute : time limit exceeded
tc-o(n2)
sc-o(1)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    if(abs(i-j)<=k) return true;
                }
            }
        }
        return false;
    }
};

opt approach 2 -
tc-o(n)
sc-o(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()){
                int j=mpp[nums[i]];
                if(abs(i-j)<=k) return true;
            }
            mpp[nums[i]]=i;
        }

        return false;
    }
};


opt approach 3-
tc-o(n)
sc-o(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                seen.erase(nums[i - k - 1]);
            }

            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }

            seen.insert(nums[i]);
        }

        return false;        
    }
};

dry run
5️⃣ Visual sliding window explanation

For k = 2

i	valid indices	element to erase
0	[0]	—
1	[0,1]	—
2	[0,1,2]	—
3	[1,2,3]	erase index 0
4	[2,3,4]	erase index 1
    

