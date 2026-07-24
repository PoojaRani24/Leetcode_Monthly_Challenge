class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left=0;
        int n=arr.size();
        int sum=0;
        int ans=0;
        for(int right=0;right<n;right++){
            sum+=arr[right];
            if(right-left+1 > k){
                sum-=arr[left];
                left++;
            }
            // cout<<sum<<" "<<threshold*k<<endl;
            if(right-left+1 == k && sum >= threshold*k)
                ans++;
        }
        return ans;
    }
};