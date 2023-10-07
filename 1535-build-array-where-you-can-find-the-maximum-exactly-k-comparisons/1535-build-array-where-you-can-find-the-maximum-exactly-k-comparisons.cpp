class Solution {
public:
    int N, M, K;
    int MOoD = 1e9+7;
    int t[51][51][101];
    
    int solution(int idx, int searchCost, int maxSoFar) {
        if(idx == N) {
            if(searchCost == K)
                return 1;
            return 0;
        }
        
        if(t[idx][searchCost][maxSoFar] != -1) {
            return t[idx][searchCost][maxSoFar];
        }
        
        int ans = 0;
        
        for(int i = 1; i <= M; i++) {
            
            if(i > maxSoFar) {
                ans = (ans + solution(idx+1, searchCost+1, i)) % MOoD;
            } else {
                ans = (ans + solution(idx+1, searchCost, maxSoFar)) % MOoD;
            }
            
        }
        
        return t[idx][searchCost][maxSoFar] = ans % MOoD;
        
    }
    
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t, -1, sizeof(t));
        return solution(0, 0, 0);
    }
};