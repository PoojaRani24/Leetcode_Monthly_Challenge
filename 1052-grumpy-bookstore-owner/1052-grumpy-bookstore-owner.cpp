class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left=0;
        int n=customers.size();
        int ans=0, fin=INT_MIN;
        int fl,fr;
        for(int right=0;right<n;right++){
            if(grumpy[right]==1)
                ans+=customers[right];
            if(right-left+1 > minutes){
                if(grumpy[left]==1)
                    ans-=customers[left];
                left++;
            }
            if(right-left+1 == minutes){
                if(ans>fin){
                    fin=ans;
                    fl=left;
                    fr=right;
                }
            }
        }

        int sum=0;
        for(int i=0;i<n;i++){
            if((i>=fl and i<=fr) || (grumpy[i]==0))
                sum+=customers[i];  
        }
        return sum;
    }
};