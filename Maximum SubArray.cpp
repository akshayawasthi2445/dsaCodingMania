class Solution {
public:
    int max(int a,int b){
        if(a>b)return a;
        else return b;
    }
    int maxSubArray(vector<int>& nums) {
        int best=nums[0];
        int current=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]+current>nums[i])
            {
                current+=nums[i];
            }
            else
            {
                current=nums[i];
            }
            best = max(best,current);
        }
        return best;
    }
};