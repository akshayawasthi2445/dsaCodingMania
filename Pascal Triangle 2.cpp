class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)return {1};
        if(rowIndex==1)return {1,1};
        
        vector<int>temp={1,1};
        vector<int> base;
        base = temp;
        vector<int>prev;
        prev=base;
        for(int k=2;k<=rowIndex;k++){
            vector<int>current = base;
            int i=0,j=1;
            while(j<k){
                current.insert(current.begin()+j,prev[i]+prev[j]);
                i++;j++;
            }
            prev = current;
        }
        return prev;
    }
};