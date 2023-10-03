class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101]={0};
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        
        int ans=0;
        for(int i=1;i<=100;i++){
            if(freq[i]==0)
                continue;
            freq[i]--;
            if(freq[i]%2 == 0)
                ans+=(freq[i]+1)*(freq[i]/2);
            else
                ans+=(freq[i])*((freq[i]+1)/2);
        }
        return ans;
    }
};


/*
1,1,1,1
3+2+1
3*4/2
*/