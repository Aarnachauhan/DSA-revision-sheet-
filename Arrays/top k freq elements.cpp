
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
tc- O(nlogn + n) = o(nlogn) //nlogn for sorting and n for frequency count
sc-o(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int x : nums) freq[x]++;

    vector<pair<int,int>> vec;
    for(auto it : freq) {
        vec.push_back({it.second, it.first});
    }

    sort(vec.rbegin(), vec.rend());

    vector<int> ans;
    for(int i = 0; i < k; i++) {
        ans.push_back(vec[i].second);
    }

    return ans;
}


optimal - hashmap + priority queue( heap )
didnt understand 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &p : freq){
            pq.push({p.second, p.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

  
