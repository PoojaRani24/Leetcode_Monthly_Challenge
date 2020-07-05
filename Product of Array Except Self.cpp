class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
                vector<int>ans;
        if(n==0)
            return ans;
        int left[n];
        left[0]=1;
        int right[n];
        right[n-1]=1;
        for(int i=1;i<nums.size();i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
            ans.push_back(left[i]*right[i]);
        return ans;
    }
};
