class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int running_sum=0;
        int curr_cnt=0,shortest_cnt=INT_MAX;
        while(j<n){
            if(running_sum<target){
                curr_cnt++;
                running_sum+=nums[j];
            }
            while(running_sum>=target){
                shortest_cnt=min(shortest_cnt, curr_cnt);
                curr_cnt--;
                running_sum-=nums[i];
                i++;
            }
            j++;
        }

        while(i<n){
            if(running_sum>=target){
                shortest_cnt=min(shortest_cnt, curr_cnt);
            }
            curr_cnt--;
            running_sum-=nums[i];
            i++;
        }
        return shortest_cnt==INT_MAX?0:shortest_cnt;
    }
};