class Solution {
public:
    bool divisorGame(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                if(i%j==0 && dp[i-j]==0){
                    dp[i]=1;
                    break;
                }
            }
        }
        if(dp[n]==0)return false;
        else return true;
    }
};