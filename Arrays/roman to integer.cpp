leetcode 16
better 
tc-o(n)
sc-o(8)=o(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp={
            {'I',1}, {'V',5} , {'X',10}, {'L',50},
            {'C',100}, {'D',500},{'M',1000}
        };
        int n=s.length();

        int ans=0;
        for(int i=0;i<n;i++){
            if(i+1<s.size() && mpp[s[i]]< mpp[s[i+1]]){
                ans-=mpp[s[i]];
            }
            else {
                ans+=mpp[s[i]];
            }
        }
        return ans;
    }
};

optimal 
tc-O(1) = as input is finite , we will take finite time to calculate 
sc-O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string,int> val;
         val["I"]=1;
         val["V"]=5;
         val["X"]=10;
         val["L"]=50;
         val["C"]=100;
         val["D"] = 500;
        val["M"] = 1000;

        // Subtraction cases
        val["IV"] = 4;
        val["IX"] = 9;
        val["XL"] = 40;
        val["XC"] = 90;
        val["CD"] = 400;
        val["CM"] = 900;


    int sum=0;
    int i=0;
    while(i<s.length()){
        if(i+1<s.length()){
            string twostr=s.substr(i,2);
            if(val.find(twostr)!=val.end()){
                sum+=val[twostr];
                i+=2;
                continue;
            }
        }
        
            string onestr=s.substr(i,1);
            sum+=val[onestr];
            i++;
        
    }
    return sum;
    }
};
