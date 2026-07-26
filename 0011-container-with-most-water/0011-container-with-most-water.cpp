class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0, right=n-1;
        int amt=0;
        int ans=INT_MIN;
        while(left<right){
            amt=(right-left)*(min(height[left],height[right]));
            ans=max(ans,amt);
            if(height[right]<height[left])
                right--;
            else
                left++;
        }
        return ans;
    }
};