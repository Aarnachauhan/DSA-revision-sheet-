leetcode 953
tc-o(n*m)
sc-o(1)

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mpp;
        for(int i=0;i<order.size();i++){
            mpp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];

            int len=min(w1.size(),w2.size());
            bool found=false;

            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    if(mpp[w1[j]]>mpp[w2[j]]) return false;

                    found=true;
                    break;
                }
            }

            if(!found && w1.size()>w2.size()) return false;
        }
        return true;
    }
};
