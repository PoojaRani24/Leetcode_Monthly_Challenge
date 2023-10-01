class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int res=low;
        //------------logic--------------------------------
        while(low<=high){
            int mid = (low+high)/2;
            int n = no_of_subarrays_with_max_sum_as_mid(nums,mid);
            if(n > k)
                low = mid+1;
            else{
                res = mid;
                high = mid-1;
            }
        }
        //-------------------------------------------------
        return res;
    }

    int no_of_subarrays_with_max_sum_as_mid(vector<int>& nums, int mid){
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i] > mid){
                cnt++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return cnt;
    }

};