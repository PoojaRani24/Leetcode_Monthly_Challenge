class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++)
            m[s[i]]=i;

        vector<int>ans;
        int beg=0,start=0,end=-1;
        while(start<n){
            end=max(end,m[s[start]]);
            if(start==end){
                ans.push_back(end-beg+1);
                beg=end+1;
            }
            start=start+1;
        }
        return ans;
    }
};