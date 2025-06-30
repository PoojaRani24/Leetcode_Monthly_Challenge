class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>freqCnt;
        for(int i=0;i<nums.size();i++)
            freqCnt[nums[i]]++;
        auto prev=freqCnt.begin();
        int ans=0;
        for(auto it=next(freqCnt.begin());it!=freqCnt.end();it++){
            if(it->first - prev->first == 1)
                ans=max(ans, it->second+prev->second);
            prev=it;
        }
        return ans;
    }
};