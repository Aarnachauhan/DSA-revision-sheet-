approach 1
two for loops - o(N2)

approach 2- better
  sorting + binary search 
required=target-nums[i]
then apply binary search for required. 

  worst case - n times search 
so searching -o(nlogn)
sorting takes o(nlogn)

tc= o(nlogn) + o(nlogn)= o(nlogn)


approach 3 - optimal 
tc-o(N) sc-o(n) as we are using hashmap 
hashmap has key and value pair .
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            int req=target-num;
            if(mpp.find(req)!=mpp.end()){ //this means required exists in the map.
                return {i,mpp[req]}; //required i and value of required.
            }
            mpp[num]=i; //if doesnt exist then store and move on 
        }
        return {-1,-1};
    }
};


note:
5️⃣ How to explicitly access keys and values (important theory)

If you want to iterate over a map:

for (auto it : mpp) {
    cout << "Key = " << it.first << ", Value = " << it.second << endl;
}


Here:

it.first → key

it.second → value

Hash maps give O(1) access by key

Searching by value would be O(n)
