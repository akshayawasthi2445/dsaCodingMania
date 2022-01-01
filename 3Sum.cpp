class Solution {
public:
    void swap(int *a,int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    void heapify(vector<int>& nums,int n,int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        if(l<n && nums[l]>nums[largest]){
            largest = l;
        }
        if(r<n && nums[r]>nums[largest]){
            largest = r;
        }
        if(largest!=i){
            swap(&nums[largest],&nums[i]);
            heapify(nums,n,largest);
        }
    }
    void heapSort(vector<int>& nums,int n){
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        
        for(int i=n-1;i>0;i--){
            swap(&nums[i],&nums[0]);// 6543217
            heapify(nums,i,0);
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if((nums.size()==1 && nums[0]==0) || nums.size()==0)return {};
        int n = nums.size();
        heapSort(nums,n);
        vector<vector<int>> store;
        // store.push_back(nums);
        // return store;
        
        // -4 -1 -1 0 1 2
        for(int i=0;i<n-2;i++){
            int x = i+1;
            int y = n-1;
            while(x<y){
                vector<int>temp;
                if(nums[i]+nums[x]+nums[y]<0)
                    x++;
                else if(nums[i]+nums[x]+nums[y]>0)
                    y--;
                else{
                    temp.emplace_back(nums[i]);
                    temp.emplace_back(nums[x]);
                    temp.emplace_back(nums[y]);
                    auto it = find(store.begin(),store.end(),temp);
                    if(it==store.end()){
                        store.emplace_back(temp);
                    }
                    x++;y--;
                }
            }
        }
        return store;
    }
};