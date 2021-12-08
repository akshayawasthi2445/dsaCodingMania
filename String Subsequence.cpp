class Solution{
public:
    int countWays(string S1, string S2){
        int m = S1.size();
        int n = S2.size();
        int dp[m+1][n+1] = {0};
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=0;i<=m;i++)
            dp[i][0]=1;
        for(int i=1;i<=S1.size();i++){
            for(int j=1;j<=S2.size();j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j]; 
                }
            }
        }
        return dp[m][n];
    }
};