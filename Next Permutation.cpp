class Solution {
public:
    void swap(int* a,int* b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    // 2 3 1 3 3
    
    
    void nextPermutation(vector<int>& nums) {
        if(nums.size()>1){
            int n = nums.size(); // 1 5 8 4 7 6 5 3 1
            int i = n-1;
            while(i>0 && nums[i-1]>=nums[i]){
                i--;
            }
            int startIndex;//i=2
            if(i==0)startIndex = 0;
            else{
                int temp = nums[i-1];//2
                startIndex = i-1;//1
                int minnum = INT_MAX;
                int index;
                // minnum is the number that we are targetting at.
                while(i<n){
                    if(nums[i]>temp && nums[i]<=minnum){
                        minnum = nums[i];
                        index = i;
                    }
                    i++;
                }
                swap(&nums[startIndex],&nums[index]);
                startIndex+=1;
            }
            
            
            int endIndex = n-1;
            while(startIndex<endIndex){
                swap(&nums[startIndex],&nums[endIndex]);
                startIndex++;endIndex--;
            }
        }
    }
};