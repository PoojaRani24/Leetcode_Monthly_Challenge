class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int>r(length,0);
        for(int i=0;i<updates.size();i++){
            r[updates[i][0]]+=updates[i][2];
            if(updates[i][1]+1<length)
                r[updates[i][1]+1]-=updates[i][2];
        }
        for(int i=1;i<length;i++)
            r[i]=r[i-1]+r[i];
        return r;
    }
};