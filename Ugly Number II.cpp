class Solution {
public:
    int nthUglyNumber(int n) {
        int list[n];
        list[0]=1;
        int index_2=0;
        int index_3=0;
        int index_5=0;
        int num2=2*list[index_2];
        int num3=3*list[index_3];
        int num5=5*list[index_5];
                    cout<<list[0]<<" ";
        for(int i=1;i<n;i++){
            list[i]=min(num2,min(num3,num5));
                        cout<<list[i]<<" ";
            if(list[i]==num2){
                index_2++;
                num2=2*list[index_2];
            }
            if(list[i]==num3){
                index_3++;
                num3=3*list[index_3];
            }
            if(list[i]==num5){
                index_5++;
                num5=5*list[index_5];
            }
        }
        return list[n-1];
    }
};
