class Solution {
public:
    int totalTrees(int n,int dp[]){
        int treecount = 0;
        for(int i=0;i<n;i++){
            int left = dp[i];
            int right = dp[n-i-1];
            treecount+=left*right;
        }
        return treecount;
    }
    int numTrees(int n) {
        if(n==0)return 1;
        if(n==1)return 1;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            int store = totalTrees(i,dp);
            dp[i] = store;
        }
        return dp[n];
    }
};