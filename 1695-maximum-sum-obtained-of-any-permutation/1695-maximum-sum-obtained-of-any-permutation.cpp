typedef long long ll;
class Solution {
public:
// 0 1 2 3 4 5
// 1 1.-1 -1
// 1 2 1 0 0 0
// 0 0 0 1 1 2
    ll M=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();int m=requests.size();
        long long ans=0;
        vector<int>cnt(n+1,0);
        for(auto it: requests){
            cnt[it[0]]++;cnt[it[1]+1]--;
        }
        for(int i=1;i<=n;i++)
            cnt[i]+=cnt[i-1];
        sort(cnt.begin(),cnt.end());
        sort(nums.begin(),nums.end());
        for(int i=n;i>0 && cnt[i]!=0;i--)
            ans+=(ll)nums[i-1]*(ll)cnt[i];
            ans%=M;
        return ans;
    }
};