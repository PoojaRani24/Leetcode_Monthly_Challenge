class Solution {
public:
    int com(int a,int b,int c){
        int res=0;
        a=a%c;
        while(b){
            if(b%2!=0)
                res=(res+a)%c;
            a=(2*a)%c;
            b=b/2;
        }
        return res;
    }
    
    int numSub(string s) {
        int count=0;
        unsigned long long int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                count++;
            else{
                if(count==0)
                    continue;
                else{
                    if(count%2==0){
                        int a,b,m=1000000007;
                        a=count/2;
                        b=count+1;
                        sum+=com(a,b,m)%m;
                    }
                    else{
                        int a,b,m=1000000007;
                        a=(count+1)/2;
                        b=count;
                        sum+=com(a,b,m)%m;
                    }
                count=0;
                }
            }
        }
        sum+=(count*(count+1))/2;
        return (int)sum%1000000007;
    }
};
