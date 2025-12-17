lc 121
brute
tc-o(n2)
sc-o(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,prices[j]-prices[i]);
            }
        }
        return maxi;
    }
};

optimal :
tc-o(n)
sc-o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       int buyprice=prices[0];
       int profit=0;

       for(int i=1;i<prices.size();i++){
        if(buyprice>prices[i]){
            buyprice=prices[i];
        }
        profit=max(profit,prices[i]-buyprice);
       }
       return profit;
    }
};
