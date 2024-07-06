class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int>tmp;
        for(int i=0;i<n;i++){
            if(tmp.empty() || tmp[tmp.size()-1]<envelopes[i][1])
                tmp.push_back(envelopes[i][1]);
            else{
                auto it=lower_bound(tmp.begin(),tmp.end(),envelopes[i][1]);
                *it=envelopes[i][1];
            }
        }
        return tmp.size();
    }
};