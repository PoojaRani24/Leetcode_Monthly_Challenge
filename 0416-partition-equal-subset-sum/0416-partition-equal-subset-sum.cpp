class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++)
            t+=nums[i];
        if(t%2!=0)
            return false;
        t=t/2;
        vector<bool>prev(t+1,false),curr(t+1,false);
        curr[0]=true;
        prev[0]=true;
        if(nums[0]<=t)
            prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=t;j++){
                bool pick=false, notPick=false;
                notPick=prev[j];
                if(j-nums[i]>=0)
                    pick=prev[j-nums[i]];
                curr[j]=pick||notPick;
            }
            prev=curr;
        }
        return prev[t];
    }
};