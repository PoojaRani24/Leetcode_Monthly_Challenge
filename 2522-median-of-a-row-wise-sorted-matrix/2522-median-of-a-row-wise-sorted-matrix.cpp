class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int l=1,h=1000000;
        int index=(n*m)/2;
        while(l<h){
            int mid=l+(h-l)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=bs(grid[i],mid);
            }
            if(cnt<=index)
                l=mid+1;
            else
                h=mid;
        }
        return l;
    }

    int bs(vector<int>&a, int v){
        return upper_bound(a.begin(),a.end(),v)-a.begin();
    }
};