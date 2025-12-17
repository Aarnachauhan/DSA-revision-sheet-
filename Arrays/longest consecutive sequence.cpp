leetcode 128
brute - this gives tle - too slow for large inputs
✅ Approach 1: Brute Force (Check Every Number)
💡 Idea

For every element, keep checking if the next number exists

Count how long the consecutive chain continues
tc-o(n2) sc-o(1)

  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) continue;
            else if(nums[i] == nums[i-1] + 1) {
                cnt++;
            } else {
                longest = max(longest, cnt);
                cnt = 1;
            }
        }

        return max(longest, cnt);
    }
};



better -
sort the array and count 
tc-o(nlogn)
sc-o(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());

        int longest=1;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue ; //this is duplicate
            else if(nums[i]==nums[i-1]+1){
                cnt++;
                
            }
            else {
                longest=max(longest,cnt); 
                cnt=1;
            }
        }
        return max(longest,cnt);
    }
};

optimal 
if num-1 doesnt exist then it is the starting number. and then we will find num+1
tc-o(n)
sc0o(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st(nums.begin(),nums.end());

       int longest=0;

       for(int num:st){
        if(st.find(num-1)==st.end()){
            int curr=num;
            int cnt=1;

            while(st.find(curr+1)!=st.end()){
                curr++;
                cnt++;
            }
            longest=max(longest,cnt);
        }
       }
       return longest;
    }
};
