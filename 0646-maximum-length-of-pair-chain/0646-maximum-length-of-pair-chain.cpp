class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        int pairCnt=0, pickedPair=0;
        for(int i=0;i<n;i++){
            if(pairCnt==0 || pairs[i][0]>pickedPair){
                pairCnt++;
                pickedPair=pairs[i][1];
            }
        }
        return pairCnt;
    }
};