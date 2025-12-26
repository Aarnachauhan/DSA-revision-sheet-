gfg
https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

note:
⚠️ Very Important Interview Rule
Case	Approach
Only positive numbers ->	Sliding Window
Positive + Negative ->	Prefix Sum + HashMap
Need subarray count ->	Prefix sum frequency
Longest subarray	-> store FIRST occurrence


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        long long sum=0;
        int longest=0;
        unordered_map<long long,int> mpp;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==k){
                longest=i+1;
            }
            
            if(mpp.find(sum-k)!=mpp.end()){
                longest=max(longest,i-mpp[sum-k]);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return longest;
        
    }
};

