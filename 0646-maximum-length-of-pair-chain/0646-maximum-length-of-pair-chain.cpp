class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto cmp=[&](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        };

        sort(pairs.begin(),pairs.end(),cmp);
        int end=pairs[0][1];
        int curLen=1, maxLen=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>end){
                cout<<pairs[i][0]<<" "<<end<<" "<<endl;
                curLen++;
                maxLen=max(maxLen,curLen);
                end=pairs[i][1];
            }
        }
        return maxLen;
    }
};