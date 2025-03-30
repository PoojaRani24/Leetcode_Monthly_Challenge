class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>partitions;
        int n=s.size();

        unordered_map<char,int>lastInd;
        for(int i=0;i<n;i++)
            lastInd[s[i]]=i;
        
        int start=0,end=-1;
        for(int i=0;i<n;i++){
            end=max(end,lastInd[s[i]]);
            if(i==end){
                partitions.push_back(end-start+1);  
                start=end+1;
            }
        }

        return partitions;
    }
};