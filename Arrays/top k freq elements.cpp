
brute force :
tc-o(n*k)
sc-o(1)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
      
       unordered_map<int, int> freq;
       for(auto it:nums){
        freq[it]++;
       }

       vector<int> ans;
       for(int i=0;i<k;i++){
        int maxi=0 , element=0;
        for(auto it:freq){
            if(it.second> maxi){
                maxi=it.second;
                element=it.first;

            }
        }
        ans.push_back(element);
        freq.erase(element); //remove it from frequency map .
       }
       return ans;
    }
};

better :
tc-o()
sc-o()

  
