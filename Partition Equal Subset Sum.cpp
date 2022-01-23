class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)return false;
        sum/=2;
        int n = nums.size();
        int store[n+1][sum+1];
        for(int i=0;i<n+1;i++)
            store[i][0] = true;
        for(int i=1;i<sum+1;i++)
            store[0][i] = false;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]>j)store[i][j]=store[i-1][j];
                else{
                    store[i][j] = store[i-1][j] or store[i-1][j-nums[i-1]];
                }
            }
        }
        return store[n][sum];
    }
    

//     0// t f f f f
//     1// t t 
//     2// t
//     3// t
//     4// t
    
};