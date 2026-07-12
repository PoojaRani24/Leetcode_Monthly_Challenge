class Solution {
public:
    long HoursToFinish(vector<int>&piles, int mid){
        long hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=piles[i]/mid;
            if(piles[i]%mid)
                hours++;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = INT_MIN;
        for(int i=0;i<n;i++)
            high = max(high, piles[i]);
        while(low<=high){
            int mid = low+(high-low)/2;
            long hoursrequired =  HoursToFinish(piles, mid);
            if(hoursrequired <= h)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};