class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>b=arr;
        sort(b.begin(),b.end());
        unordered_map<int,int>um;
        
        int cnt=0;
        for(int i=0;i<b.size();i++){ 
            if(um.find(b[i])==um.end())
                um[b[i]] = ++cnt;
        }

        for(int i=0;i<arr.size();i++)
            arr[i]=um[arr[i]];

        return arr;
    }
};