class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        int n=nums.size();
        int cnt=0;
        for(auto num:nums){
            if(lis.empty()|| num>lis[lis.size()-1]){
                lis.push_back(num);
                cnt++;
            }
            else{
                int index=lower_bound(lis.begin(),lis.end(),num)-lis.begin();
                lis[index]=num;
            }
        }
        return cnt;
    }
};