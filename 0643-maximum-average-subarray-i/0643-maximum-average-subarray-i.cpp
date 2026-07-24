class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int left = 0;
        double ans = 0.0;
        double fin = INT_MIN;
        for(int right=0;right<n;right++){
            ans+=nums[right];
            if(right-left+1 > k){
                ans-=nums[left];
                left++;
            }
            if(right-left+1 == k)
                fin=max(fin,ans/(double)k);
        }
        return fin;
    }
};