naukri.com
positives only

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int i=0;
    int j=0;
    int sum=0;
    int longest=0;
    while(j<n){
     sum+=a[j];
     
     while(sum>k){
         sum-=a[i];
         i++;
     }
     if(sum==k){
         longest=max(longest,j-i+1);
     }
     j++;
    }
    return longest;
}
